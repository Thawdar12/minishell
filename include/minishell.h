#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_token_type
{
	T_WORD,
	T_PIPE,
	T_REDIR_IN,
	T_REDIR_OUT,
	T_APPEND,
	T_HEREDOC
}					t_token_type;

typedef struct s_token
{
	char			*value;
	t_token_type	type;
	struct s_token	*next;
}					t_token;

// lexer
t_token				*lexer(char *input);

// lexer_utils
int					is_operator(char c);
t_token				*handle_operator(char *str, int *i);
char				*extract_word(char *str, int *i);
char				*extract_single_quote(char *str, int *i);
char				*extract_double_quote(char *str, int *i);
char				*extract_full_word(char *str, int *i);
t_token				*new_lst_token(char *value, t_token_type type);
void				token_add_back(t_token **lst, t_token *new_lst);


// debug
void	print_tokens(t_token *list);

#endif