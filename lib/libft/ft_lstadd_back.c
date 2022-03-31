/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 19:17:21 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/09/28 19:31:30 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ele;

	ele = *lst;
	while (ele)
	{
		if (ele->next)
			ele = ele->next;
		else
		{
			ele->next = new;
			return ;
		}
	}
	*lst = new;
}
