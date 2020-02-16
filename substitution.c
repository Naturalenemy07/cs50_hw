#include<stdio.h>
#include<cs50.h>
#include<string.h>

int verify_unique_letters(string t);
int verify_length(string t);


int main(int argc, string argv[])
{
// First, verify key meets all requirements:

    if(argc != 2) // this if-statement checks the correct usage of single command-line argument by seeing if it is exactly two strings.
    {
        printf("Usage: ./substitution key **key is a string of 26 unique characters**\n");
        return(1);
    }

    string key = argv[1];

    verify_unique_letters(key);
    verify_length(key);

    printf("You have the correct length key!\n");



}


//Custom Functions

int verify_unique_letters(string t)
{
    //we can see if there are any repeats by storing two values at once.
    //store the first character and compare it to the rest of the rest of the characters in the string,
    //then move on to the next character and do the same thing.
    //Repeat this for the rest of the chracters in the string.

    for(int i = 0, n = strlen(t); i < n; i++)
    {
        for(int j = 0, m = n - i - 1; j < m; j++)
        {
            if(t[i] == t[j])
            {
                printf("The key must have all unique characters\n");
                return(1);
            }

            else if(t[i] == t[j] + 32 || t[i] == t[j] - 32)
            {
                printf("The key must have all unique characters, the key isn't case sensitive\n");
                return(1);
            }
        }
    }

}



int verify_length(string t)
{
    int length = strlen(t);

    if(length == 26)
    {
        return(0);
    }

    else
    {
        printf("The key must be 26 characters!\n");
        return(1);
    }
}

// input text
// output encrypted text

/*
int main(void)
{
    string text = get_string("Enter text: ");
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        printf("%c\n", text[i]);
    }
    return(0);

}

*/
