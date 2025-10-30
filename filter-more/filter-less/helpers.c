#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
     // Her satır için
    for (int i = 0; i < height; i++)
    {
        // Her sütun için
        for (int j = 0; j < width; j++)
        {
            // RGB değerlerini al
            float average = (image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0;

            // En yakın tam sayıya yuvarla
            int grayscale = (int)(average + 0.5);

            // Her bileşeni eşitle
            image[i][j].rgbtRed = grayscale;
            image[i][j].rgbtGreen = grayscale;
            image[i][j].rgbtBlue = grayscale;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    // Her satır için
    for (int i = 0; i < height; i++)
    {
        // Her sütun için
        for (int j = 0; j < width; j++)
        {

           float sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
           float sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
           float sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;

           int sr = (int)(sepiaRed + 0.5);
           int sg = (int)(sepiaGreen + 0.5);
           int sb = (int)(sepiaBlue + 0.5);

           sr = fmin(255,sr);
           sg = fmin(255,sg);
           sb = fmin(255,sb);

           // Her bileşeni eşitle
           image[i][j].rgbtRed = sr;
           image[i][j].rgbtGreen = sg;
           image[i][j].rgbtBlue = sb;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Her satır için
    for (int i = 0; i < height; i++)
    {
        // Her sütun için
        for (int j = 0; j < width/2; j++)
        {
            RGBTRIPLE ref;
            ref = image[i][width - j - 1];
            image[i][j] = ref;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Öncelikle image dizisinin bir kopyasını oluştur
    RGBTRIPLE copy[height][width];

    // Kopyaya image'deki tüm pikselleri aktar
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Her piksel için
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int redSum = 0;
            int greenSum = 0;
            int blueSum = 0;
            int count = 0;

            // Komşuları ve kendisini kontrol et (3x3 kutu)
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;

                    // Sınır kontrolü yap
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        redSum += copy[ni][nj].rgbtRed;
                        greenSum += copy[ni][nj].rgbtGreen;
                        blueSum += copy[ni][nj].rgbtBlue;
                        count++;
                    }
                }
            }

            // Ortalama renk değerlerini hesapla ve ata
            image[i][j].rgbtRed = (int)(redSum / (float)count + 0.5);
            image[i][j].rgbtGreen = (int)(greenSum / (float)count + 0.5);
            image[i][j].rgbtBlue = (int)(blueSum / (float)count + 0.5);
        }
    }

    return;
}
