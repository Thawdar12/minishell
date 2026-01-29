# Minishell Overview

## Directory Structure

```
minishell/
├── include/               # Header files
│   └── minishell.h
├── src/
│   ├── main/
│   │   └── main.c         # Entry point
│   └── lexer/
│       ├── lexer.c       # Lexer main function
│       ├── lexer_utils.c # Token list functions & operator handling
│       └── lexer_extract_utils.c # Word & quote extraction
├── libft/                 # Libft library
├── obj/                   # Object files (generated)
├── Makefile
└── README.md
```

# Lexer Overview

## Supported Token Types

The lexer supports the following token types:

- **T_WORD** → normal words and arguments  
- **T_PIPE** → `|`  
- **T_REDIR_IN** → `<`  
- **T_REDIR_OUT** → `>`  
- **T_APPEND** → `>>`  
- **T_HEREDOC** → `<<`  

## How the Lexer Works

### 1. Skip Whitespace
Spaces and tabs are ignored.

### 2. Detect Operators

If the current character is an operator:
- `|`
- `<`
- `>`
- `<<`
- `>>`
The lexer creates an **operator token** and advances the input index.

### 3. Extract Words

If the character is not whitespace or an operator, the lexer extracts a word:
- Handles **plain words**
- Handles **single quotes** `'...'`
- Handles **double quotes** `"..."`

Multiple segments are concatenated into a single token if needed.

## Example

### Input
```bash
echo "Hello World" | grep World > output.txt
```
### Lexer Output

```
TYPE: 0 | VALUE: [echo]
TYPE: 0 | VALUE: [Hello World]
TYPE: 1 | VALUE: [|]
TYPE: 0 | VALUE: [grep]
TYPE: 0 | VALUE: [World]
TYPE: 3 | VALUE: [>]
TYPE: 0 | VALUE: [output.txt]
```
---
## Token Type Mapping

| Numeric Type | Token Name   |
------------|---------------
| 0          | T_WORD        |
| 1          | T_PIPE        |
| 2          | T_REDIR_IN    |
| 3          | T_REDIR_OUT   |
| 4          | T_APPEND      |
| 5          | T_HEREDOC     |

---
## Important Notes

### Memory Management

- All token values are **heap-allocated** using `ft_strdup` or `ft_substr`
- Tokens **must be freed after parsing**


### Quote Errors

- If quotes are not closed properly, the lexer returns `NULL`
- The parser should detect this and handle syntax errors


### Word Concatenation

`extract_full_word` concatenates quoted and unquoted parts.

Example:

```bash
'hi'"there"
```

Result:

```
hithere
```
--
# Makefile Usage

### Compile

```bash
make
```

### Run Minishell

```bash
./minishell
```

### Clean Object Files

```bash
make clean
```

### Full Clean

```bash
make fclean
```

### Recompile From Scratch

```bash
make re
```

# Side Notes

According to the project subject:
- You can exit the shell using **Ctrl + D**

