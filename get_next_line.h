/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:01:17 by rboulaga          #+#    #+#             */
/*   Updated: 2024/05/07 13:13:08 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10

# endif

char	*get_next_line(int fd);
char	*read_for_me(char *reminder, int fd, char *buff);
size_t	ft_strlenn(char *str);
char	*ft_strjoinn(char *s1, char *s2);
char	*ft_strdupp(char *s);
char	*ft_strchrr(char *s, int c);
char	*leftside(char *reminder);
char	*rightside(char *reminder);

#endif
