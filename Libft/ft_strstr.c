/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 19:07:00 by ccriston          #+#    #+#             */
/*   Updated: 2019/04/14 11:52:22 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int ind_str;
	int ind_f;

	ind_str = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[ind_str] != '\0')
	{
		ind_f = 0;
		while (needle[ind_f] == haystack[ind_str + ind_f])
		{
			if (needle[ind_f + 1] == '\0')
				return ((char *)(haystack + ind_str));
			ind_f = ind_f + 1;
		}
		ind_str = ind_str + 1;
	}
	return (NULL);
}
