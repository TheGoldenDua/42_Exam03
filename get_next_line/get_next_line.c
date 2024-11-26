#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

int ft_strlen(const char *str)
{
    int i = 0;

    while(str[i])
        i++;
    return (i);
}

char *ft_strchr(char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
            return (s);
        s++;
    }
    return (NULL);
}

void ft_strcpy(char *dest, const char *src)
{
    int i = 0;

    while(src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

char *ft_strdup(const char *str)
{
    char *res;
    int len = ft_strlen(str) + 1;

    res = malloc(len);
    if(!res)
        return (NULL);
    ft_strcpy(res, str);
    return (res);
}

char *ft_strjoin(char *s1, char *s2)
{
    char *res;

    if(!s1 || !s2)
        return (NULL);
    res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if(!res)
        return (NULL);
    ft_strcpy(res, s1);
    ft_strcpy(res + ft_strlen(s1), s2);
    free(s1);
    return (res);
}

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    char *line;
    char *new_line;
    int count;

    line = ft_strdup(buffer);
    while(!(new_line =  ft_strchr(line,'\n')) && (count = read(fd, buffer, BUFFER_SIZE)))
    {
        buffer[count] = '\0';
        line = ft_strjoin(line, buffer);
    }
    if(ft_strlen(line) == 0)
        return(free(line), NULL);
    if(new_line)
    {
        ft_strcpy(buffer, new_line + 1);
        *(new_line + 1) = '\0';
    }
    else
        buffer[0] = '\0';
    return (line);
}