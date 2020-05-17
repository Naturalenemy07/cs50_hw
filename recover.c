#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: input the image you need to recover only!");
        return 1
    }

    else
    {
        //set the command line argument as our filename which will be opened and read
        argv[1] = filename;

        //Open file
        FILE *f fopen(filename, "r");

        //Look for JPEG files by searching for header of four bytes: Oxff Oxd8 Oxff and Oxe0 - Oxef
        //Each JPEG is stored one after the other

        //allocate 512 bytes?
        void *malloc(buffer 512)
        fread(data, size, number, inptr);
    }
}
