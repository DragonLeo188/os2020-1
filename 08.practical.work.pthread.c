#include <stdio.h>
#include <pthread.h>

int isPrime(int n, int i) 
{
    if (i == 1) 
    {
        return 1;
    }
    else
    {
        if (n % i == 0) 
        {
            return 0;
        }
        else
        {
            return isPrime(n, i - 1);
        }
    }
}
void *primeNum() 
{
    int n = 2;
    printf("Print all prime numbers from 2 to 1.000.000: \n");
    while (n <= 1000000) 
    {
        int check = n/2;
        if (isPrime(n, check) == 1) 
        {
            printf ("%d ",n);
        } 
        n++;
    }
    printf("\n");
}

void *seqFibon() {
    int a = 1, b = 1, c = 0;
    printf("Print all numbers in Fibonacci sequence from 2 to 1 000 000: \n");
    while (c <= 1000000) {
        c = a + b;
        a = b;
        b = c;
        printf ("%d ",c);
    };
    printf("\n");
    
}

int main() 
{
    pthread_t prime, fibon;
    pthread_create(&prime, NULL, primeNum, NULL);
    pthread_create(&fibon, NULL, seqFibon, NULL);
    pthread_join(prime, NULL);
    pthread_join(fibon, NULL);
    return 0;
}