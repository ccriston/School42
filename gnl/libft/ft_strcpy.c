/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 13:10:12 by ccriston          #+#    #+#             */
/*   Updated: 2019/04/05 14:52:49 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *str)
{
	int index;

	index = 0;
	while (str[index] != '\0')
	{
		dst[index] = str[index];
		index++;
	}
	dst[index] = '\0';
	return (dst);
}
