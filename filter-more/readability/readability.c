#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
 string text = get_string("Text: ");

 int lettercount = 0;
 int sentencecount = 0;
 int wordcount = 1;
 size_t len = strlen(text);
 for (int i = 0; i < len; i++)
 {
    if (text[i] == '.' || text[i] == '!' || text[i] == '?')
    {
        sentencecount += 1;
    }
    else if (isalpha(text[i]))
    {
        lettercount += 1;
    }
    else if (text[i] == ' ')
    {
        wordcount += 1;
    }
 }

 // Ortalama değerler
    float L = (float) lettercount / wordcount * 100;
    float S = (float) sentencecount  / wordcount * 100;

    // Coleman-Liau index
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }

}
