#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long credit = get_long ("Number: ");

  if((340000000000000 <= credit && credit <= 349999999999999) || (370000000000000 <= credit && credit <= 379999999999999))
    {
      long toplamamex = 0;
      long carpimamex = 0;
      long geneltoplam1 = 0;
      long credit1 = credit;
      for(int i = 0; i < 15 ; i++)
      {
        if(i == 0 || i % 2 == 0)
        {
         toplamamex = credit1 % 10;
         geneltoplam1 += toplamamex;
        }
        else
        {
        carpimamex = credit1 % 10;
        carpimamex *= 2;
        if(carpimamex > 9)
        {
           carpimamex -= 9;
        }
         geneltoplam1 += carpimamex;
        }
        credit1 /= 10;
      }

      if (geneltoplam1 % 10 == 0)
      {
        printf("AMEX\n");
      }
      else
      {
        printf("INVALID\n");
      }

    }


 else if(5100000000000000 <= credit && credit <= 5599999999999999)
    {
      long toplamMC = 0;
      long carpimMC = 0;
      long geneltoplam2 = 0;
      long credit2 = credit;
      for(int k = 0; k < 16 ; k++)
      {
         if(k == 0 || k % 2 == 0)
         {
         toplamMC = credit2 % 10;
         geneltoplam2 += toplamMC;
         }
         else
         {
         carpimMC = credit2 % 10;
         carpimMC *= 2;
         if(carpimMC > 9)
         {
           carpimMC -= 9;
         }
         geneltoplam2 += carpimMC;
         }
         credit2 /= 10;
      }
         if (geneltoplam2 % 10 == 0)
         {
         printf("MASTERCARD\n");
         }
         else
         {
         printf("INVALID\n");
         }

      }


  else if(4000000000000 <= credit && credit <= 49999999999999)
    {
      long toplamV = 0;
      long carpimV = 0;
      long geneltoplam3 = 0;
      long credit3 = credit;
      for(int m = 0; m < 13 ; m++)
      {
        if(m == 0 || m % 2 == 0)
        {
         toplamV = credit3 % 10;
         geneltoplam3 += toplamV;
        }
        else
        {
        carpimV = credit3 % 10;
        carpimV *= 2;
        if(carpimV > 9)
        {
           carpimV -= 9;
        }
        geneltoplam3 += carpimV;
        }
        credit3 /= 10;
      }
       if (geneltoplam3 % 10 == 0)
        {
        printf("VISA\n");
        }
        else
       {
        printf("INVALID\n");
       }

      }


  else if(4000000000000000 <= credit && credit <= 4999999999999999)
    {
      long toplamV2 = 0;
      long carpimV2 = 0;
      long geneltoplam4 = 0;
      long credit4 = credit;
      for(int o = 0; o < 16 ; o++)
      {
        if(o == 0 || o % 2 == 0)
      {
         toplamV2 = credit4 % 10;
         geneltoplam4 += toplamV2;
      }
      else
      {
        carpimV2 = credit4 % 10;
        carpimV2 *= 2;
        if(carpimV2 > 9)
        {
           carpimV2 -= 9;
        }
        geneltoplam4 += carpimV2;
       }
       credit4 /= 10;
      }
      if (geneltoplam4 % 10 == 0)
      {
        printf("VISA\n");
      }
       else
      {
        printf("INVALID\n");
      }
      }


  else
  {
    printf("INVALID\n");
  }
}




