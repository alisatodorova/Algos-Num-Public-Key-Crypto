/*
Implements the Fibonacci sequence using the big integer addition algorithm, for positive integers.
*/

#include <stdlib.h>
#include <stdio.h>

// Big Integer
typedef struct
{
    int size;
    int *tab;
} bignum;

//  Performs big integer addition where
// a big integer is represented as an array of digits in base B, with a sign bit
bignum bigIntAdd(bignum a, bignum b, int B)
{
    bignum c;
    int max_size = (a.size > b.size) ? a.size : b.size;
    c.tab = (int *)malloc((max_size + 1) * sizeof(int)); // Allocates memory for the result array

    int l = b.size;
    int k = a.size;
    int carry = 0;

    for (int i = 0; i <= l - 1; i++)
    {
        int temp = a.tab[i] + b.tab[i] + carry;
        carry = temp / B;
        c.tab[i] = temp % B;
    }

    for (int i = l; i <= k - 1; i++)
    {
        int temp = a.tab[i] + carry;
        carry = temp / B;
        c.tab[i] = temp % B;
    }

    // If carry remains after the last addition
    if (carry > 0)
    {
        c.tab[k] = carry;
        c.size = k + 1;
    }
    else
    {
        c.size = k;
    }

    return c;
}

// Performs the Fibonacci sequence
bignum fibonacci(int n){
    bignum u0 = {1, (int[]){1}}; // u_0=1
    bignum u1 = {1, (int[]){1}}; // u_1=1
    if (n==0){
        return u0;
    }
    if (n==1){
        return u1;
    }

    // u_n = u_{n−1}+u_{n−2} for n ≥ 2
    bignum un;
    for (int i = 2; i <= n; i++){
        un = bigIntAdd(u1, u0, 10); //base B=10
        u0 = u1;
        u1 = un;
    }
    return un;
}

// Test
int main()
{
    int n = 101; //number of Fibonacci terms

    bignum result = fibonacci(n);

    printf("Fibonacci sequence up to term %d: ", n);
    for (int i = result.size - 1; i >= 0; i--)
    {
        printf("%d", result.tab[i]);
    }
    printf("\n");

    // Free allocated memory
    free(result.tab);

    return 0;
}
