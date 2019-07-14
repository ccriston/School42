/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:35:51 by ccriston          #+#    #+#             */
/*   Updated: 2019/04/14 13:32:55 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static unsigned int		nm_word(char const *s, char c)
{
	unsigned int	is;
	unsigned int	j;

	is = 0;
	j = 0;
	while (s[is] != '\0')
	{
		while (s[is] == c)
			is++;
		if (s[is] != c && s[is] != '\0')
			j++;
		while (s[is] != c && s[is] != '\0')
			is++;
	}
	return (j);
}

static unsigned int		ft_wordlen(char const *s, char c, unsigned int is)
{
	unsigned int	len;

	len = 0;
	while (s[is] != c && s[is] != '\0')
	{
		len++;
		is++;
	}
	return (len);
}

static void				ft_free(char **str, unsigned int i)
{
	if (i > 1)
		while (--i > 0)
		{
			free((str[i]));
			str[i] = NULL;
		}
	free(str[0]);
	str[0] = NULL;
	free(str);
	str = NULL;
}

static char				**ft_str(char **str, char *s, char c, unsigned int j)
{
	unsigned int	i;
	unsigned int	is;
	unsigned int	k;

	is = 0;
	i = 0;
	while (i < j)
	{
		while (s[is] == c)
			is++;
		k = 0;
		if (!(str[i] = ft_strnew(ft_wordlen(s, c, is))))
		{
			ft_free(str, i);
			return (NULL);
		}
		while (s[is] != c && s[is] != '\0')
			str[i][k++] = s[is++];
		str[i][k] = '\0';
		if (s[is] == '\0')
			return (str);
		i++;
	}
	return (str);
}

char					**ft_strsplit(char const *s, char c)
{
	char			**str;
	unsigned int	j;

	if (!s)
		return (NULL);
	j = nm_word(s, c);
	if (!(str = (char **)ft_memalloc(sizeof(char *) * (j + 1))))
		return (NULL);
	return (ft_str(str, (char *)s, c, j));
}
