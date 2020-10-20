#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//Reference all the functions that are being used
int letter_count(string s);
int word_count(string s);
int sent_count(string s);
float index_calc(float L, float S);

int main(void)
{
    //Get the String Input
    string str_var = get_string("Text: ");

    //Get the count values
    float lttr_count = letter_count(str_var);
    float wrd_count = word_count(str_var);
    float snt_count = sent_count(str_var);

    //Calc the averages
    float lettr_avg = (lttr_count / wrd_count) * 100;
    float sent_avg = (snt_count / wrd_count) * 100;
    int indx_val = index_calc(lettr_avg, sent_avg);

    //Check the different index cases
    if (indx_val >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (indx_val < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", indx_val);
    }


}

//Function to count number of letters in string.
int letter_count(string s)
{
    int lttr = 0;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        char up_s = toupper(s[i]);

        if (up_s >= 65 && up_s <= 90)
        {
            lttr++;
        }
    }
    return lttr;
}

//Function to count the number of words in a string.
int word_count(string s)
{
    int wrd = 0;
    int spc = 0;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == ' ')
        {
            spc++;
        }
    }
    wrd = spc + 1;
    return wrd;
}

//Function to count the number of sentences in a string
int sent_count(string s)
{
    int snt = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == '!' || s[i] == '.' || s[i] == '?')
        {
            snt++;
        }
    }
    return snt;
}

//Index Calc Function
float index_calc(float L, float S)
{
    float idx = (0.0588 * L) - (0.296 * S) - 15.8;
    idx = round(idx);

    return idx;

}