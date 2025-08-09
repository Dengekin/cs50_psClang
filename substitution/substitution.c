#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


string subs (string word, string key);

int main(int argc, string argv[])
{

    if ( argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if(!isalpha(argv[1][i]) || strlen (argv[1]) != 26)
        {
          printf("Key must contain 26 characters\n");
          return 1;
        }
    }

    int counts[26] = {0};
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        int index = tolower(argv[1][i]) - 'a';
        if (counts[index] == 1)
        {
            printf("Each letter in the key must appear exactly once\n");
            return 1;
        }
        counts[index]++;
    }

    string plaintext = get_string("plaintext: ");
    string ciphertext = subs(plaintext, argv[1]);
    printf("ciphertext: %s\n", ciphertext);

    // Free dynamically allocated memory
    free(ciphertext);

    return 0;
}


string subs (string word, string key)
{
   char* subst = malloc (strlen(word) + 1);
   if (subst == NULL)
   {
    fprintf (stderr, "Memory allocation failed\n");
    exit(1);
   }

   for (int i = 0; i < strlen(word); i++)
   {
    if (islower(word[i]))
    {
        int wordnuml = word [i] - 'a';
        subst[i] = tolower(key[wordnuml]);
    }
    else if (isupper(word[i]))
    {
        int wordnumu = word[i] - 'A';
        subst[i] = toupper(key[wordnumu]);
    }
    else
    {
        subst[i] = word[i];
    }

   }
   subst[strlen(word)] = '\0';
   return subst;
}
