/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 23:40:42 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/09/05 15:08:15 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	void	*dest_start;

	dest_start = dest;
	while (len-- > 0)
		*(unsigned char *) dest++ = (unsigned char) c;
	return (dest_start);
}
