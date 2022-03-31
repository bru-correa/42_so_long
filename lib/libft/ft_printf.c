/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:17:24 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/03/31 01:04:35 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_flags(const char *input, va_list args);
static int	print(const char *input, va_list args, int length);

int	ft_printf(const char *input, ...)
{
	int			length;
	va_list		args;

	length = 0;
	va_start(args, input);
	length = print(input, args, length);
	va_end(args);
	return (length);
}

static int	print(const char *input, va_list args, int length)
{
	length = 0;
	while (*input != '\0')
	{
		if (*input == '%' && ft_strchr("cspudixX%", *(input + 1)))
		{
			input++;
			length += handle_flags(input, args);
		}
		else
		{
			if (*input == '\\' && ft_strchr((input + 1), '%'))
			{
				length += write(1, input, 2);
				input++;
			}
			else
				length += write(1, input, 1);
		}
		input++;
	}
	return (length);
}

static int	handle_flags(const char *input, va_list args)
{
	int	length;

	if (*input == 'c')
		length = print_char(va_arg(args, int));
	else if (*input == 's')
		length = print_string(va_arg(args, char *));
	else if (*input == 'd' || *input == 'i')
		length = print_decimal(va_arg(args, int));
	else if (*input == 'u')
		length = print_decimal(va_arg(args, unsigned int));
	else if (*input == 'x' || *input == 'X')
		length = print_hexadecimal(va_arg(args, unsigned int), *input);
	else if (*input == 'p')
		length = print_pointer(va_arg(args, void *));
	else
	{
		ft_putchar_fd('%', 1);
		length = 1;
	}
	return (length);
}
