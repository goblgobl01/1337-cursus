#include <stdio.h>

int main()
{
    char c = 0; // Start with all bits cleared (00000000)
    int i = 0;

    while (i < 8)
    {
        c = c << 1; // Shift left by 1 bit to make room for the next bit
        if (i == 0)
            c = c | 1; // Set the least significant bit (rightmost)
        else if (i == 6)
            c = c | 1; // Set the 7th bit (from the right)
        i++;
    }

    printf("This is the letter c after the loop: %c\n", c);
    return 0;
}
