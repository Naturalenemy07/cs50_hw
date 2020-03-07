#include <stdio.h>
#include <cs50.h>

int collatz(int n, int i);
//this program calculates how many steps it takes to get back to 

int main(void)
{
    int i = 0;
    int n = get_int("n: "); //gets input for what n should
    int steps = collatz(n, i);
    printf("Steps: %i\n", steps);
}


int collatz(int n, int i)
{

    if (n == 1)
    {
        return(i);
    }

    else if (n % 2 == 1)
    {
        i++;
        return collatz(3 * n + 1, i);
    }

    else
    {
        i++;
        return collatz(n / 2, i);
    }
}
