/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasato- <lmasato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:02:34 by lmasato-          #+#    #+#             */
/*   Updated: 2022/06/23 13:28:07 by lmasato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_num(char *s, char c);
static char	*ft_word_alloc(char **m, size_t index, char *s, char c);
static void	ft_free_split(char **m, size_t index);

char	**ft_split(char const *s, char c)
{	
	size_t		i;
	size_t		wnum;
	char		**m;

	i = 0;
	wnum = ft_word_num((char *)s, c);
	if (s[0] == 0)
		wnum = 0;
	m = malloc(sizeof(char *) * (wnum + 1));
	if (m == NULL)
		return (NULL);
	while (i < wnum)
	{	
		s = ft_word_alloc(m, i, (char *)s, c);
		if (m[i] == NULL)
		{	
			ft_free_split(m, i);
			return (NULL);
		}
		i++;
	}
	m[i] = NULL;
	return (m);
}

static int	ft_word_num(char *s, char c)
{
	size_t	count;
	size_t	i;

	i = 1;
	count = 0;
	if (c == 0)
		return (1);
	if (s[0] != c)
		count++;
	while (s[i] != '\0')
	{	
		if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

static char	*ft_word_alloc(char **m, size_t index, char *s, char c)
{
	size_t	i;
	size_t	j;
	char	*p;

	i = 0;
	j = 0;
	while (s[0] == c)
		s++;
	while (!((s[i + 1] == '\0') || (s[i] != c && s[i + 1] == c)))
		i++;
	p = malloc(sizeof(char) * (i + 2));
	if (p == NULL)
		return (NULL);
	while (j <= i)
	{
		p[j] = s[j];
		j++;
	}
	p[j] = '\0';
	m[index] = &p[0];
	return (&s[j + 1]);
}

static void	ft_free_split(char **m, size_t index)
{
	while (index != 0)
	{	
		free(m[index]);
		index--;
	}
	free(m[0]);
	free(m);
}
