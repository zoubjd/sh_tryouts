#include "shell.h"

char *make_env(char *path)
{
    char *p, *value, *last, *key;
    int i = 0;

    while (environ[i] != NULL)
    {
        p = _strdup(environ[i]);
        last = strtok(p, "=");
        if (_strcmp(last, path) == 0)
        {
            value = strtok(NULL, "\n");
            key = _strdup(value);
            free(p);
            return (key);
        }
        free(p);
        i++;
    }
    return (NULL);
}

char *make_path(char *path)
{
    char *pe = make_env("PATH"), *fullcmd, *storage;
    int i = 0;
    struct stat st;

    while (path[i] != '\0')
    {
        if (path[i] == '/')
        {
            if (stat(path, &st) == 0)
                return (_strdup(path));
            else
                return (NULL);
        }
        i++;
    }
    if (pe == NULL)
    {
        return (NULL);
    }
    storage = strtok(pe, ":");
    while (storage != NULL)
    {
        fullcmd = malloc(_strlen(path) + _strlen(storage) + 1);
        if (fullcmd != NULL)
        {
            _strcpy(fullcmd, storage);
            _strcat(fullcmd, "/");
            free(be)
            _strcat(fullcmd, path);
            if (stat(fullcmd, &st) == 0)
            {
                free(pe);
                return (fullcmd);
            }
            else
            {
                free(fullcmd);
            }
            storage = strtok(NULL, ":");
        }
    }
    free(pe);
    return (NULL);
}
