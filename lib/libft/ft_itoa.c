/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:44:17 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/09/22 18:46:06 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		nlen(int n);
static void			to_str(char *str, unsigned int n, size_t len);
static unsigned int	to_positive(int n);

char	*ft_itoa(int n)
{
	char			*output;
	size_t			len;
	unsigned int	un;

	len = nlen(n);
	output = (char *)malloc(len + 1);
	if (!output)
		return (NULL);
	if (n < 0)
	{
		*output = '-';
		un = to_positive(n);
		to_str(output + 1, un, len - 1);
	}
	else
	{
		un = to_positive(n);
		to_str(output, un, len);
	}
	return (output);
}

static size_t	nlen(int n)
{
	size_t	len;
	size_t	sign;

	if (n == 0)
		return (1);
	if (n >= 0)
		sign = 0;
	else
		sign = 1;
	len = 0;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len + sign);
}

static void	to_str(char *str, unsigned int n, size_t len)
{
	size_t	i;

	i = len - 1;
	while (i + 1)
	{
		str[i--] = (n % 10) + '0';
		n = n / 10;
	}
	str[len] = '\0';
}

static unsigned int	to_positive(int n)
{
	if (n >= 0)
		return ((unsigned int) n);
	return ((unsigned int)(n * -1));
}
