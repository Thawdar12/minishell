NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

# Directories

INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

# Source files

SRC_FILES =  main/main.c	lexer/lexer.c	lexer/lexer_utils.c	lexer/lexer_extract_utils.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# Libft

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Rules

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -lreadline -o $(NAME)

# Object compilation

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -c $< -o $@

# Libft rule

$(LIBFT):
	make -C $(LIBFT_DIR)

# Cleaning

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re