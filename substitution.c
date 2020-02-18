#include<stdio.h>
#include<cs50.h>
#include<string.h>

int verify_only_characters(string t);
int verify_unique_characters(string t);
int verify_length(string t);
int encrypt_text[string txt, string ky]; //getting an error on this line...it is expecting a string here?

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

    // Next, take user input as a string.

    string plain_text = get_string("plaintext: \n");

    // Next, put plain text through encryption algorithm and print ciphertext

    string cipher_text = encrypt_text[plain_text, key];


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

int verify_unique_characters(string t) //this function is failing to produce errors//
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

int encrypt_text[string txt, string ky]
{

    int cipher_code[strlen(txt)];

    for (i = 0, n = strlen(txt); i < n; i++)
    {
        if (txt[i] > 96 && txt[i] < 123)
        {
            cipher_code[i] = ky[txt[i] - 97];
        }

        else if (txt[i] > 64 && txt[i] < 91)
        {
            cipher_code[i] = ky[txt[i] - 65];
        }
        
        else
        {
            cipher_code[i] = txt[i];
        }
    }
}

// this is some code used to figure it out 
/*
{
    string text = "hello, world";
    int ciphertext[strlen(text)];

    string key =   "VCHPRZGJNTLSKFBDQWAXEUYMOI"; //this is a key of 26 unique characters

    for(int i = 0, n = strlen(text); i < n; i++)
    {
        ciphertext[i] = key[text[i]-97];
        printf("%c",ciphertext[i]);
    }

    printf("\n");
}

*/
