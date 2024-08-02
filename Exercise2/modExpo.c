/*
Implements the modular exponentiation algorithm from the course.
*/

#include <stdlib.h>
#include <stdio.h>

// Big Integer
typedef struct
{
    int size;
    long long int *tab;
} bignum;


//  Performs big integer modular exponentiation
// a big integer is represented as an array of digits in base B, with a sign bit
long long int modExpo(bignum *a, long long int b, long long int n)
{
    long long int c = 1;

    for (int i = a->size - 1; i >= 0; i--){
        c = (c*c) % n;
        if (a->tab[i] == 1)
        {
            c = (c * b) % n;
        }
    }

    return c;
}

bignum *init_bignum(int size)
{
    bignum *num = (bignum *)malloc(sizeof(bignum));
    num->size = size;
    num->tab = (long long int *)calloc(size, sizeof(long long int));
    return num;
}

// Test
int main()
{
    long long int base = 2342;

    // The exponent is 6762 which is in binary 0001101001101010
    bignum *exponent = init_bignum(16);
    exponent->tab[15] = 0;
    exponent->tab[14] = 0;
    exponent->tab[13] = 0;
    exponent->tab[12] = 1;
    exponent->tab[11] = 1;
    exponent->tab[10] = 0;
    exponent->tab[9] = 1;
    exponent->tab[8] = 0;
    exponent->tab[7] = 0;
    exponent->tab[6] = 1;
    exponent->tab[5] = 1;
    exponent->tab[4] = 0;
    exponent->tab[3] = 1;
    exponent->tab[2] = 0;
    exponent->tab[1] = 1;
    exponent->tab[0] = 0;
    long long int modulus = 9343;

    long long int result = modExpo(exponent, base, modulus);

    printf("Result = %lld\n", result);

    // Free allocated memory
    free(exponent->tab);
    free(exponent);

    return 0;
}
