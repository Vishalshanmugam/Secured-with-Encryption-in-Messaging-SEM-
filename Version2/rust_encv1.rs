use tokio::net::TcpStream;
use tokio::io::{AsyncReadExt, AsyncWriteExt};
use aes_gcm::{Aes256Gcm, KeyInit, aead::{Aead, AeadCore, OsRng}};
use base64::engine::general_purpose;
use base64::Engine as _;

async fn handle_connection(mut stream: TcpStream, aes: Aes256Gcm) {
    let nonce = Aes256Gcm::generate_nonce(&mut OsRng);
    let aes_for_writing = aes.clone();
    
    // Split the stream without Arc
    let (mut reader, mut writer) = stream.split();

    // Spawn writer task
    tokio::spawn(async move {
        loop {
            let mut message = String::new();
            std::io::stdin().read_line(&mut message).unwrap();
            
            match aes_for_writing.encrypt(&nonce, message.as_bytes()) {
                Ok(ciphertext) => {
                    let encoded = general_purpose::STANDARD.encode(&ciphertext);
                    if let Err(e) = writer.write_all(encoded.as_bytes()).await {
                        eprintln!("Write error: {}", e);
                        break;
                    }
                }
                Err(e) => eprintln!("Encryption error: {}", e),
            }
        }
    });

    // Reader task
    let mut buffer = vec![0; 1024];
    loop {
        match reader.read(&mut buffer).await {
            Ok(0) => break,
            Ok(n) => {
                let received = &buffer[..n];
                let decoded = general_purpose::STANDARD.decode(received).unwrap_or_default();
                
                match aes.decrypt(&nonce, decoded.as_ref()) {
                    Ok(plaintext) => println!("Received: {}", String::from_utf8_lossy(&plaintext)),
                    Err(e) => eprintln!("Decryption error: {}", e),
                }
            }
            Err(e) => {
                eprintln!("Read error: {}", e);
                break;
            }
        }
    }
}

#[tokio::main]
async fn main() {
    // Initialize AES (replace with your actual key)
    let key = aes_gcm::Key::<Aes256Gcm>::from_slice(b"very_secret_key_32_bytes_long!");
    let cipher = Aes256Gcm::new(key);
    
    // Connect to server (replace with your actual connection logic)
    let stream = TcpStream::connect("127.0.0.1:8080").await.unwrap();
    
    handle_connection(stream, cipher).await;
}
