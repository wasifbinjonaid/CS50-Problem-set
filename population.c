#include "cs50.h"
#include <stdio.h>

int main(void)
{
    int start, end;
    do
    {
        start = get_int("Population start size: ");
    }
    while (start < 9);

    do
    {
        end = get_int("Population end size: ");
    }
    while (end < start);

    int year = 0;

    while (start < end)
    {
        start = start + (int) start / 3 - (int) start / 4;
        year++;
    }

    printf("Years: %i\n", year);
}