#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<math.h>

int count_letters(string t);
int count_words(string t);
int count_sentences(string t);

int main(void)
{
    //users input from a text
    string text = get_string("Text: ");

    double number_of_letters = count_letters(text); //function counts number of letters
    printf("%f letter(s)\n", number_of_letters); //prints the number of letters

    double number_of_words = count_words(text); // function counts number of words
    printf("%f word(s)\n", number_of_words); //prints the number of words

    double number_of_sentences = count_sentences(text); //function that counts the number of sentences
    printf("%f sentence(s)\n", number_of_sentences);  //prints the number of sentences

    double L_scaled = number_of_letters / number_of_words * 100;
    double S_scaled = number_of_sentences / number_of_words * 100;
    printf("L_scaled: %f\n",L_scaled);
    printf("S_scaled: %f\n",S_scaled);

    int index = round(0.0588 * L_scaled + 0.296 * S_scaled - 15.8);

    if(index < 0)
    {
        printf("Before Grade 1\n");
    }

    else if(index >= 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %i\n", index);
    }

}


int count_letters(string t)  //counter for the amount of letters
{
    int L = 0;

    for(int i = 0, n = strlen(t); i < n; i++)
    {
        if (t[i] >= 'A' && t[i] <= 'Z')
        {
            L++; //adds to counter if ASCII is between 65 and 90, which are capital letters
        }

        else if (t[i] >= 'a' && t[i] <= 'z')
        {
            L++;  //adds to counter if ASCII is between 65 and 90, which are lower case letters
        }
        else
        {
            L = L + 0; //o addition if there are no Roman characters in string at point i
        }

    }

    return(L);
}

int count_words(string t) //counter for the number of words, **assuming sentences don't start or end with spaces, and there is only one space between words and sentences.
{
    int W = 0;

    for (int i = 0, n = strlen(t); i < n; i++)
    {
        if (t[i] == ' ')
        {
            W++; //adds to counter if there is a space
        }
        else
        {
            W = W + 0;//no addition if there is no space
        }

    }

    return(W+1); //adds 1 to counter to count the last word (no space after this word)
}


int count_sentences(string t)
{
    int S = 0;

    for (int i = 0, n = strlen(t); i < n; i++)
    {
        if(t[i] == '.' || t[i] == '!' || t[i] == '?')
        {
            S++;  //adds to counter if a period, exclamation point, or questions mark is encountered(signalling the end of sentence)
        }
        else
        {
            S = S + 0;
        }

    }

    return(S);
}
