/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasato- <lmasato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:54:20 by lmasato-          #+#    #+#             */
/*   Updated: 2022/06/20 15:39:21 by lmasato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{	
	size_t			i;
	unsigned char	*p;
	unsigned char	ch;

	i = 0;
	ch = c;
	p = (unsigned char *) s;
	while (i < n)
	{
		if (p[i] == ch)
			return ((void *)(&p[i]));
		i++;
	}
	return (0);
}
