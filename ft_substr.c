/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasato- <lmasato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:24:20 by lmasato-          #+#    #+#             */
/*   Updated: 2022/06/20 16:16:04 by lmasato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{	
	size_t	i;
	size_t	size;
	char	*p;

	i = 0;
	size = 0;
	if (start < ft_strlen(s))
		size = ft_strlen(&s[start]);
	if (len < size)
		size = len;
	p = malloc(sizeof(char) * (size + 1));
	while (i < size)
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}
