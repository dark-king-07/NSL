#include<stdio.h>
#include<math.h>
long long int power(long long int a, long long int b, long long int P) //calculate the power
{
    long long int result = 1;
    a = a % P;
    while (b > 0) 
    {
        if (b % 2 == 1) 
        {
            result = (result * a) % P;
        }
        b = b >> 1;
        a = (a * a) % P;
    }
    return result;
}

int main() 
{
    long long int P, G, a, b;

    printf("Enter the value of P (a prime number): ");
    if(scanf("%lld", &P) != 1 || P <= 0) // check if value of P is valid 
    {
        printf("Invalid input for P.\n");
        return 1;
    }
    printf("Enter the value of G (a primitive root modulo P): "); // check if value of  is valid
    if(scanf("%lld", &G) != 1 || G <= 0 || G >= P) 
    {
        printf("Invalid input for G.\n");
        return 1;
    }
    printf("Enter the private key a: ");
    if(scanf("%lld", &a) != 1 || a <= 0 || a >= P) 
    {
        printf("Invalid input for a.\n");
        return 1;
    }
    printf("Enter the private key b: ");
    if(scanf("%lld", &b) != 1 || b <= 0 || b >= P) 
    {
        printf("Invalid input for b.\n");
        return 1;
    }
    long long int x = power(G, a, P);
    printf("The public key for a: %lld\n", x);
    long long int y = power(G, b, P);
    printf("The public key for b: %lld\n", y);

    long long int ka = power(y, a, P);
    long long int kb = power(x, b, P);

    printf("Secret key for a: %lld\n", ka);
    printf("Secret key for b: %lld\n", kb);
    return 0;
}