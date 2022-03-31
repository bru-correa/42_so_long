/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:45:10 by bcorrea-          #+#    #+#             */
/*   Updated: 2021/09/27 17:24:15 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*get_word(const char *s, char c, int *pos);
static char		*set_word(const char *src, char *dest, int start, int end);
static size_t	count_words(const char *s, char c);
static char		**init_words(const char *s, char c);

char	**ft_split(const char *s, char c)
{
	char	**words;
	char	**words_start;
	int		pos;

	words = init_words(s, c);
	if (!words)
		return (NULL);
	words_start = words;
	pos = 0;
	while (s[pos])
	{
		while (s[pos] && s[pos] == c)
			pos++;
		if (s[pos])
			*words++ = get_word(s, c, &pos);
	}
	*words = NULL;
	return (words_start);
}

static char	**init_words(const char *s, char c)
{
	size_t	wordn;
	char	**words;

	if (!s)
		return (NULL);
	wordn = count_words(s, c);
	words = malloc((wordn + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	return (words);
}

static size_t	count_words(const char *s, char c)
{
	size_t	counter;

	counter = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
			counter++;
		while (*s != c && *s)
			s++;
	}
	return (counter);
}

static char	*get_word(const char *s, char c, int *pos)
{
	int		start_pos;
	char	*output;

	start_pos = *pos;
	while (s[*pos] != c && s[*pos])
		*pos = *pos + 1;
	output = malloc((*pos - start_pos + 2) * (sizeof(char)));
	if (!output)
		return (NULL);
	set_word(s, output, start_pos, *pos - 1);
	return (output);
}

static char	*set_word(const char *src, char *dest, int start, int end)
{
	int	i;
	int	j;

	i = 0;
	j = start;
	while (j <= end)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}
