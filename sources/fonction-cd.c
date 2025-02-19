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


void cd(char *tokens[])
{
    if (tokens[1] == NULL)
    {
        printf("cd: missing argument\n");
    }
    else
    {
        if (!SetCurrentDirectory(tokens[1]))
        {
            printf("cd: %s: No such file or directory\n", tokens[1]);
        }
    }
}

void cd_home()
{
    char *home = getenv("HOME");
    if (home == NULL)
    {
        printf("cd: HOME not set\n");
    }
    else
    {
        if (!SetCurrentDirectory(home))
        {
            printf("cd: %s: No such file or directory\n", home);
        }
    }
}

void cd_back()
{
    char path[MAX_PATH];
    GetCurrentDirectory(MAX_PATH, path);
    char *last_slash = strrchr(path, '\\');
    if (last_slash == path)
    {
        last_slash++;
    }
    *last_slash = '\0';
    if (!SetCurrentDirectory(path))
    {
        printf("cd: %s: No such file or directory\n", path);
    }
}

void cd_root()
{
    if (!SetCurrentDirectory("C:\\"))
    {
        printf("cd: C:\\: No such file or directory\n");
    }
}

