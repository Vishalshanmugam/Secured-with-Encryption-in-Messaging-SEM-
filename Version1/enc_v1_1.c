#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void xor_encrypt_decrypt(char *output, const char *input, const char *key, int length) 
{
    int key_len = strlen(key);
    for (int i = 0; i < length; i++) 
    {
        output[i] = input[i] ^ key[i % key_len];
    }
}

int main() {
    char input[BUFFER_SIZE];
    char output[BUFFER_SIZE];
    char key[BUFFER_SIZE];
    int choice;
    int length;

    printf("==== Secure Terminal Message Encryption ====\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("Select option (1 or 2): ");
    scanf("%d", &choice);
    getchar(); // consume newline

    printf("Enter the message: ");
    fgets(input, BUFFER_SIZE, stdin);
    length = strcspn(input, "\n");
    input[length] = '\0'; // remove newline

    printf("Enter the secret key: ");
    fgets(key, BUFFER_SIZE, stdin);
    key[strcspn(key, "\n")] = '\0'; // remove newline

    if (choice == 1) 
    {
        xor_encrypt_decrypt(output, input, key, length);
        printf("Encrypted message (hex): ");
        for (int i = 0; i < length; i++) 
        {
            printf("%02X ", (unsigned char)output[i]);
        }
        printf("\n");
    } 
    else if (choice == 2) 
    {
        xor_encrypt_decrypt(output, input, key, length);
        output[length] = '\0'; // null-terminate after decrypt
        printf("Decrypted message: %s\n", output);
    } else 
    {
        printf("Invalid choice!\n");
    }

    return 0;
}
