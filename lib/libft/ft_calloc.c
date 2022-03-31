/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 17:04:09 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/09/13 14:42:57 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*mem;

	total_size = nmemb * size;
	mem = malloc(total_size);
	if (!mem)
		return (NULL);
	mem = ft_memset(mem, 0, total_size);
	return (mem);
}
