#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string msg = get_string ("Message: ");
    for( int i = 0; i < strlen(msg); i++)
    {
        int k = msg [i];

       for (int l = 128; l >= 1; l /= 2)
       {
       if(k >= l)
       {
         k -= l;
         print_bulb(1);
       }
       else
       {
         print_bulb(0);
       }
       }
       printf("\n");

    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
