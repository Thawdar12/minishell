#include "../../include/minishell.h"

t_token	*lexer(char *input)
{
	int i;
	t_token *list;
	t_token *new_lst;

	i = 0;
	list = NULL;
	while (input[i])
	{
		if (input[i] == ' ' || input[i] == '\t')
			i++;
		else if (is_operator(input[i]))
		{
			new_lst = handle_operator(input, &i);
			if (!new_lst)
				return (NULL);
			token_add_back(&list, new_lst);
		}
		else
		{
			char *word = extract_full_word(input, &i);
			if (!word)
				return (NULL);
			new_lst = new_lst_token(word, T_WORD);
			token_add_back(&list, new_lst);
		}
	}
	return (list);
}
