#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if(argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav");
        return 1;
    }

    // Open input file for reading
    // TODO #2

    char *infile = argv[1];
    FILE *wow = fopen(infile,"rb");
    if(wow == NULL)
    {
        printf("Could not open %s.\n",infile);
        return 2;
    }

    // Read header
    // TODO #3

    WAVHEADER inbuffer;
    fread(&inbuffer,1,sizeof(WAVHEADER),wow);

    // Use check_format to ensure WAV format
    // TODO #4

    if(check_format(inbuffer) != 1)
    {
        printf("Unsupported file format.\n");
        fclose(wow);
        return 3;
    }

    // Open output file for writing
    // TODO #5
    char *outfile = argv[2];
    FILE *now = fopen(outfile,"wb");
    if(now == NULL)
    {
        printf("Could not open %s.\n",outfile);
        return 2;
    }


    // Write header to file
    // TODO #6
    fwrite(&inbuffer,1,sizeof(WAVHEADER),now);

    // Use get_block_size to calculate size of block
    // TODO #7

    int blocksize = get_block_size(inbuffer);


    // Write reversed audio to file
    // TODO #8

    uint8_t conbuffer[blocksize];

    // Header'dan sonra veri nerede başlıyor?
    long data_start = ftell(wow);

    // Dosya sonuna git
    fseek(wow, 0, SEEK_END);
    long file_end = ftell(wow);

    // Kaç byte ses verisi var?
    long data_size = file_end - data_start;

    // En son bloğun pozisyonundan başlayarak ters yaz
    for (long pos = data_start + data_size - blocksize; pos >= data_start; pos -= blocksize)
{
    fseek(wow, pos, SEEK_SET);
    fread(conbuffer, 1, blocksize, wow);
    fwrite(conbuffer, 1, blocksize, now);
}

    // Close infile
    fclose(wow);

    // Close outfile
    fclose(now);

}

int check_format(WAVHEADER header)
{
    if(header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    int bytesPerSample = header.bitsPerSample / 8;
    return (header.numChannels * bytesPerSample);
}






