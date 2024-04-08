#include <stdio.h>
#include <ctype.h> // For isalpha() and islower()

// Function to perform Caesar Cipher encryption
char caesar_encrypt(char ch, int key) 
{
    if (isalpha(ch)) 
    {
        char base = islower(ch) ? 'a' : 'A';
        return (ch - base + key) % 26 + base;
    }
    return ch; // Non-alphabetic characters remain unchanged
}

// Function to perform Caesar Cipher decryption
char caesar_decrypt(char ch, int key) 
{
    if (isalpha(ch)) 
    {
        char base = islower(ch) ? 'a' : 'A';
        return (ch - base - key + 26) % 26 + base;
    }
    return ch; // Non-alphabetic characters remain unchanged
}

int main() 
{
    char message[] = "Hello HoW aRe YoU";
    int key = 3; // Example key (you can choose any positive integer)
    // Encrypt the message
    for (int i = 0; message[i]; i++) 
    {
        message[i] = caesar_encrypt(message[i], key);
    }
    printf("Encrypted message: %s\n", message);
  
    // Decrypt the ciphertext
    for (int i = 0; message[i]; i++) 
    {
        message[i] = caesar_decrypt(message[i], key);
    }
    printf("Decrypted message: %s\n", message);
    return 0;
}

