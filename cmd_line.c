#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    if (argc == 3) //can take up to 3 arguments in command line
    {
        printf("hello, %s %s\n!", argv[1], argv[2]);

    }

    else if (argc == 2)
    {
        printf("hello, %s\n!", argv[1]);
    }

    else
    {
        printf("hello, world!\n");
    }

}
