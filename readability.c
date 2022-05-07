#include <cs50.h>
#include <stdio.h>

int main(void){
    char* text = get_string("Text: ");
    int i = 0;

    float ltrs = 0;
    float sntcs = 0;
    float wrds = 0;

    while(text[i] != '\0'){

        if((text[i]>='a' && text[i]<='z') || (text[i]>='A' && text[i]<='Z')){
            ltrs++;
        }
        else if(text[i]== ' '){
            wrds++;
        }
        else if(text[i] == '!' || text[i]=='.' || text[i]=='?'){
            sntcs++;
        }
        i++;
    }
    wrds++;

    float L = ltrs / wrds * 100;
    float S = sntcs / wrds * 100;

    float index = (0.0588 * L) - (0.296 * S) - 15.8;

    //TODO
    //patch up the rounding problem

    if(index < 1){
        printf("Before Grade 1\n");
    }
    else if(index < 12){
        printf("Grade %d\n", (int)index);
    }
    else{
        printf("16+\n");
    }
}
