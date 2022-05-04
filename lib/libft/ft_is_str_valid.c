/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_str_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:16:04 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/04 15:16:11 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_str_valid(char *str, char *valid_chars)
{
	int	i;

	if (str == NULL || valid_chars == NULL)
		return (FALSE);
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_is_char_valid(str[i], valid_chars) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
