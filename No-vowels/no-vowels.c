// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

string replace (string word);

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }

    string modified = replace(argv[1]);
    printf("%s\n", modified);

    free (modified);

    return 0;
}



string replace (string word)
{
    char* mdf = malloc(strlen(word) + 1);
    if (mdf == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }


    for ( int i = 0; i <= strlen(word); i++ )
    {
     switch (word[i]){

        case 'a':
        case 'A':
            mdf[i] = '6';
            break;

        case 'e':
        case 'E':
            mdf[i] = '3';
            break;

        case 'i':
        case 'I':
            mdf[i] = '1';
            break;

        case 'o':
        case 'O':
            mdf[i] = '0';
            break;

        default:
            mdf[i] = word[i];
      }
    }
     return mdf;
}
