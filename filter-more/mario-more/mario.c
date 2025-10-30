#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int yuks;
    do{
        yuks = get_int ("Height: ");
    }
    while (yuks < 1 || yuks > 8);

    for (int i = 1; i <= yuks; i++)
    {
        for(int bos1 = 0; bos1 < yuks - i; bos1++)
        {
            printf(" ");
        }
        for(int dolu1 = 0; dolu1 < i; dolu1++)
        {
            printf("#");
        }
        for(int kbos = 0; kbos < 2; kbos++)
        {
            printf(" ");
        }
        for(int dolu2 = 0; dolu2 < i; dolu2++)
        {
            printf("#");
        }
        for(int bos2 = 0; bos2 < yuks - i; bos2++)
        {
            printf(" ");
        }
        printf("\n");
    }
}
