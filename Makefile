COLOR_RESET = \033[0m
COLOR_YELLOW = \033[1;33m
COLOR_CYAN = \033[1;36m
COLOR_RED = \033[91m
COLOR_GREEN = \033[92m
COLOR_PINK = \033[95m

NAME = philosopher

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -I $(PATH_HEADER)

PATH_LIBFT = libft
PATH_SRCS = srcs

PATH_ALGORITHM = srcs/algorithm
PATH_ERRORHANDLE = srcs/handle

PATH_HEADER = includes
OBJ_DIR = objs

ERRORHANDLE_SRC =	handle_input.c

ERRORHANDLE_SRCS = $(addprefix $(SRC_PATH)/handle/, $(ERRORHANDLE_SRC))

SRCS = $(PATH_SRCS)/main.c $(ERRORHANDLE_SRCS)
OBJS = $(SRCS:$(SRC_PATH)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(PATH_LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(PATH_LIBFT) -lft
	@echo "[$(COLOR_YELLOW)$(NAME) --> OK$(COLOR_RESET)]\n ${COLOR_GREEN}Success!${COLOR_RESET}"
	@echo "$(COLOR_PINK)\tUsage: ./philosopher [Argument 5 - 6]$(COLOR_RESET)"

$(OBJ_DIR)/%.o: $(PATH_SRCS)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(COLOR_GREEN)Compiled:$(COLOR_RESET) $<"

clean:
	@make clean -C $(PATH_LIBFT)
	@$(RM) $(OBJ_DIR)
	@echo "$(COLOR_RED)Cleaned up object files$(COLOR_RESET)"

fclean: clean
	@make fclean -C $(PATH_LIBFT)
	@$(RM) $(NAME)
	@echo "$(COLOR_RED)Cleaned up executables$(COLOR_RESET)"

re: fclean all

.PHONY: all clean fclean re
