/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:46:44 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/03/31 01:08:55 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digits(long int n)
{
	int					count;
	unsigned long int	digits;

	if (n == 0)
		return (1);
	else if (n > 0)
	{
		digits = n;
		count = 0;
	}
	else
	{
		digits = n * -1;
		count = 1;
	}
	while (digits > 0)
	{
		digits /= 10;
		count++;
	}
	return (count);
}

char	*ft_litoa(long int n)
{
	char			*result;
	int				length;
	unsigned int	number;

	length = count_digits(n);
	result = malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	result[length--] = '\0';
	if (n == 0)
		result[0] = '0';
	if (n < 0)
	{
		number = n * -1;
		result[0] = '-';
	}
	else
		number = n;
	while (number > 0)
	{
		result[length--] = '0' + (number % 10);
		number = number / 10;
	}
	return (result);
}
