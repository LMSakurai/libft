/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasato- <lmasato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:57:13 by lmasato-          #+#    #+#             */
/*   Updated: 2022/06/22 17:11:33 by lmasato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{	
	t_list	*tmp;
	t_list	*aux;

	tmp = *lst;
	aux = tmp;
	while (aux != NULL)
	{	
		aux = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = aux;
	}
	*lst = NULL;
}
