#include<stdio.h>
#include<cs50.h>
#include<string.h>

int verify_only_characters(string t);
int verify_unique_characters(string t);
int verify_length(string t);


int main(int argc, string argv[])
{
    // First, verify key meets all requirements:

    // This if-statement checks the correct usage of single command-line argument by seeing if it is exactly two strings.
    if(argc != 2)
    {
        printf("Usage: ./substitution key **key is a string of 26 unique characters**\n");
        return(1);
    }

    string key = argv[1];

    verify_only_characters(key);
    verify_unique_characters(key);
    verify_length(key);

    // Next, translate the letters in ASCII (including capital letters) to respective letter in the key (in order)

}


//Custom Functions

int verify_only_characters(string t)
{
    for (int i = 0, n = strlen(t); i < n; i++)
    {
        if (t[i] < 65 || t[i] > 122)
        {
            printf("Key can only contain characters!\n");
            return(1);
        }
        else if(t[i] > 90 && t[i] < 97)
        {
            printf("Key can only contain characters!\n");
            return(1);
        }
        else
        {
            printf("Key is only characters!\n");
            return(0);
        }
    }
}

int verify_unique_characters(string t)
{
    int k = 0;

    for (int i = 0, n = strlen(t); i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            // These conditional statements in verify_unique_characters funciton cause "warning: control may reach end of non-void function [-Wreturn-type]" to pop up.
            // The algorithm has verified that only characters can get to this point, so it doesn't matter.  Will look into resolving this error if I have time.
            if (t[i] == t[j])

            {
                k++;
            }

            else if (t[i] == t[j]+32 || t[i] == t[j]-32)
            {
                k++;
            }

            else
            {
                k = k + 0;
            }
        }
    }

    if(k > 0)
    {
        printf("Your key needs to be 26 UNIQUE characters!\n");
        return(1);
    }
    else
    {
        printf("Your key contains unique characters!\n");
        return(0);
    }
}



int verify_length(string t)
{
    int length = strlen(t);

    if (length == 26)
    {
        printf("Your key is 26 characters long!\n");
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
