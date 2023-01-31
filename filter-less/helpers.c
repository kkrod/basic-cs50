#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // se lleva el pixel a el promedio de rgb o sea la suma entre 3 es el valor
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            int promedio = image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed;
            promedio = round (promedio / 3.0);
            image[i][j].rgbtBlue = promedio;
            image[i][j].rgbtGreen = promedio;
            image[i][j].rgbtRed = promedio;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            int sepiaRed = round( .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round( .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round (.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0, k = width - 1 ; j < (width/2); j++, k--)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][k];
            image[i][k] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
     for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            float count = 0;
            int avgBlue = 0;
            int avgGreen = 0;
            int avgRed = 0;

            for (int k = -1 ; k <= 1 ; k++)
            {
                for (int l = -1 ; l <= 1; l++)
                {
                    int y = k + j;
                    int x = l + i;
                    if (y >= 0 && x >= 0 && y < width && x < height)
                    {
                        avgBlue += copy[x][y].rgbtBlue;
                        avgGreen += copy[x][y].rgbtGreen;
                        avgRed += copy[x][y].rgbtRed;
                        count++;
                    }
                }
            }
            image[i][j].rgbtBlue = round (avgBlue / count);
            image[i][j].rgbtGreen = round (avgGreen / count);
            image[i][j].rgbtRed = round (avgRed / count) ;
        }
    }
    return;
}
