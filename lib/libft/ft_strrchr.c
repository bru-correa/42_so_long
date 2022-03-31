/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:54:50 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/09/09 16:05:46 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	if (c > 127)
		c %= 256;
	len = ft_strlen(s);
	if (s[len] == c)
		return ((char *) &s[len]);
	while (len + 1)
	{
		if (s[len] == c)
			return ((char *) &s[len]);
		len--;
	}
	return (NULL);
}
