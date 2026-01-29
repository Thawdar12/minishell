/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tswe-zin@student.42singapore.sg <tswe-z    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 00:43:07 by tswe-zin@st       #+#    #+#             */
/*   Updated: 2025/09/22 20:47:28 by tswe-zin@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
		{
			in_word = 0;
		}
		s++;
	}
	return (count);
}

static char	*copy_word(const char *s, int len)
{
	char	*word;
	int		i;

	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	add_word(char **result, const char *start_ptr, int len, int word_i)
{
	result[word_i] = copy_word(start_ptr, len);
	if (!result[word_i])
	{
		while (word_i > 0)
		{
			free(result[word_i - 1]);
			word_i--;
		}
		result[0] = NULL;
		free(result);
		return (0);
	}
	return (1);
}

static void	split_words(char **result, const char *s, char c)
{
	int			i;
	int			j;
	int			len;
	const char	*word_start;

	i = 0;
	j = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		word_start = s + i;
		while (s[i] && s[i] != c)
			i++;
		len = s + i - word_start;
		if (len > 0)
		{
			if (!add_word(result, word_start, len, j))
				return ;
			j++;
		}
	}
	result[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!result)
		return (NULL);
	split_words(result, s, c);
	return (result);
}
