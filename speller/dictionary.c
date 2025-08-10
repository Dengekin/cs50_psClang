 // Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table>>
const unsigned int N = 65537;

// Hash table
node *table[N];

// Global kelime sayacı
unsigned int word_count = 0;


// Returns true if word is in dictionary, else false
bool check(const char *word)
{

    // TODO
    unsigned int index = hash(word);
    node *cursor = table[index];

    while (cursor != NULL)
    {
        if(strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number djb2 = Daniel J. Bernstein >>
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned long h = 5381;
    int c;
    while ((c = (unsigned char)*word++))
    {
        c = tolower(c);
        h = ((h << 5) + h) + c;
    }
    return h % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dic = fopen(dictionary,"r");
    if(dic == NULL)
    {
        return false;
    }
     // 2) Her kelimeyi okuyup tabloya ekle
    char buffer[LENGTH + 1];
    while( fscanf(dic, "%45s", buffer) == 1)
    {
        // a) yeni düğüm ayır
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            fclose(dic);
            return false;// bellek biterse
        }

        // b) kelimeyi düğüme kopyala
        strcpy ( n->word, buffer );

        // c) hash ile kovayı bul
        unsigned int idx = hash(buffer);

        // d) liste başına ekle (O(1))
        n->next = table[idx];
        table[idx] = n;

        // e) sayacı artır
        word_count++;
    }

    // 3) Dosyayı kapat
    fclose(dic);
    return true;


}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // Tüm kovaları gez
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];


        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;

}
