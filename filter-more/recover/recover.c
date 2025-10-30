#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("usage error");
        return 1;
    }

    char *infile = argv[1];

    FILE *forensic = fopen(infile, "rb");
    if(forensic == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];
    FILE *gbuffer = NULL;
    int i = 0;
    char outjpg[8];

    while (fread(buffer, 1, BLOCK_SIZE, forensic) == BLOCK_SIZE)
    {

    if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
         if (gbuffer != NULL)
            {
                fclose(gbuffer);
            }
        sprintf(outjpg, "%03i.jpg", i);
        gbuffer = fopen(outjpg, "wb");
        fwrite(&buffer,1,BLOCK_SIZE,gbuffer);
        i++;
    }
    else if ( i != 0)
    {
        fwrite(&buffer,1,BLOCK_SIZE,gbuffer);
    }


}

}

