/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:53:01 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/03/31 01:08:00 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_decimal(long int decimal)
{
	char	*printable_number;
	int		digits_count;

	printable_number = ft_litoa(decimal);
	digits_count = ft_strlen(printable_number);
	ft_putstr_fd(printable_number, 1);
	free(printable_number);
	return (digits_count);
}
