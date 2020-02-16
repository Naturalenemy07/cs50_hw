#include<stdio.h>
#include<cs50.h>
#include<string.h>

int verify_length(string t);

// run substitution with the 26 letter key
int main(int argc, string argv[])
{
    string key = argv[1];

    verify_unique_letters(key);
    verify_length(key);

    printf("You have the correct length key!\n");



}

int verify_unique_letters(string t)
{

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
        printf("The key must be 26 unique letters!\n");
        return(1);
        break();
    }
}
// verify key meets all requirements:
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
