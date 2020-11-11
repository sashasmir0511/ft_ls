GCC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = ft_ls
INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

SRC = main.c parsing.c error.c file_list_new.c
OBJ = $(SRC:.c=.o)

SRCS=$(addprefix $(SRC_DIR)/,$(SRC))
OBJS=$(addprefix $(OBJ_DIR)/,$(OBJ))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ft_printf
	@$(GCC) $(CFLAGS) -o $(NAME) $(OBJS) -L ft_printf -lftprintf

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INC_DIR)/ft_ls.h
	@mkdir -p $(OBJ_DIR)
	$(GCC) $(CFLAGS) -I $(INC_DIR) -g -c $< -o $@

clean:
	@make clean -C ft_printf
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C ft_printf

re: fclean all