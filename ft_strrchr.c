/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasato- <lmasato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:47:11 by lmasato-          #+#    #+#             */
/*   Updated: 2022/06/20 16:13:53 by lmasato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	int				tmp;
	unsigned char	ch;

	ch = c;
	i = 0;
	tmp = -1;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			tmp = i;
		i++;
	}
	if (ch == 0)
		return ((char *)(&s[i]));
	if (tmp == -1)
		return (0);
	else
		return ((char *)(&s[tmp]));
}
