#include "helpers.h"
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) //loop through the height
    {
        for (int j = 0; j < width; j++) //loop through the pixels in each row
        {
            //used to test my loops and aquisition of pixels
            //printf("%i %i %i\n", image[i][j].rgbtRed, image[i][j].rgbtGreen, image[i][j].rgbtBlue);

            //average out RGB values for all pixels
            int avgRGB = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3;
            //printf("%i ", avgRGB); //tested averaging

            //next set the RGB values to the average value
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = avgRGB;
        }
        //printf("\n");
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
