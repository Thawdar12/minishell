#include "../../include/minishell.h"

int	is_operator(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

t_token	*handle_operator(char *str, int *i)
{
	if (str[*i] == '>' && str[*i + 1] == '>')
	{
		*i += 2;
		return (new_lst_token(ft_strdup(">>"), T_APPEND));
	}
	else if (str[*i] == '<' && str[*i + 1] == '<')
	{
		*i += 2;
		return (new_lst_token(ft_strdup("<<"), T_HEREDOC));
	}
	else if (str[*i] == '>')
	{
		(*i)++;
		return (new_lst_token(ft_strdup(">"), T_REDIR_OUT));
	}
	else if (str[*i] == '<')
	{
		(*i)++;
		return (new_lst_token(ft_strdup("<"), T_REDIR_IN));
	}
	else if (str[*i] == '|')
	{
		(*i)++;
		return (new_lst_token(ft_strdup("|"), T_PIPE));
	}
	return (NULL);
}

t_token	*new_lst_token(char *value, t_token_type type)
{
	t_token	*new_lst;

	new_lst = malloc(sizeof(t_token));
	if (!new_lst)
		return (NULL);
	new_lst->value = value;
	new_lst->type = type;
	new_lst->next = NULL;
	return (new_lst);
}
void	token_add_back(t_token **lst, t_token *new_lst)
{
	t_token	*tmp;

	if (!*lst)
	{
		*lst = new_lst;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_lst;
}
