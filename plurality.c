#include <stdio.h>
#include <cs50.h>

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
    printf("%s, %s\n", candidates[0].name, candidates[1].name);
    int voters = get_int("Number of voters: ");
    int i = argc-1;
    
    while(voters > 0){
        char* vote = get_string("Vote: ");
        while(i > 0){
            printf("%s\n", candidates[i].name);
            i--;
        }
        voters--;
    }
}
