#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void xor_encrypt_decrypt(char *message, const char *key, int length) {
    int key_len = strlen(key);
    for (int i = 0; i < length; i++) {
        message[i] ^= key[i % key_len];
    }
}

int main() {
    char buffer[BUFFER_SIZE];
    char key[BUFFER_SIZE];
    int choice;
    int msg_len;

    printf("==== Secure Terminal Message Encryption ====\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("Select option (1 or 2): ");
    scanf("%d", &choice);
    getchar(); // clear newline

    printf("Enter the message: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    msg_len = strcspn(buffer, "\n"); // get length before newline
    buffer[msg_len] = '\0'; // ensure null termination

    printf("Enter the secret key: ");
    fgets(key, BUFFER_SIZE, stdin);
    key[strcspn(key, "\n")] = 0; // remove newline

    if (choice == 1) {
        xor_encrypt_decrypt(buffer, key, msg_len);
        printf("Encrypted message (hex): ");
        for (int i = 0; i < msg_len; i++) {
            printf("%02X ", (unsigned char)buffer[i]);
        }
        printf("\n");
    } else if (choice == 2) {
        // Assume input was entered as hex values
        printf("Enter the number of bytes to decrypt: ");
        scanf("%d", &msg_len);
        getchar(); // clear newline

        printf("Enter hex bytes separated by spaces: ");
        for (int i = 0; i < msg_len; i++) {
            unsigned int byte;
            scanf("%x", &byte);
            buffer[i] = (char)byte;
        }
        buffer[msg_len] = '\0'; // null terminate

        xor_encrypt_decrypt(buffer, key, msg_len);
        printf("Decrypted message: %s\n", buffer);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
