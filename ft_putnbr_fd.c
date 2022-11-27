/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasato- <lmasato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:00:33 by lmasato-          #+#    #+#             */
/*   Updated: 2022/06/20 15:42:56 by lmasato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstring(char v[], int count, int fd);
void	ft_putnumbers(int nb, int fd);

void	ft_putnbr_fd(int nb, int fd)
{	
	if (nb == -2147483648)
		write(fd, "-2147483648", 11);
	else if (nb < 0)
	{	
		ft_putchar_fd('-', fd);
		nb = nb * (-1);
		ft_putnumbers(nb, fd);
	}
	else if (nb == 0)
		ft_putchar_fd('0', fd);
	else
		ft_putnumbers(nb, fd);
}

void	ft_putstring(char v[], int count, int fd)
{	
	int	i;

	i = 0;
	while (count >= i)
	{
		write(fd, &v[count], 1);
		count--;
	}
}

void	ft_putnumbers(int nb, int fd)
{
	char	v[10];
	int		count;
	int		c;

	count = 0;
	while (nb > 0)
	{
		c = (nb % 10) + '0';
		nb = nb / 10;
		v[count] = c;
		count++;
	}
	ft_putstring(v, count - 1, fd);
}
