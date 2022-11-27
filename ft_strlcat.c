/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasato- <lmasato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:07:52 by lmasato-          #+#    #+#             */
/*   Updated: 2022/06/20 15:49:33 by lmasato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_with_limit(char *dst, size_t size);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	slen;
	size_t	add;

	slen = ft_strlen(src);
	dlen = ft_strlen_with_limit(dst, size);
	add = size - dlen - 1;
	j = 0;
	i = dlen;
	if (dlen < size)
	{	
		while ((j < add) && (src[j] != '\0'))
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	return (dlen + slen);
}

static int	ft_strlen_with_limit(char *dst, size_t size)
{
	size_t	i;

	i = 0;
	while ((dst[i] != '\0') && (i < size))
		i++;
	return (i);
}
