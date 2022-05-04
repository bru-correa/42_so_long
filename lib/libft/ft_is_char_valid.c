/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_char_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:14:16 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/04 15:14:47 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_char_valid(char c, char *valid_chars)
{
	int	i;

	if (valid_chars == NULL)
		return (FALSE);
	i = 0;
	while (valid_chars[i] != 0)
	{
		if (c == valid_chars[i])
			return (TRUE);
		i++;
	}
	return (FALSE);
}
