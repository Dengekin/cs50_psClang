#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


string gizli (string word, int key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for ( int i = 0; i < strlen(argv[1]); i++)
    {
         if (!isdigit(argv[1][i]))
         {
              printf("Usage: ./caesar key\n");
              return 1;
         }
    }

    int key = atoi(argv[1]) % 26;


    string msg = get_string("plaintext:  ");
    printf("ciphertext: %s\n", gizli (msg, key));



}


string gizli (string word, int key1)
{
     char* yn = malloc (strlen(word) + 1);
     if (yn == NULL)
     {
     fprintf(stderr, "Memory allocation failed\n");
     exit(1);
     }

     for ( int i = 0; i < strlen(word); i++)
     {
          int wordnum = word[i];
          if ( wordnum >= 65 && wordnum <= 90)
          {
              wordnum -= 65;
              wordnum = (wordnum + key1) % 26;
              wordnum += 65;
              yn[i] = (char)wordnum;
          }
          else if (wordnum >=97 && wordnum <= 122)
          {
               wordnum -= 97;
               wordnum = (wordnum + key1) % 26;
               wordnum += 97;
               yn[i] = (char)wordnum;
          }
          else
          {
               yn[i] = word[i];
          }



     }
     yn[strlen(word)] = '\0';
     return yn;
}
