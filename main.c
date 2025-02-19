#include "parser.h"
#include "fonction-pwd.h"
#include "fonction-mkdir.h"
#include "fonction-cat.h"
#include "fonction-cd.h"
#include "fonction-ls.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <sys/types.h>


int main(int argc, char *argv){
    char *input;
    while(1){
        printf("MyShell> ");
        if (fgets(input, 100, stdin) == NULL)
        break;
       }
       input[strcspn(input, "\n")] = 0;
       parse(input, " ");
         if(strcmp(input, "exit") == 0)
            {
                exit(0);
            }
         
         else if(strcmp(input, "cd") == 0){
              cd(" ");
         } 
         else if(strcmp(input, "ls") == 0){
              ls(" ");
         }
         else if(strcmp(input, "pwd") == 0){
              pwd(" ");
         }
         else if(strcmp(input, "mkdir")==0){
              mkdir(" ");
         } else if (strcmp(input, "cat") == 0){
              cat(" ");
         }
         else{
              printf("Commande non reconnue\n");
         }


         execute(input);
         




    return 0;
}