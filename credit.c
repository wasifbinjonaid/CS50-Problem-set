#include "cs50.h"
#include <stdio.h>

int find_length(long long card);

int main(void)
{
    // prompt user for credit card
    long long credit_card = get_long_long("Credit Card: ");
    int card_length = find_length(credit_card);

    if (card_length == 13 || card_length == 16 && 
        credit_card > 4000000000000000 && credit_card < 5000000000000)
    {
        printf("VISA\n");
    }

    else if (card_length == 15 && credit_card > 340000000000000 && credit_card < 350000000000000 ||
        credit_card > 370000000000000 && credit_card < 380000000000000)
    {
        printf("AMEX\n");
    }

    else if (card_length == 16 && credit_card > 5100000000000000 && credit_card < 5500000000000000)
    {
        printf("MASTERCARD\n");
    }

    else
    {
        printf("Please Enter a valid Card\n");
    }

    int digit = 0;
    int sum = 0;
    int cary = 0;
    int nf = 0;

    // loop through the digits
    for (int i = 0; i < card_length; i++)
    {
        // separate each digits
        digit = credit_card % 10;
        credit_card = credit_card / 10;

        // checksum
        if (i % 2 != 0)
        {
            if (digit * 2 < 10)
                sum += digit * 2;
            else
            {
                nf = digit * 2 % 10 + digit * 2 / 10;
                sum += nf;
            }
        }
        else
        {
            cary = cary + digit;
        }
    }

    if ((sum + cary) % 10 == 0)
    {
        printf("card is valid\n");
    }
    else
    {
        printf("card is not valid\n");
    }
}

int find_length(long long card)
{
    int l = 0;
    while (card != 0)
    {
        card = card / 10;
        l++;
    }

    return l;
}