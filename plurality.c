#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct{
    char* name;
    int votes;
}candidate;

int main(int argc, char* argv[]){

    if(argc == 2){
        printf("%s won by default\n", argv[1]);
        return 0;
    }
    else if(argc < 2){
        printf("Usage: ./plurality candidate_names\n");
        return 1;
    }

    candidate candidates[argc-1];

    for(int i = 1; i < argc; i++){
        candidates[i-1].name = argv[i];
        candidates[i-1].votes = 0;
    }

    int voters = get_int("Number of voters: ");

    while(voters>0){
        char *vote = get_string("Vote: ");
        for(int i = 0; i < (argc-1); i++){
            if(strcmp(vote, candidates[i].name)==0){
                candidates[i].votes++;
            }
        }
        voters--;
    }

    for(int i = 0; i < argc-1; i++){
        for(int j=i+1; j < argc-1; j++){
            if(candidates[j].votes > candidates[i].votes){
                candidate temp = candidates[i];
                candidates[i] = candidates[j];
                candidates[j] = temp;
            }
        }
    }

    int i = 0;
    while(candidates[i].votes == candidates[0].votes){
        printf("%s ", candidates[i].name);
        i++;
    }
    printf("\n");
}
