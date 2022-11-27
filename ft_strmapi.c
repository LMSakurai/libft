/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasato- <lmasato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:36:19 by lmasato-          #+#    #+#             */
/*   Updated: 2022/06/10 18:37:36 by lmasato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*p;

	i = 0;
	p = malloc(sizeof(char) * (ft_strlen(s) + 1));
	while (s[i] != '\0')
	{	
		p[i] = f(i, s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}
