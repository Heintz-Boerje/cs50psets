#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){

    if(argc != 2){
        printf("Usage:  ./substitution key\n");
        return 1;
    }

    if(strlen(argv[1]) != 26){
        printf("Key must contain 26 alphabetical characters.\n");
        return 1;
    }

    for(int i = 0; i < 26; i++){
        if(argv[1][i] < 'A' || argv[1][i] > 'z' || (argv[1][i]>'Z' && argv[1][i] < 'a')){
            printf("Key must only contain alphabetical characters\n");
            return 1;
        }
        for(int j = i+1; j < 26; j++){
            if(argv[1][i] == argv[1][j]){
                printf("The key musn't contain duplicate characters\n");
                return 1;
            }
        }
    }
    char* key = argv[1];
    int u = 0;
    while(key[u] != '\0'){
        if(key[u]>= 'A' && key[u]<='Z'){
            key[u] += 32;
        }
        u++;
    }
    char* plntxt = get_string("plaintext: ");
    char* aleph = "abcdefghijklmnopqrstuvwxyz";
    char output[strlen(plntxt)];
    int i = 0;

    while(plntxt[i] != '\0'){
        for(int j = 0; j < 26; j++){
            if( (plntxt[i]>='a' && plntxt[i]<='z') || (plntxt[i]>='A' && plntxt[i] <= 'Z')){
                if(aleph[j] == plntxt[i]){
                    output[i] = key[j];
                }
                else if(aleph[j]-32 == plntxt[i]){
                    output[i] = key[j]-32;
                }
            }
        else{
                output[i] = plntxt[i];
            }
        };
    i++;
    }

    output[i]='\0';
    printf("cyphertext: %s\n", output);
}
