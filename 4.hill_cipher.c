#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define MAX_SIZE 10

void hillCipherEncrypt(int key[MAX_SIZE][MAX_SIZE], int keySize, char *message) 
{
    int i, j, k, len, sum;
    len = strlen(message);
    int encrypted[len];
    
    while (len % keySize != 0) 
    {
        message[len] = 'X';
        len++;
    }
    message[len] = '\0';
    
    for (i = 0; i < len; i += keySize) 
    {
        for (j = 0; j < keySize; j++) 
        {
            sum = 0;
            for (k = 0; k < keySize; k++) 
            {
                sum += key[k][j] * (message[i + k] - 'A');
            }
            encrypted[i + j] = sum % 26;
        }
    }
    
    printf("Encrypted Message: ");
    for (i = 0; i < len; i++) 
    {
        printf("%c", encrypted[i] + 'A');
    }
    printf("\n");
}

int main() 
{
    int key[MAX_SIZE][MAX_SIZE];
    int keySize, i, j;
    char message[1000];
    
    printf("Enter key size (square matrix size): ");
    scanf("%d", &keySize);
    
    printf("Enter key matrix elements:\n");
    for (i = 0; i < keySize; i++) 
    {
        for (j = 0; j < keySize; j++) 
        {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &key[i][j]);
        }
    }
    
    printf("The Key Matrix is:\n");
    for (i = 0; i < keySize; i++) 
    {
        for (j = 0; j < keySize; j++) 
        {
            printf("%d\t",key[i][j]);
        }
        printf("\n");
    }
    
    printf("Enter the message to be encrypted (in capital letters): ");
    scanf("%s", message);
    
    hillCipherEncrypt(key, keySize, message);
    
    return 0;
}
