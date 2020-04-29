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
    //set the new colors here = made three seperate arrays but maybe I can do a structure...
    int image_copy_R[height][width];
    int image_copy_G[height][width];
    int image_copy_B[height][width];

    int avg_R;
    int avg_G;
    int avg_B;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Corner pixels
            if ((i == 0 && j == 0) || (i == height-1 && j == 0) || (i == 0 && j == width-1) || (i == height-1 && j == width-1))
            {
                //printf("Corner\n"); //test my corners (read 4)
                if (i == 0 && j == 0)
                {
                    avg_R = round((image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed + image[i][j+1].rgbtRed)/3);
                    avg_G = round((image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen + image[i][j+1].rgbtGreen)/3);
                    avg_B = round((image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue + image[i][j+1].rgbtBlue)/3);
                }

                else if(i == height-1 && j == 0)
                {
                    avg_R = round((image[i][j+1].rgbtRed + image[i-1][j+1].rgbtRed + image[i-1][j].rgbtRed)/3);
                    avg_G = round((image[i][j+1].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i-1][j].rgbtGreen)/3);
                    avg_B = round((image[i][j+1].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i-1][j].rgbtBlue)/3);
                }

                else if (i == 0 && j == width-1)
                {
                    avg_R = round((image[i+1][j].rgbtRed + image[i+1][j-1].rgbtRed + image[i][j-1].rgbtRed)/3);
                    avg_G = round((image[i+1][j].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i][j-1].rgbtGreen)/3);
                    avg_B = round((image[i+1][j].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i][j-1].rgbtBlue)/3);
                }

                else
                {
                    avg_R = round((image[i][j-1].rgbtRed + image[i-1][j-1].rgbtRed + image[i-1][j].rgbtRed)/3);
                    avg_G = round((image[i][j-1].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i-1][j].rgbtGreen)/3);
                    avg_B = round((image[i][j-1].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i-1][j].rgbtBlue)/3);
                }
            }

            //Edge pixels
            else if((i == 0 || i == height-1 || j == 0 || j == width-1))
            {
                //printf("Edge "); //test edges
                if (i == 0)
                {
                    avg_R = round((image[i][j-1].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed + image[i][j+1].rgbtRed)/5);
                    avg_G = round((image[i][j-1].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen + image[i][j+1].rgbtGreen)/5);
                    avg_B = round((image[i][j-1].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue + image[i][j+1].rgbtBlue)/5);
                }

                else if (i == height - 1)
                {
                    avg_R = round((image[i][j-1].rgbtRed + image[i-1][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed + image[i][j+1].rgbtRed)/5);
                    avg_G = round((image[i][j-1].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i][j+1].rgbtGreen)/5);
                    avg_B = round((image[i][j-1].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i][j+1].rgbtBlue)/5);
                }

                else if (j == 0)
                {
                    avg_R = round((image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed + image[i][j+1].rgbtRed + image[i-1][j+1].rgbtRed + image[i-1][j].rgbtRed)/5);
                    avg_G = round((image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen + image[i][j+1].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i-1][j].rgbtGreen)/5);
                    avg_B = round((image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue + image[i][j+1].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i-1][j].rgbtBlue)/5);
                }

                else
                {
                    avg_R = round((image[i+1][j].rgbtRed + image[i+1][j-1].rgbtRed + image[i][j-1].rgbtRed + image[i-1][j-1].rgbtRed + image[i-1][j].rgbtRed)/5);
                    avg_G = round((image[i+1][j].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i][j-1].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i-1][j].rgbtGreen)/5);
                    avg_B = round((image[i+1][j].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i][j-1].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i-1][j].rgbtBlue)/5);
                }
            }

            //Non-edge or Non-corner pixels (has 8 neighboring pixels)
            else
            {
                avg_R = round((image[i+1][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed + image[i][j+1].rgbtRed +
                                    image[i-1][j+1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j-1].rgbtRed + image[i][j-1].rgbtRed)/8);
                avg_G = round((image[i+1][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen + image[i][j+1].rgbtGreen +
                                    image[i-1][j+1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i][j-1].rgbtGreen)/8);
                avg_B = round((image[i+1][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue + image[i][j+1].rgbtBlue +
                                    image[i-1][j+1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i][j-1].rgbtBlue)/8);
            }

            image_copy_R[i][j] = avg_R;
            image_copy_G[i][j] = avg_G;
            image_copy_B[i][j] = avg_B;
        }
    }

    //not set the original image to the blurred colors

    for (int k = 0; k < height; k++)
    {
        for (int m = 0; m < width; m++)
        {
            image[k][m].rgbtRed = image_copy_R[k][m];
            image[k][m].rgbtGreen = image_copy_G[k][m];
            image[k][m].rgbtBlue = image_copy_B[k][m];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int Gx_Kernel[3][3] = {{-1, 0, 1},{-2, 0, 2},{-1, 0, 1}};
    int Gy_Kernel[3][3] = {{-1, -2, -1},{0, 0, 0},{1, 2, 1}};

    //can't figure out how to make a 3x3 matrix around the
    int ULx = Gx_Kernel[1][1];
    int Ux = Gx_Kernel[1][2];
    int URx = Gx_Kernel[1][3];
    int Lx = Gx_Kernel[2][1];
    int Rx = Gx_Kernel[2][3];
    int LLx = Gx_Kernel[3][1];
    int Lx = Gx_Kernel[3][2];
    int LRx = Gx_Kernel[3][3];

    int ULy = Gy_Kernel[1][1];
    int Uy = Gy_Kernel[1][2];
    int URy = Gy_Kernel[1][3];
    int Ly = Gy_Kernel[2][1];
    int Ry = Gy_Kernel[2][3];
    int LLy = Gy_Kernel[3][1];
    int Ly = Gy_Kernel[3][2];
    int LRy = Gy_Kernel[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%i ", Gx_Kernel[i][j])
        }
        printf("\n")
    }

    int Gx_Red[8];
    int Gx_Green[8];
    int Gx_Blue[8];

    int Gy_Red[8];
    int Gy_Green[8];
    int Gy_Blue[8];


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Corner pixels
            if ((i == 0 && j == 0) || (i == height-1 && j == 0) || (i == 0 && j == width-1) || (i == height-1 && j == width-1))
            {
                //printf("Corner\n"); //test my corners (read 4)
                if (i == 0 && j == 0)
                {
                     Gx_Red = image[i+1][j].rgbtRed * Ux + image[i+1][j+1].rgbtRed * URx + image[i][j+1].rgbtRed * Rx;
                     Gx_Green = image[i+1][j].rgbtGreen * Ux + image[i+1][j+1].rgbtGreen * URx + image[i][j+1].rgbtGreen * Rx;
                     Gx_Blue = image[i+1][j].rgbtBlue * Ux + image[i+1][j+1].rgbtBlue * URx + image[i][j+1].rgbtBlue * Rx;

                     Gy_Red = image[i+1][j].rgbtRed * Uy + image[i+1][j+1].rgbtRed * URy + image[i][j+1].rgbtRed * Ry;
                     Gy_Green = image[i+1][j].rgbtGreen * Uy + image[i+1][j+1].rgbtGreen * URy + image[i][j+1].rgbtGreen * Ry;
                     Gy_Blue = image[i+1][j].rgbtBlue * Uy + image[i+1][j+1].rgbtBlue * URy + image[i][j+1].rgbtBlue * Ry;
                }

                else if(i == height-1 && j == 0)
                {

                }

                else if (i == 0 && j == width-1)
                {

                }

                else
                {

                }
            }

            //Edge pixels
            else if((i == 0 || i == height-1 || j == 0 || j == width-1))
            {
                //printf("Edge "); //test edges
                if (i == 0)
                {

                }

                else if (i == height - 1)
                {

                }

                else if (j == 0)
                {

                }

                else
                {

                }
            }

            //Non-edge or Non-corner pixels (has 8 neighboring pixels)
            else
            {

            }
        }
    }

    //Sobel Algorithm
    int n_red = sqrt(Gx_Red^2 + Gy_Red^2);
    int n_green = sqrt(Gx_Green^2 + Gy_Green^2);
    int n_blue = sqrt(Gx_Blue^2 + Gy_Blue^2);

    //maximum value is 255...is there a better way to do this?
    if (n_red > 255)
    {
        n_red = 255;
    }

    if (n_green > 255)
    {
        n_green = 255;
    }

    if (n_blue > 255)
    {
        n_blue = 255;
    }

    return;
}
