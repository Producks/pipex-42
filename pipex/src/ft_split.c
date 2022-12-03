/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:05:15 by ddemers           #+#    #+#             */
/*   Updated: 2022/11/28 13:25:04 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static char    *ft_special(const char *str, unsigned int start, s_split *a)
{
    int    i;
    int    y;
    char    *temp;

    i = start + 1;
    while (str[i] != 39 && str[i] != '\0' && str[i] != '\"')
        i++;
    y = (i - (start - 1));
    a->check_sep = 69;
    temp = ft_substr(str, start, y);
    a->i += ft_strlen(temp);
    a->ptr[a->nmbcount] = ft_strtrim(temp, "'\"");
    free(temp);
    return (a->ptr[a->nmbcount]);
}

static char    **ft_free_mem(char **ptr)
{
    int    i;

    i = 0;
    while (ptr[i])
    {
        free(ptr[i]);
        i++;
    }
    free (ptr);
    return (NULL);
}

static int    ft_length(char const *s, char c, int i)
{
    int    length;

    length = 0;
    while (s[i] != c && s[i])
    {
        length++;
        i++;
    }
    return (length);
}

static    char    **get_size(char const *s, char c, s_split *a)
{
    a->word_count = 1;
    while (*s)
    {
        while (*s == c)
            ++s;
        if (*s)
            ++a->word_count;
        if (*s == 39 || *s == '\"')
        {
            s++;
            while (*s != 39 && *s != '\0' && *s != '\"')
                s++;
            if (*s == 39 || *s == '\0' || *s == '\"')
                s++;
        }
        while (*s && *s != c)
            ++s;
    }
    a->str = (char **)malloc(sizeof(char *) * a->word_count);
    if (!a->str)
        return (NULL);
    a->str[a->word_count - 1] = NULL;
    return (a->str);
}

char    **ft_split(char const *s, char c)
{
    s_split    a;

    if (!s)
        return (NULL);
    a.ptr = get_size(s, c, &a);
    a.i = -1;
    a.nmbcount = 0;
    a.check_sep = 0;
    while (a.ptr && s[++a.i])
    {
        if (s[a.i] == c)
            a.check_sep = 0;
        if (s[a.i] == 39 || s[a.i] == '\"')
            a.ptr[a.nmbcount++] = ft_special(s, a.i, &a);
        if (s[a.i] != c && a.check_sep++ == 0)
        {
            a.ptr[a.nmbcount] = ft_substr(s, a.i, ft_length(s, c, a.i));
            if (a.ptr[a.nmbcount++] == NULL)
                return (ft_free_mem(a.ptr));
        }
    }
    return (a.ptr);
}
