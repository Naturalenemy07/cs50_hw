#include <stdio.h>
#include <cs50.h>

int collatz(int n, int i);
//this program calculates how many steps it takes to get back to 

int main(void)
{
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
        return 1 + collatz(3 * n + 1, i);
    }

    else
    {
        return 1 + collatz(n / 2, i);
    }
}
