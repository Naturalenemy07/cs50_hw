
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
