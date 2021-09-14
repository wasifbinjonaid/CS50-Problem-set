#include "cs50.h"
#include <math.h>
#include <stdio.h>

int main(void)
{
    
    float dollar = get_float("Cash: ");
    int cent = round(dollar * 100);
    
    int coin = 0;

    while (cent != 0)
    {
        if (cent >= 25)
        {
            cent -= 25;
            coin++;
        }    
        else if (cent >= 10)
        {
            cent -= 10;
            coin++;
        }
        else if (cent >= 5)
        {
            cent -= 5;
            coin++;
        }
        else if (cent >= 1)
        {
            cent -= 1;
            coin++;
        }
    }

    printf("total coin: %i\n", coin);
}