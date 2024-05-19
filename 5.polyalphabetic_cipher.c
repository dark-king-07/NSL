#include <ctype.h>
#include <stdio.h>
#include <string.h>

void encrypt(char *text, char *key)
 {
    for (int i = 0, j = 0; text[i] != '\0'; ++i) 
    {
        char c = text[i];
        if (isalpha(c)) {
            char offset = isupper(c) ? 'A' : 'a';
            text[i] = ((c - offset + (toupper(key[j]) - 'A')) % 26) + offset;
            j = (j + 1) % strlen(key);
        }
    }
}

void decrypt(char *text, char *key) 
{
    for (int i = 0, j = 0; text[i] != '\0'; ++i) 
    {
        char c = text[i];
        if (isalpha(c)) 
        {
            char offset = isupper(c) ? 'A' : 'a';
            text[i] = ((c - offset - (toupper(key[j]) - 'A') + 26) % 26) + offset;
            j = (j + 1) % strlen(key);
        }
    }
}

int main() 
{
    char key[] = "deceptive";
    char text[] = "wearediscoveredsaveyourself";
    printf("Original text: %s\n", text);
    encrypt(text, key);
    printf("Encrypted text: %s\n", text);
    decrypt(text, key);
    printf("Decrypted text: %s\n", text);
    return 0;
}
