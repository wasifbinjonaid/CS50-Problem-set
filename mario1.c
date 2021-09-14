#include "cs50.h"
#include <stdio.h>

int main(void)
{
    int height;
    
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (i >= height-j-1)
                printf("#");
            else
                printf(" ");
        }

        printf("  ");

        for (int z = 0; z < height; z++)
        {
            if (i >= z)
                printf("#");
            else
                printf(" ");
        }

        printf("\n");
    }
    
}