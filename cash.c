#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void)
{
    //ask for user input on how much change is due
    float cng = get_float("How much change is owed: "); 
    int change = round(cng * 100);
    
    while (change <= 0) 
    {
        cng = get_float("How much change is owed: ");
        change = round(cng * 100);
    }
        
    //set float values for each coin as a variable
    int q = 25;
    int d = 10;
    int n = 5;
    int p = 1;   
    int coins = 0;
    
    //printf("change = %d\n", change);
    
    while (change >= q)
    {
        change = change - q;
        coins++;
        //printf("%d\n", change);
        //printf("coins: %d\n", coins);
    }
   
    while (change >= d)
    {
        change = change - d;
        coins++;
        //printf("%d\n", change);
        //printf("coins: %d\n", coins);
    }
    
    while (change >= n)
    {
        change = change - n;
        coins++;
        //printf("%d\n", change);
        //printf("coins: %d\n", coins);
    }
    
    while (change >= p)
    {
        change = change - p;
        coins++;
        //printf("%d\n", change);
        //printf("coins: %d\n", coins);
    }
    
    printf("%d\n", coins);
}
