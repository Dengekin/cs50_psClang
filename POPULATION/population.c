#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int startsize = get_int ("Start size: ");

    while (startsize < 9)
    {
        startsize = get_int ("Start size: ");

    }



    // TODO: Prompt for end size
    int endsize = get_int ("End size: ");


    while (endsize < startsize)
    {
         endsize = get_int ("End size: ");

    }


    // TODO: Calculate number of years until we reach threshold
    int years;
    for (years = 0; startsize < endsize; years++)
    {
        int born = startsize / 3;
        int die = startsize / 4;
        startsize += born;
        startsize -= die;
    }


    // TODO: Print number of years

    printf("Years: %i", years);
}
