/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:32:46 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/09/16 14:42:06 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	length;

	length = ft_strlen(src);
	if (size > 0)
	{
		while ((*src != '\0') && (size-- - 1))
			*dest++ = *src++;
		*dest = '\0';
	}
	return (length);
}
