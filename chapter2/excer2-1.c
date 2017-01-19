#include <stdio.h>
#include <limits.h>
#include <float.h>

/*
Write a program to determine the ranges of char, short, int and long variables, both signed and unsigned, by printing appropriate values from standard headers and direct computation. Harder if you compute them: determine the ranges of the various floating-point types.
*/

// https://en.wikipedia.org/wiki/Two's_complement
// unsiged char = number of bits~0 = two's complement. The max size for the bits, for all positive.
// shift the bits left by 1 to get the max for signed, do the same for min, invert and minus 1.
// ~0 = -1
// (unsigned char) ~0 = (0000 0000) ~0 = (1111 1111) = 255
// (unsigned char) ~0 >> 1 = (0000 0000) ~0 >> 1 = (1111 1111) >> 1 = (0111 1111) = 127
// -(unsigned char) ~0 >> 1 = -(0000 0000) ~0 >> 1 - 1 = -(1111 1111) >> 1 - 1 = -(0111 1111) - 1 = -127 - 1 = -128
int main() 
{
        printf("Chars:\n");
        printf("\tThe size of unsigned Char Max: %d\n", (unsigned char)~0);
        printf("\tThe size of signed Char Max: %d\n", (unsigned char)~0 >> 1);
        printf("\tThe size of signed Char Min: %d\n", -((unsigned char)~0 >> 1) - 1);

        printf("Ints:\n");
        printf("\tThe size of unsigned int: %u\n", (unsigned int)~0);
        printf("\tThe size of signed int Max: %d\n", (int)((unsigned int) ~0 >> 1));
        printf("\tThe size of signed int Min: %d\n", -(int)((unsigned int) ~0 >> 1) - 1);
        
        printf("Shorts:\n");
        printf("\tThe size of unsigned short: %d\n", (unsigned short)~0);
        printf("\tThe size of signed short Max: %d\n", (short)((unsigned short)~0 >> 1));
        printf("\tThe size of signed short Min: %d\n", -(short)((unsigned short)~0 >> 1) -1);

        printf("Longs:\n");
        printf("\tThe size of unsiged long: %lu\n", (unsigned long)~0);
        printf("\tThe size of signed long Max: %ld\n", (long)((unsigned long)~0 >> 1));
        printf("\tThe size of signed long Min: %ld\n", -(long)((unsigned long)~0 >> 1) - 1);
}
