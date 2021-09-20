#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // prompt user for input via get_string
    string text = get_string("text: ");
    int letter_count = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isupper(text[i]))
        {
            letter_count += 1;
        }
        else if (islower(text[i]))
        {
            letter_count += 1;
        }
    }

    // printf("%i\n", letter_count);

    int word_count = 1;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            word_count += 1;
        }
    }

    // printf("%i\n", word_count);

    int sentence_count = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sentence_count += 1;
        }
    }

    // printf("%i\n", sentence_count);
    float L = (letter_count * 100) /(float) word_count;
    float S = (sentence_count * 100) /(float) word_count;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    } 
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("%i\n", index);
    }
}