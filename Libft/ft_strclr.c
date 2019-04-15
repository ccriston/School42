/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:12:26 by ccriston          #+#    #+#             */
/*   Updated: 2019/04/12 15:59:30 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strclr(char *s)
{
	char *p;

	if (s && *s)
	{
		p = s;
		while (p && *p)
			*p++ = '\0';
	}
}
