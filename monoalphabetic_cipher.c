#include<stdio.h>
#include<ctype.h>
#include<string.h>
char encrypt(char ch, char *key) 
{
    if (isalpha(ch)) 
    {
        int index = toupper(ch) - 'A';
        return key[index];
    }
    return ch; // Non-alphabetic characters remain unchanged
}

char decrypt(char ch, char *key) 
{
    int i;
    for (i = 0; i < 26; i++) 
    {
        if (key[i] == ch) 
        {
            return 'A' + i;
        }
    }
    return ch; // Non-alphabetic characters remain unchanged
}

int main() 
{
    char plaintext[] = "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG";
    char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";

// Encryption
    char ciphertext[strlen(plaintext) + 1];
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) 
    {
        ciphertext[i] = encrypt(plaintext[i], key);
    }
    ciphertext[i] = '\0'; // Null terminate the ciphertext string
    printf("Plaintext: %s\n", plaintext);
    printf("Key: %s\n", key);
    printf("Ciphertext: %s\n", ciphertext);

// Decryption
    char decrypted_text[strlen(ciphertext) + 1];
    for (i = 0; ciphertext[i] != '\0'; i++) 
    {
    decrypted_text[i] = decrypt(ciphertext[i], key);
    }
    decrypted_text[i] = '\0'; // Null terminate the decrypted text string
    printf("Decrypted Text: %s\n", decrypted_text);
    return 0;
}
