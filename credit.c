#include <stdio.h>
#include <cs50.h>

void mkdigits(long, int*);
bool checksum(int*, int);

int main(void){

    long num = get_long("Number: ");
    int diginum = 0;

    if( num >= 1000000000000 && num <= 10000000000000){
        diginum = 13;
    }
    else if(num >= 100000000000000 && num <= 1000000000000000 ){
        diginum = 15;
    }
    else if(num >= 1000000000000000 && num <= 10000000000000000 ){
        diginum = 16;
    }
    else{
        printf("INVALID\n");
        return 1;
    }

    int digits[diginum];
    mkdigits(num, digits);
    bool valid = checksum(digits, diginum);

    if(valid){
        if(diginum == 15 && digits[diginum-1] == 3 && (digits[diginum-2] == 4 || digits[diginum-2]==7)){
            printf("AMEX\n");
            return 0;
        }
        else if((diginum == 13 || diginum == 16) && digits[diginum-1]==4){
            printf("VISA\n");
            return 0;
        }
        else if((digits[diginum-2]>=1 && digits[diginum-2]<=5) && digits[diginum-1] == 5 && diginum == 16){
            printf("MASTERCARD\n");
            return  0;
        }
        else{
            printf("INVALID\n");
            return 1;
        }
    }
    else{
        printf("INVALID\n");
        return 1;
    }
}

void mkdigits(long num, int* digits){
    int i = 0;
    while(num > 0){
        digits[i] = num%10;
        num /= 10;
        i++;
    }
}

bool checksum(int* digits, int diginum){
    int sum = 0;

    for(int i = 1; i < diginum; i += 2){
        sum += (digits[i]*2)/10 + (digits[i]*2)%10;
    }
    for(int i = 0; i < diginum; i += 2){
        sum += digits[i];
    }
    if(sum % 10 == 0){
        return 1;
    }
    return 0;
}
