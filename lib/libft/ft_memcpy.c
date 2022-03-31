/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 02:14:42 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/09/07 02:14:55 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*dest_start;

	dest_start = dest;
	if (src == NULL && dest == NULL)
		return (dest);
	while (n--)
		*(unsigned char *) dest++ = *(unsigned char *) src++;
	return (dest_start);
}
