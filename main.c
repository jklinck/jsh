#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include "commands.h"

int main(int arg, char *argv[]){

    while(1){   
        // for getline
        char *line = NULL; 
        size_t linecap = 0;
        ssize_t userInput;
        
        // for collecting tokens generated from getline
        char *token;
        const char *allTokens[11] = {0};
        int i = 0; // to create a stopping point for allTokens

        char s[100];
        // printf("%s: ", getcwd(s, 100));
        printf("jsh ~ %% ");
        userInput = getline(&line, &linecap, stdin);
        char *backup = line;
        token = strsep(&line, " \n"); // this clears line, that's why we need backup

        while(token != NULL){
            if(token[0] != '\0' && i < 10){
                allTokens[i] = token;
                i++;
            }
            if(token[0] == '\0'){
                allTokens[i] = NULL;
            }
            token = strsep(&line, " \n");
        }

        if(allTokens[0] == NULL){
            free(backup);
            continue;
        }

        int input = command(*allTokens);
        if(input == 1){
            break;
        }
        else if(input == 2){
            chdir(allTokens[1]);
        }
    } // end while loop and exit program

    return 0;
}


