/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:47:14 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/09/22 13:18:27 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*output;
	unsigned int	i;

	if (!s)
		return (NULL);
	output = ft_strdup(s);
	if (!output)
		return (NULL);
	i = 0;
	while (output[i])
	{
		output[i] = f(i, output[i]);
		i++;
	}
	output[i] = '\0';
	return (output);
}
