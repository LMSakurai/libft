/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasato- <lmasato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:52:38 by lmasato-          #+#    #+#             */
/*   Updated: 2022/06/20 15:35:19 by lmasato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_len(int n);
static void	ft_int_to_string(int n, char *p);
static char	*ft_edge_cases(int n);

char	*ft_itoa(int n)
{	
	char	*p;
	int		sign;

	sign = 0;
	if (n == 0)
		return (ft_edge_cases(0));
	if (n == -2147483648)
		return (ft_edge_cases(n));
	if (n < 0)
	{	
		sign = 1;
		n = n * (-1);
	}
	p = malloc(sizeof(char) * (ft_int_len(n) + 1 + sign));
	if (sign == 1)
	{
		p[0] = '-';
		ft_int_to_string(n, &p[1]);
	}
	else
		ft_int_to_string(n, p);
	return (p);
}

static int	ft_int_len(int n)
{	
	int	count;

	count = 0;
	if (n < 0)
		n = n * (-1);
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	ft_int_to_string(int n, char *p)
{	
	int	r;
	int	i;
	int	size;

	size = ft_int_len(n) - 1;
	i = size;
	while (n > 0)
	{	
		r = n % 10;
		n = n / 10;
		p[i] = r + '0';
		i--;
	}
	p[size + 1] = '\0';
}

static char	*ft_edge_cases(int n)
{	
	char	*p;

	if (n == 0)
	{
		p = malloc(sizeof(char) * 2);
		p[0] = '0';
		p[1] = '\0';
	}
	else
	{
		p = malloc(sizeof(char) * (10 + 1 + 1));
		p[0] = '-';
		p[1] = '2';
		ft_int_to_string(147483648, &p[2]);
	}
	return (p);
}
