#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "input.h"
#include "parser.h"
#include "process.h"
#include "builtin.h"
#include "signals.h"
#include "pipes.h"
#include "redirect.h"

static void tokenize(char *str, char **argv)
{
    int i = 0;
    char *token = strtok(str, " \t\n");
    while (token != NULL && i < 63)
    {
        argv[i++] = token;
        token = strtok(NULL, " \t\n");
    }
    argv[i] = NULL;
}

int main(void)
{
    char *line;
    char **tokens;

    initialize_signals();

    printf("=====================================\n");
    printf("%s Version %s\n", SHELL_NAME, VERSION);
    printf("=====================================\n");

    while (1)
    {
        printf("myshell> ");
        line = read_line();

        if (line == NULL)
            break;

        if (strcmp(line, "exit") == 0)
        {
            free(line);
            break;
        }

        if (strchr(line, '|') != NULL)
        {
            char *argv1[64];
            char *argv2[64];
            char *left = strtok(line, "|");
            char *right = strtok(NULL, "|");

            if (left == NULL || right == NULL)
            {
                printf("Invalid pipe command\n");
            }
            else
            {
                tokenize(left, argv1);
                tokenize(right, argv2);
                if (argv1[0] != NULL && argv2[0] != NULL)
                {
                    execute_pipe(argv1, argv2);
                }
                else
                {
                    printf("Invalid pipe command\n");
                }
            }
        }
        else
        {
            tokens = parse_line(line);
            if (tokens[0] != NULL)
            {
                if (execute_builtin(tokens) == 0)
                {
                    if (execute_redirection(tokens) == 0)
                    {
                        execute(tokens);
                    }
                }
            }
            free_tokens(tokens);
        }

        free(line);
    }

    printf("Goodbye!\n");
    return 0;
}
