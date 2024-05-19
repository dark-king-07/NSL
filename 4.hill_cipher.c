  #include<stdio.h>
    #include<string.h>
    int main() 
    {
        unsigned int a[5][5] = { { 6, 24, 1,5,1 }, { 13, 16, 10 ,4,1}, { 20, 17, 15,5,13 } , { 8, 5,12,13, 10 }, { 23,1,21, 8, 21 }};
        unsigned int b[5][5] = { { 8, 5, 10,3,1}, { 21, 8, 21,11,4}, {7,14,21,12,8}, {3,14,2,11,28},{ 18, 5, 10,13,11}};
        int i, j;
        unsigned int c[20], d[20];
        char msg[20];
        int determinant = 0, t = 0;
        printf("Enter plain text\n ");
        scanf("%s", msg);
        for (i = 0; i < 5; i++) 
        {
            c[i] = msg[i] - 65;
            printf("%d ", c[i]);
        }
        for (i = 0; i < 5; i++) 
        {
            t = 0;
            for (j = 0; j < 5; j++) 
            {
                t = t + (a[i][j] * c[j]);
            }
            d[i] = t % 26;
        }
        printf("\nEncrypted Cipher Text :");
        for (i = 0; i < 5; i++)
            printf(" %c", d[i] + 65);
        for (i = 0; i < 5; i++)
        {
            t = 0;
            for (j = 0; j < 5; j++) 
            {
                t = t + (b[i][j] * d[j]);
            }
            c[i] = t % 26;
        }
        printf("\nDecrypted Cipher Text :");
        for (i = 0; i < 5; i++)
            printf(" %c", c[i] + 65);
        return 0;
    }
