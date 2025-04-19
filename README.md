# 🔐 Encrypted Messaging System in C

A simple terminal-based encrypted messaging system built in C using symmetric key cryptography. This project explores low-level message encryption through character-level operations and XOR-based transformations, without relying on external libraries.

## 🚀 Features

- Symmetric key encryption and decryption using XOR logic
- Manual buffer control for memory safety
- Lightweight, fast, and terminal-friendly interface
- Modular design for secure input handling and encryption logic
- Educational implementation to understand the foundation of secure communication

## 📦 How It Works

1. The user provides a message and a secret key.
2. The program encrypts the message by XOR-ing each character with the key (cycled if shorter).
3. The encrypted message can be decrypted using the same key via the same logic.

> Note: This implementation is for educational purposes only and **not suitable for production-level encryption**.

## 🛠️ Requirements

- C compiler (e.g. `gcc`, `clang`)
- Linux/macOS/Windows terminal

## 📥 Build & Run

```bash
gcc encrypted_messaging.c -o securechat
./securechat
