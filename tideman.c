#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>

typedef struct{
    char* name;
    int* rank;
}
candidate;

int main(int argc, char* argv[]){

    if(argc == 2){
        printf("%s won by default\n", argv[1]);
        return 0;
    }
    else if(argc < 2){
        printf("Usage: ./tideman candidate_names\n");
        return 1;
    }

    candidate candidates[argc-1];

    for(int i=1; i<argc; i++){
        candidates[i-1].name = argv[i];
        candidates[i-1].rank = malloc(argc-1);
    }

    for(int i=0; i<argc-1; i++){
        for(int j=0; j<argc-1; j++){
            printf("%i \n", candidates[i].rank[j]);
        }
    }

    //Didn't yet know of a better way to free the memory.
    for(int i=0; i<argc-1; i++){
        free(candidates[i].rank);
    }
}
