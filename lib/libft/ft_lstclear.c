/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 19:56:57 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/09/28 20:28:11 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current_ele;
	t_list	*next_ele;

	current_ele = *lst;
	while (current_ele)
	{
		next_ele = current_ele->next;
		ft_lstdelone(current_ele, del);
		current_ele = next_ele;
	}
	*lst = NULL;
}
