/*
Implements the n! using the multiplication algorithm on big integers, for positive integers.
*/

#include <stdlib.h>
#include <stdio.h>

// Big Integer
typedef struct
{
    int size;
    long long int *tab;
} bignum;

//  Performs big integer multiplication where
// a big integer is represented as an array of digits in base B, with a sign bit
bignum bigIntMult(bignum a, bignum b, int B)
{
    int l = b.size;
    int k = a.size;
    long long int carry = 0;

    bignum c;
    int max_size = k + l;
    c.tab = (long long int *)malloc((max_size + 1) * sizeof(long long int)); // Allocates memory for the result array
    c.size = max_size;

    for (int i = 0; i <= max_size; i++)
    {
        c.tab[i] = 0;
    }

    for (int i = 0; i < k; i++)
    {
        carry = 0;

        for (int j = 0; j < l; j++)
        {
           long long int temp = a.tab[i] * b.tab[j] + c.tab[i + j] + carry;
            carry = temp / B;
            c.tab[i + j] = temp % B;
        }
        c.tab[i + l] += carry; // Adds remaining carry
    }

    // Removes leading zeros
    while (c.size > 1 && c.tab[c.size - 1] == 0)
    {
        c.size--;
    }

    return c;
}

// Performs n!
bignum factorial (int n){
   bignum result = {1, (long long int[]){1}};

   // n! = n · (n − 1)...2 · 1
   for (int i = 2; i <= n; i++) {
       bignum ni = {1, (long long int[]){i}};
       result = bigIntMult(result, ni, 10); // base B=10
   }
   return result;
}

   // Test
   int main()
   {
       int n = 40; // number of Fibonacci terms

       bignum result = factorial(n);

       printf("%d! = ", n);
       for (int i = result.size - 1; i >= 0; i--)
       {
           printf("%lld", result.tab[i]);
       }
       printf("\n");

       // Free allocated memory
       free(result.tab);

       return 0;
}
