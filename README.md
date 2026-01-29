Minishell Overview

Directory Structure

minishell/
├── include/               # Header files
│   └── minishell.h
├── src/
│   ├── main/
│   │   └── main.c         # Entry point
│   └── lexer/
│       ├── lexer.c        # Lexer main function
│       ├── lexer_utils.c  # Token list functions & operator handling
│       └── lexer_extract_utils.c # Functions to extract words and quotes
├── libft/                 # Libft library
├── obj/                   # Object files (generated)
├── Makefile
└── README.md

Lexer Overview

Token supported types: words, pipe |, redir_in <, redir_out >, append >>, heredoc <<

How lexer works
1. skip whitespace
2. Check if the current characrer is an operator
    - |, <, >, <<, >>
    - Create an operator Token
3. Or else, extract a words
    - Handle plain words, single quotes '...', double quotes "..."
    - Concatenates multiple parts into one token if needed
    eg: echo "Hello World" | grep World > output.txt
        Output: 
            TYPE: 0 | VALUE: [echo]
            TYPE: 0 | VALUE: [Hello World]
            TYPE: 1 | VALUE: [|]
            TYPE: 0 | VALUE: [grep]
            TYPE: 0 | VALUE: [World]
            TYPE: 3 | VALUE: [>]
            TYPE: 0 | VALUE: [output.txt]

    Note:
    TYPE: 0 → T_WORD
    TYPE: 1 → T_PIPE
    TYPE: 2 → T_REDIR_IN
    TYPE: 3 → T_REDIR_OUT
    TYPE: 4 → T_APPEND
    TYPE: 5 → T_HEREDOC

IMPORTANT NOTES
1. All token values are heap-allocated using ft_strdup or ft_substr.
    Free memory after parsing is done.
2. Unmatched quotes return NULL -> Parser should handle syntax errors.
3. extract_full_word handles concatenation of quoted and unquoted segments:
    Input: 'hi'"there" → Output: "hithere"

Makefile Usage

Compile:
    make
Run:
    ./minishell
Clean object files:
    make clean
Full clean:
    make fclean
Recompile from scratch:
    make re
Side note (according to subject): can terminate the program with Ctrl+D