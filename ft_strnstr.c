/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasato- <lmasato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:11:15 by lmasato-          #+#    #+#             */
/*   Updated: 2022/06/21 14:30:05 by lmasato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		llen;
	int		j;
	int		c;

	j = 0;
	i = 0;
	llen = ft_strlen(little);
	if (((char *)little)[0] == '\0')
		return ((char *)big);
	if (((char *)big)[0] == '\0')
		return (NULL);
	while (i < len)
	{
		while ((j < llen) && (i + llen - 1 < len))
		{
			c = ft_strncmp(&((char *) big)[i], &((char *) little)[j], llen);
			if (c == 0)
				return (&((char *)big)[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
