/*
Implements the big integer addition algorithm, for positive integers.
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
bignum bigIntAdd(bignum a, bignum b, int B){
    bignum c;
    int max_size = (a.size > b.size) ? a.size : b.size;
    c.tab = (int *)malloc((max_size + 1) * sizeof(int)); // Allocates memory for the result array
   
    int l = b.size;
    int k = a.size;
    int carry = 0;

    for (int i = 0; i <= l-1; i++){
        int temp = a.tab[i] + b.tab[i] + carry;
        carry = temp / B;
        c.tab[i] = temp % B;
    }

    for (int i = l; i <= k-1; i++)
    {
        int temp = a.tab[i] + carry;
        carry = temp / B;
        c.tab[i] = temp % B;
    }

    // If carry remains after the last addition
    if (carry > 0){
        c.tab[k] = carry;
        c.size = k + 1;
    }
    else
    {
        c.size = k;
    }
   
    return c;
} 


// Test
int main()
{
    bignum num1 = {3, (int[]){7,4,6}}; // a=647, k=3
    bignum num2 = {2, (int[]){5, 8}}; // b=85, l=2
    int B = 10;                      // Base 10

    bignum result = bigIntAdd(num1, num2, B);

    printf("Result: ");
    // Prints the elements in the array as one number
    for (int i = result.size - 1; i >= 0; i--){
        printf("%d", result.tab[i]);
    }
    printf("\n");

    // Free allocated memory
    free(result.tab);

    return 0;
}
