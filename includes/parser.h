#ifndef __PARSER_H__
#define __PARSER_H__

struct parser
{
    char *input;
    char *tokens[100];
    char *history[100];
    int count;
};


void parse(char *input, char *tokens[]);
void read_input(char *input);
void execute(char *tokens[]);
void print_prompt();
void print_history(char *history[], int count);
void add_history(char *history[], char *input, int *count);
void execute_from_history(char *history[], char *tokens[], int count);


#endif // __PARSER_H__