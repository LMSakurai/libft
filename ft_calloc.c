/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasato- <lmasato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:49:58 by lmasato-          #+#    #+#             */
/*   Updated: 2022/06/20 15:28:05 by lmasato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{	
	size_t	i;
	void	*p;
	char	*c;

	i = 0;
	if ((nmemb != 0) && (((nmemb * size) / nmemb) != size))
		return (NULL);
	p = malloc(size * nmemb);
	c = p;
	while (i < (nmemb * size))
	{	
		c[i] = '\0';
		i++;
	}
	return (p);
}	
