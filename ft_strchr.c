/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasato- <lmasato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:04:33 by lmasato-          #+#    #+#             */
/*   Updated: 2022/06/20 15:47:03 by lmasato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{	
	int				i;
	unsigned char	ch;

	ch = c;
	i = 0;
	while (s[i] != '\0')
	{	
		if (s[i] == ch)
			return ((char *)(&s[i]));
		i++;
	}
	if (ch == 0)
		return ((char *)(&s[i]));
	return (0);
}
