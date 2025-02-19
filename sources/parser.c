#include "parser.h"
#include "fonction-cd.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <sys/types.h>

#define MAX_LINE 1024
#define MAX_TOKEN 128

// Function to parse the input command
void parse(char *input, char *tokens[])
{
    char *token;
    int i = 0;

    token = strtok(input, " ");
    while (token != NULL)
    {
        tokens[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;
}

// Function to read the input command
void read_input(char *input)
{
    fgets(input, MAX_LINE, stdin);
    input[strcspn(input, "\n")] = 0;
}

// Function to execute the command
void execute(char *tokens[])
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    char command[MAX_LINE] = "";
    for (int i = 0; tokens[i] != NULL; i++)
    {
        strcat(command, tokens[i]);
        strcat(command, " ");
    }

    if (!CreateProcess(NULL, command, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
    {
        printf("Error executing command\n");
        return;
    }

    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

// Function to print the prompt
void print_prompt()
{
    char cwd[MAX_LINE];
    GetCurrentDirectory(MAX_LINE, cwd);
    printf("%s> ", cwd);
}

// Function to change the directory


// Function to print the history
void print_history(char *history[], int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%d. %s\n", i + 1, history[i]);
    }
}

// Function to add the command to history
void add_history(char *history[], char *input, int *count)
{
    if (*count < MAX_LINE)
    {
        history[*count] = strdup(input);
        *count = *count + 1;
    }
    else
    {
        for (int i = 0; i < MAX_LINE - 1; i++)
        {
            history[i] = history[i + 1];
        }
        history[MAX_LINE - 1] = strdup(input);
    }
}

// Function to execute the command from history
void execute_from_history(char *history[], char *tokens[], int count)
{
    int index = atoi(tokens[1]);
    if (index > count)
    {
        printf("Command not in history\n");
    }
    else
    {
        char *input = strdup(history[index - 1]);
        char *tokens[MAX_TOKEN];
        parse(input, tokens);
        execute(tokens);
    }
}