#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //ask user input for pyramid height
    int height = get_int("Height: ");
    int base = height;
    
    while (height < 1 || height > 8) 
    {
        height = get_int("Height: ");
    }
    
    if (height > 0 && height < 9) 
    {   
        for (int i = 1; i <= height; i++)
        {        
            int k = height - i;
        
            for (int m = 0 ; m < k; m++)
            {
                printf(" ");
            } 
        
            for (int n = 0; n < i; n++) 
            {
                printf("#");
            }
        
            printf("  "); // print space in the middle of the pyramid
        
            for (int n = 0 ; n < i; n++) 
            {
                printf("#");
            } 
        
            //for(int m = 0; m < k; m++) {printf(" ");}
        
            printf("\n"); // next pyramid level
        }
    }
}
