/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:08:10 by ddemers           #+#    #+#             */
/*   Updated: 2022/12/02 17:31:10 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static char	*ft_strchr(const char *str, int c)
{
	char	ch;

	if (!str)
		return (NULL);
	ch = c;
	while (*str != '\0')
	{
		if (*str == ch)
			return ((char *) str);
		str++;
	}
	if (ch == '\0')
		return ((char *) str);
	return (NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	ending;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	ending = ft_strlen(s1) - 1;
	while (*s1 && ft_strchr(set, s1[ending]))
		ending--;
	return (ft_substr(s1, 0, ending + 1));
}
