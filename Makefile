COLOR_RESET = \033[0m
COLOR_YELLOW = \033[1;33m
COLOR_CYAN = \033[1;36m
COLOR_RED = \033[91m
COLOR_GREEN = \033[92m
COLOR_PINK = \033[95m

NAME = philosopher

RM = rm -rf

PATH_HEADER = includes
CFLAGS = -Wall -Wextra -Werror -I $(PATH_HEADER)
PATH_SRCS = srcs

PATH_ALGORITHM = srcs/algorithm
PATH_ERRORHANDLE = srcs/handle

OBJ_DIR = objs

ERRORHANDLE_SRC =	handle_input.c

UTILS_SRC =			utils.c

ERRORHANDLE_SRCS = $(addprefix $(SRC_PATH)/handle/, $(ERRORHANDLE_SRC))
UTILS_SRCS = $(addprefix $(SRC_PATH)/utils/, $(UTILS_SRC))

SRCS = $(PATH_SRCS)/main.c $(ERRORHANDLE_SRCS) $(UTILS_SRCS)
OBJS = $(SRCS:$(SRC_PATH)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "[$(COLOR_YELLOW)$(NAME) --> OK$(COLOR_RESET)]\n ${COLOR_GREEN}Success!${COLOR_RESET}"
	@echo "$(COLOR_PINK)\tUsage: ./philosopher [Argument 5 - 6]$(COLOR_RESET)"

$(OBJ_DIR)/%.o: $(PATH_SRCS)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(COLOR_GREEN)Compiled:$(COLOR_RESET) $<"

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(COLOR_RED)Cleaned up object files$(COLOR_RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(COLOR_RED)Cleaned up executables$(COLOR_RESET)"

re: fclean all

.PHONY: all clean fclean re
