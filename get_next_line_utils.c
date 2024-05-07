/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 01:17:13 by rabia             #+#    #+#             */
/*   Updated: 2024/05/07 10:18:56 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*ft_strdupp(char *s)
{
	size_t	len;
	size_t	i;
	char	*string;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlenn(s);
	string = (char *)malloc(sizeof(char) * (len + 1));
	if (string == NULL)
		return (NULL);
	while (s[i])
	{
		string[i] = s[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

size_t	ft_strlenn(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strchrr(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoinn(char *s1, char *s2)
{
	char	*newstr;
	int		i;
	int		j;

	j = 0;
	newstr = (char *)malloc(sizeof(char) * (ft_strlenn(s1) + ft_strlenn(s2) + 1));
	if (!newstr)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
		newstr[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		newstr[j++] = s2[i++];
	newstr[j] = '\0';
	free(s1);
	return (newstr);
}
