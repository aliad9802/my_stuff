/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** strtwa.c
*/

#include "../include/my.h"

static int is_sep(char c, char *sep)
{
    for (int k = 0; sep[k]; k++) {
        if (sep[k] == c)
            return (-1);
    }
    return (0);
}

static int sizewrd(char *string, int k, char *sep)
{
    int	lngth = 1;

    for (;string[k] && is_sep(string[k], sep) == 0; k++) {
        lngth++;
    }
    lngth--;
    return (lngth);
}

static int aslong_sep(char *sep, int k, char const *string)
{
    if (-1 == is_sep(string[k], sep)) {
        for (;-1 == is_sep(string[k], sep);k++)
        k = k - 1;
    }
    return (k);
}

static int wrdcntr(char const *string, char *sep)
{
    int	tot = 1;

    for (int k = 0; string[k]; k++) {
        tot += 1;
        k = aslong_sep(sep, k, string);
    }
    return (tot);
}

char **strtwa(char *string, char *sep) {
    int wordCount = wrdcntr(string, sep);
    int wordSize;
    char **result = (char **)malloc((wordCount + 1) * sizeof(char *));

    int k = 0;
    for (int i = 0; i < wordCount; i++) {
        k = aslong_sep(sep, k, string);
        wordSize = sizewrd(string, k, sep);
        result[i] = (char *)malloc((wordSize + 1) * sizeof(char));
        for (int j = 0; j < wordSize; j++)
            result[i][j] = string[k++];
        result[i][wordSize] = '\0';
    }
    result[wordCount] = NULL;
    return result;
}

// char **strtwa(char *string, char *sep)
// {
//     int	i = 0;
//     int	j = 0;
//     int	nw = wrdcntr(string, sep) + 2 + 1;
//     char **array = malloc(sizeof(char*) * nw);

//     for (int k = 0; string[k];) {
//         j = 0;
//         for (; (string[k] && is_sep(string[k], sep) == -1); k++);
//         array[i] = malloc(sizeof(char) * (sizewrd(string, k, sep) + 1));
//         for (; (string[k] && is_sep(string[k], sep) == 0); k++ , j++)
//             array[i][j] = string[k];
//         array[i][j] = '\0';
//         for (; (string[k] && is_sep(string[k], sep) == -1); k++);
//         i++;
//     }
//     array[i] = NULL;
//     return (array);
// }

