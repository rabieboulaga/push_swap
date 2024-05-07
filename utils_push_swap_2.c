/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push_swap_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 00:28:06 by rboulaga          #+#    #+#             */
/*   Updated: 2024/05/06 18:21:36 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


long long	ft_atoi(const char *str)
{
	int	i;
	long long	res;
	int	s;

	i = 0;
	res = 0;
	s = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res * s);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	newstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!newstr)
		return (NULL);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		newstr[i] = s2[j];
		j++;
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*string;

	len = ft_strlen(s);
	i = 0;
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

char	*ft_substr(char const *string, unsigned int start, size_t len)
{
	char			*str1;
	unsigned int	j;
	unsigned int	i;

	j = 0;
	i = start;
	if (!string)
		return (NULL);
	if (start >= ft_strlen(string))
		return (ft_strdup(""));
	if (len > ft_strlen(string) - start)
		len = (ft_strlen(string) - start);
	str1 = malloc(sizeof(char) * (len + 1));
	if (!str1)
		return (NULL);
	while (string[i] && i < len + start)
		str1[j++] = string[i++];
	str1[j] = 0;
	return (str1);
}


