/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:53:43 by ccriston          #+#    #+#             */
/*   Updated: 2019/04/13 19:18:27 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t ind_str;
	size_t ind_f;

	ind_str = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[ind_str] != '\0')
	{
		ind_f = 0;
		while (needle[ind_f] == haystack[ind_str + ind_f]
		&& (ind_str + ind_f) < len)
		{
			if (needle[ind_f + 1] == '\0')
				return ((char *)(haystack + ind_str));
			ind_f = ind_f + 1;
		}
		ind_str = ind_str + 1;
	}
	return (NULL);
}
