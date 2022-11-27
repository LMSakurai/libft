/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasato- <lmasato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:26:26 by lmasato-          #+#    #+#             */
/*   Updated: 2022/06/20 16:15:05 by lmasato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in_set(char c, char const *set);
static int	ft_start_index(char const *s1, char const *set);
static int	ft_end_index(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{	
	int		i;
	int		len;
	int		start;
	int		end;
	char	*p;

	i = 0;
	start = ft_start_index(s1, set);
	end = ft_end_index(s1, set);
	if (start == -1)
	{
		p = malloc (sizeof(char));
		p[0] = '\0';
		return (p);
	}
	len = end - start + 1;
	p = malloc(sizeof(char) * (len + 1));
	while (i < len)
	{	
		p[i] = s1[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}

static int	ft_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{	
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_start_index(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{	
		if (!ft_in_set(s1[i], set))
		{	
			return (i);
		}	
		i++;
	}
	return (-1);
}

static int	ft_end_index(char const *s1, char const *set)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = -1;
	while (s1[i] != '\0')
	{	
		if (!ft_in_set(s1[i], set))
		{	
			tmp = i;
		}	
		i++;
	}
	return (tmp);
}
