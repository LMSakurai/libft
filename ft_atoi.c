/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasato- <lmasato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:43:54 by lmasato-          #+#    #+#             */
/*   Updated: 2022/06/13 19:57:28 by lmasato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_handler(char c);

int	ft_atoi(const char *nptr)
{	
	int		i;
	int		n;
	int		signal;
	char	*p;

	i = 0;
	n = 0;
	p = (char *) nptr;
	while ((p[i] == 32) || (p[i] >= 9 && p[i] <= 13))
		i++;
	signal = ft_handler(p[i]);
	if (ft_isdigit(p[i]))
		n = p[i] - 48;
	i++;
	while (ft_isdigit(p[i]))
	{	
		n = n * 10 + (p[i] - 48);
		i++;
	}
	n = n * signal;
	return (n);
}

static int	ft_handler(char c)
{
	if (c == '+' || ft_isdigit(c))
		return (1);
	if (c == '-')
		return (-1);
	return (0);
}
