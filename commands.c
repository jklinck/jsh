#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include "commands.h"

int command(const char *allTokens){
    if(strcmp(&allTokens[0], "cd") == 0){
            return 2;
    }
    else if(strcmp(&allTokens[0], "ls") == 0){
        int id = fork();
        if(id == 0){
            execl("/bin/ls", "ls", NULL);
            perror("execl for ls failed");
        }
        else if(id > 0){
            wait(NULL);
        }
    }
    else if(strcmp(&allTokens[0], "clear") == 0){
        int id = fork();
        if(id == 0){
            execl("/usr/bin/clear", "clear", NULL);
            perror("execl for clear failed");
        }
        else if(id > 0){
            wait(NULL);
        }
    }
    else if(strcmp(&allTokens[0], "exit") == 0){
        return 1;
    }
    else if(strcmp(&allTokens[0], "pwd") == 0){
        char s[100];
        printf("%s\n", getcwd(s, 100));
    }
    else{
        printf("Unkown command\n");
    }

    return 0;
}