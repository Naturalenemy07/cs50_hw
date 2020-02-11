#include<stdio.h>
#include<cs50.h>
#include<string.h>

// run substitution with the 26 letter key
// verify key meets all requirements
// input text
// output encrypted text

int main(void)
{
    string text = get_string("Enter text: "); // this is to test whether indivudual characters in a string can be printed
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        printf("%c\n", text[i]);
    }
    return(0);

}

// Now that individual strings can be accessed, I need to figure out how to take an input and set each letter in the alphabet to the key in successive order. 
