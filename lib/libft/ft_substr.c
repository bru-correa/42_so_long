/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 21:28:24 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/09/29 21:26:45 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(const char *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*substr_start;
	size_t	size;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		size = 0;
	else
		size = get_size(s, start, len);
	substr = malloc((size + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	substr_start = substr;
	while (size > 0)
	{
		*substr = s[start];
		size--;
		start++;
		substr++;
	}
	*substr = '\0';
	return (substr_start);
}

static size_t	get_size(const char *s, unsigned int start, size_t len)
{
	size_t	size;

	size = 0;
	while (s[size + start] && size < len)
		size++;
	return (size);
}
