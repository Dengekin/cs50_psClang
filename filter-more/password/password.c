// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    char noya[5] = {0};

    for (int i = 0; i < strlen(password); i++)
    {
        if(isupper(password[i]))
        {
            noya[0] = 'n';
        }
        else if(islower(password[i]))
        {
            noya[1] = 'o';
        }
        else if(isdigit(password[i]))
        {
            noya[2] = 'y';
        }
        else if(ispunct(password[i]))
        {
            noya[3] = 'a';
        }
     }
            noya[4] = '\0';

     if (strcmp(noya,"noya") == 0)
     {
        return true;
     }
     else
     {
        return false;
     }
}
