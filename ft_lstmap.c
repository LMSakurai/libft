/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasato- <lmasato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:58:45 by lmasato-          #+#    #+#             */
/*   Updated: 2022/06/22 17:08:13 by lmasato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{	
	t_list	*l;
	t_list	*p;
	t_list	*aux;

	l = NULL;
	if (lst != NULL)
	{	
		l = ft_lstnew(f(lst->content));
		l->next = NULL;
		aux = l;
	}
	while (lst != NULL)
	{	
		lst = lst->next;
		if (lst == NULL)
			return (l);
		p = ft_lstnew(f(lst->content));
		if (p == NULL)
			ft_lstclear(&l, del);
		aux->next = p;
		aux = p;
	}
	return (l);
}
