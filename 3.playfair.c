#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

void prepareKey(char *key, char *preparedKey) {
    int i, j, k = 0;
    char *ptr = preparedKey;
    int keyLength = strlen(key);
    int flag = 0;
    // Copy the key to preparedKey and remove duplicate letters
    for (i = 0; i < keyLength; i++) {
        if (key[i] == 'j') key[i] = 'i'; // Replace 'j' with 'i'
        if (key[i] == ' ') continue; // Skip spaces
        for (j = 0; j < i; j++) {
            if (key[i] == key[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            *ptr = key[i];
            ptr++;
        }
        flag = 0;
    }
    // Fill the remaining letters of the alphabet
    for (i = 0; i < 26; i++) {
        if ('a' + i == 'j') continue; // Skip 'j'
        if (!strchr(preparedKey, 'a' + i)) {
            *ptr = 'a' + i;
            ptr++;
        }
    }
    *ptr = '\0';
}

void generateTable(char *preparedKey, char playfair[SIZE][SIZE]) {
    char *ptr = preparedKey;
    int i, j;
    // Fill the Playfair table with the letters from the prepared key
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            playfair[i][j] = *ptr++;
        }
    }
}

void findPositions(char playfair[SIZE][SIZE], char a, char b, int *rowA, int *colA, int *rowB, int *colB) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (playfair[i][j] == a) {
                *rowA = i;
                *colA = j;
            }
            if (playfair[i][j] == b) {
                *rowB = i;
                *colB = j;
            }
        }
    }
}

void encryptPair(char playfair[SIZE][SIZE], char a, char b) {
    int rowA, colA, rowB, colB;
    findPositions(playfair, a, b, &rowA, &colA, &rowB, &colB);
    // Same row
    if (rowA == rowB) {
        printf("%c%c", playfair[rowA][(colA + 1) % SIZE], playfair[rowB][(colB + 1) % SIZE]);
    }
    // Same column
    else if (colA == colB) {
        printf("%c%c", playfair[(rowA + 1) % SIZE][colA], playfair[(rowB + 1) % SIZE][colB]);
    }
    // Rectangle
    else {
        printf("%c%c", playfair[rowA][colB], playfair[rowB][colA]);
    }
}

void encrypt(char *message, char playfair[SIZE][SIZE]) {
    int i;
    // Replace 'j' with 'i' and remove non-alphabetic characters
    for (i = 0; message[i] != '\0'; i++) {
        if (message[i] == 'j') message[i] = 'i';
        if (!isalpha(message[i])) {
            for (int j = i; message[j] != '\0'; j++) {
                message[j] = message[j + 1];
            }
        }
    }
    // Add a filler character if the message length is odd
    if (strlen(message) % 2 != 0) {
        strcat(message, "x");
    }
    // Encrypt pairs of letters
    for (i = 0; message[i] != '\0'; i += 2) {
        encryptPair(playfair, message[i], message[i + 1]);
    }
    printf("\n");
}

int main() {
    char key[100], preparedKey[26], playfair[SIZE][SIZE];
    char message[1000];
    
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0; // Remove newline character
    
    printf("Enter the message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0; // Remove newline character
    
    prepareKey(key, preparedKey);
    generateTable(preparedKey, playfair);
    
    printf("Encrypted message: ");
    encrypt(message, playfair);
    
    return 0;
}
