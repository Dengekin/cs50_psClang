// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>

#define NUM_CITIES 10

typedef struct
{
    string city;
    int temp;
}
avg_temp;

avg_temp temps[NUM_CITIES];

void sort_cities(void);

int main(void)
{
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    sort_cities();

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}


void sort_cities(void)
{


    // SELECTION SORT



//    for ( int i = 0; i < NUM_CITIES - 1; i++ )
//   {
//    int max = i;
//    for ( int j = i + 1; j < NUM_CITIES; j++)
//    {
//        if (temps[j].temp > temps[max].temp)
//        {
//            max = j;
//        }
//    }
//     if (max != i)
//        {
//            int temp_temp = temps[i].temp;
//            temps[i].temp = temps[max].temp;
//            temps[max].temp = temp_temp;
//            string temp_city = temps[i].city;
//            temps[i].city = temps[max].city;
//            temps[max].city = temp_city;
//         }




                        // BUBBLE SORT

//    int swpcntr;
//    do
//   {
//
//    swpcntr = 0;
//    for (int i = 0; i < NUM_CITIES - 1; i++)
//    {
//
//
//            if (temps[i].temp < temps[i + 1].temp)
//            {
//            // Swap temperatures
//            int temp_temp = temps[i].temp;
//            temps[i].temp = temps[i + 1].temp;
//            temps[i + 1].temp = temp_temp;
//
//            // Swap cities
//            string temp_city = temps[i].city;
//            temps[i].city = temps[i + 1].city;
//            temps[i + 1].city = temp_city;
//            swpcntr++;
//            }
//    }
//
//    }
//    while (swpcntr != 0);


                                // INSERTION SORT

     for (int i = 1; i < NUM_CITIES; i++)
     {
        avg_temp key = temps[i];
        int j = i - 1;

        while ( j >= 0 && temps[j].temp < key.temp)
        {
            temps[j + 1] = temps[j];
            j = j - 1;
        }
        temps[j + 1] = key;
     }

}
