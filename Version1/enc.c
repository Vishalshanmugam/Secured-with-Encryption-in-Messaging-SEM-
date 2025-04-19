#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LEN 1024
#define MAX_KEY_LEN 256

// Function to XOR encrypt/decrypt the message
void xor_crypt(char *input, char *key, char *output) {
    int input_len = strlen(input);
    int key_len = strlen(key);

    for (int i = 0; i < input_len; ++i) {
        output[i] = input[i] ^ key[i % key_len]; // simple XOR
    }
    output[input_len] = '\0'; // Null-terminate the result
}

// Secure input reading
void read_input(const char *prompt, char *buffer, int max_len) {
    printf("%s", prompt);
    if (fgets(buffer, max_len, stdin) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
            buffer[len - 1] = '\0'; // Remove newline
    }
}

int main() {
    char message[MAX_MSG_LEN];
    char key[MAX_KEY_LEN];
    char output[MAX_MSG_LEN];
    int choice;

    printf("==== Secure Terminal Message Encryption ====\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("Select option (1 or 2): ");
    scanf("%d", &choice);
    getchar(); // Consume leftover newline

    if (choice != 1 && choice != 2) {
        printf("Invalid option.\n");
        return 1;
    }

    read_input("Enter the message: ", message, MAX_MSG_LEN);
    read_input("Enter the secret key: ", key, MAX_KEY_LEN);

    xor_crypt(message, key, output);

    if (choice == 1) {
        printf("\nEncrypted message (may contain unreadable characters):\n");
        for (int i = 0; i < strlen(message); ++i)
            printf("%02X ", (unsigned char)output[i]);
        printf("\n");
    } else {
        printf("\nDecrypted message:\n%s\n", output);
    }

    return 0;
}
