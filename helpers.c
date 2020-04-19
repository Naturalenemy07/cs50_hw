#include "helpers.h"
#include <stdio.h>
#include <math.h>

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
            int avgRGB = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3);
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
    int temp_R;
    int temp_G;
    int temp_B;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            //set the global variable pointers to the values held by the pixels
            temp_R = image[i][j].rgbtRed;
            temp_G = image[i][j].rgbtGreen;
            temp_B = image[i][j].rgbtBlue;

            //next set the pixels equal to the adjacent pixels on other side of the picture
            image[i][j].rgbtRed = image[i][width - j -1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;

            //reflect
            image[i][width - j - 1].rgbtRed = temp_R;
            image[i][width - j - 1].rgbtGreen = temp_G;
            image[i][width - j - 1].rgbtBlue = temp_B;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Corner pixels
            if ((i == 0 && j == 0) || (i == height-1 && j == 0) || (i == 0 && j == width-1) || (i == height-1 && j == width-1))
            {
                //printf("Corner\n"); //test my corners (read 4)
            }

            //Edge pixels
            else if((i == 0 || i == height-1 || j == 0 || j == width-1))
            {
                //printf("Edge "); //test edges
            }

            //Non-edge or Non-corner pixels (has 8 neighboring pixels)
            else
            {

            }
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
