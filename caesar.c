#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>

int verify_key_number(int key);

int main(int argc, string argv[])
{

    // this will verify that the command line argument is only 2 inputs: the ./caesar COMMAND and the KEY
    if (argc != 2)
    {
        printf("Use Command Line argument: ./caesar key **key is a number only\n");
        return(1);
    }

    string key = argv[1]; //set the key as an integer, which is the second input of the command line argument

    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (key[i] < 48 || key[i] > 57)
        {
            printf("Key should be a number!\n");
            return(1);
        }
    }

    int key_int = atoi(key); // use of the atoi() function converts a string into an integer

    //printf("%i\n", key_int); just to make sure that the key has now been transformed into an integer

    string plaintext = get_string("plaintext: ");

    int cipher_text[strlen(plaintext)]; //cipher_text is an array of integers synominous to the plaintext

    int max_cap = 90;//set min and max values of caps and lower case
    int min_cap = 65;
    int max_low = 122;
    int min_low = 97;

    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        //Upper case characters

        if (plaintext[i] > min_cap - 1 && plaintext[i] < max_cap + 1)
        {
            cipher_text[i] = plaintext[i] + key_int;

            if (cipher_text[i] > max_cap)
            {
                int j = max_cap - plaintext[i];
                cipher_text[i] = min_cap - 1 - j + key_int;
            }
        }


        //Lowercase characters

        else if (plaintext[i] > min_low - 1 && plaintext[i] < max_low + 1)
        {
            cipher_text[i] = plaintext[i] + key_int;


            if (cipher_text[i] > max_low)
            {
                int j = max_low - plaintext[i];
                cipher_text[i] = min_low - 1 - j + key_int;
            }
        }

        //non-characters

        else
        {
            cipher_text[i] = plaintext[i];
        }

        printf("%c", cipher_text[i]);
    }
    printf("\n");
}
