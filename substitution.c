#include<stdio.h>
#include<cs50.h>
#include<string.h>

// run substitution with the 26 letter key
// verify key meets all requirements
// input text
// output encrypted text

int main(void)
{
    string text = get_string("Enter text: ");
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        printf("%c\n", text[i]);
    }
    return(0);

}
