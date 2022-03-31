/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:25:39 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/09/13 17:27:35 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*output;
	size_t	size;
	char	*output_start;

	if (!s1 || !s2)
		return (NULL);
	size = (ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char);
	output = (char *)malloc(size);
	if (!output)
		return (NULL);
	output_start = output;
	while (*s1)
		*output++ = *s1++;
	while (*s2)
		*output++ = *s2++;
	*output = '\0';
	return (output_start);
}
