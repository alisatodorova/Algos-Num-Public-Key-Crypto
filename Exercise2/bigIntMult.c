/*
Implements the multiplication algorithm on big integers, for positive integers.
*/

#include <stdlib.h>
#include <stdio.h>

// Big Integer
typedef struct
{
    int size;
    int *tab;
} bignum;

//  Performs big integer multiplication where
// a big integer is represented as an array of digits in base B, with a sign bit
bignum bigIntMult(bignum a, bignum b, int B)
{
    int l = b.size;
    int k = a.size;
    int carry = 0;

    bignum c;
    int max_size = k + l;
    c.tab = (int *)malloc((max_size + 1) * sizeof(int)); // Allocates memory for the result array
    c.size = max_size;

    for (int i = 0; i <= max_size; i++)
    {
        c.tab[i] = 0;
    }

    for (int i = 0; i <= k - 1; i++)
    {
        carry = 0;

        for (int j = 0; j <= l - 1; j++)
        {
            int temp = a.tab[i] * b.tab[j] + c.tab[i + j] + carry;
            carry = temp / B;
            c.tab[i + j] = temp % B;
        }
        c.tab[i + l] += carry; // Adds remaining carry
    }

    // Removes leading zeros
    while (c.size > 1 && c.tab[c.size - 1] == 0){
        c.size--;
    }

    return c;
}

// Test
int main()
{
    bignum num1 = {2, (int[]){7, 3}};  // a=37, k=2
    bignum num2 = {2, (int[]){5, 8}}; // b=85, l=2
    int B = 10;                      // Base 10

    bignum result = bigIntMult(num1, num2, B);

    printf("Result: ");
    // Prints the elements in the array as one number
    for (int i = result.size - 1; i >= 0; i--)  {
        printf("%d", result.tab[i]);
    }
    printf("\n");

    // Free allocated memory
    free(result.tab);

    return 0;
}
