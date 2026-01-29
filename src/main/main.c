#include "../../include/minishell.h"

/// FOR DEBUGING <Delete later>
void	print_tokens(t_token *list)
{
	while (list)
	{
		printf("TYPE: %d | VALUE: [%s]\n",
			list->type,
			list->value);
		list = list->next;
	}
}

int main(void)
{
    char *input;
    t_token *tokens;

    while(1)
    {
        input = readline("minishell$ ");
        if(!input)
            break;
        if(*input)
            add_history(input);
        tokens = lexer(input);
        print_tokens(tokens);
        free(input);
    }
}
