#include "../../include/minishell.h"

char *extract_word(char *str, int *i)
{
    int start;
    start = *i;
	while (str[*i]
		&& str[*i] != ' '
		&& !is_operator(str[*i])
		&& str[*i] != '\''
		&& str[*i] != '"')
		(*i)++;

	return (ft_substr(str, start, *i - start));
}

char	*extract_single_quote(char *str, int *i)
{
	int	start;

	(*i)++;
	start = *i;

	while (str[*i] && str[*i] != '\'')
		(*i)++;

	if (!str[*i])
		return (NULL);

	char *word = ft_substr(str, start, *i - start);
	(*i)++;
	return (word);
}

char	*extract_double_quote(char *str, int *i)
{
	int	start;

	(*i)++; // skip the open quote
	start = *i; // mark the start

	while (str[*i] && str[*i] != '"') // scan until close  quote
		(*i)++;

	if (!str[*i]) // if end of string reached without closing quote
		return (NULL);

	char *word = ft_substr(str, start, *i - start); // extract word
	(*i)++; // skip the close quote
	return (word);
}

char	*extract_full_word(char *str, int *i)
{
	char	*result;
	char	*tmp;
	char	*part;

	result = ft_strdup("");

	while (str[*i] && str[*i] != ' ' && !is_operator(str[*i]))
	{
		if (str[*i] == '\'')
			part = extract_single_quote(str, i);
		else if (str[*i] == '"')
			part = extract_double_quote(str, i);
		else
			part = extract_word(str, i);

		if (!part)
			return (NULL);

		tmp = result;
		result = ft_strjoin(tmp, part);
		free(tmp);
		free(part);
	}
	return (result);
}

