COLOR_RESET = \033[0m
COLOR_YELLOW = \033[1;33m
COLOR_CYAN = \033[1;36m
COLOR_RED = \033[1;91m
COLOR_GREEN = \033[92m
COLOR_PINK = \033[95m

NAME = philo

RM = rm -rf

PATH_HEADER = includes
# CFLAGS = -Wall -Werror -Wextra -pthread -g -I $(PATH_HEADER)
CFLAGS = -Wall -Werror -Wextra -pthread -g -fsanitize=thread -I $(PATH_HEADER)
# CFLAGS = -pthread -g -fsanitize=thread -I $(PATH_HEADER)

PATH_SRCS = srcs

PATH_ALGORITHM = srcs/algorithm
PATH_ERRORHANDLE = srcs/handle

OBJ_DIR = objs

ALGORITHM_SRC =		init_philo.c	\
					routine.c

ERRORHANDLE_SRC =	handle_input.c

UTILS_SRC =			utils_libft.c	\
					utils_philo.c

ALGORITHM_SRCS =	$(addprefix $(SRC_PATH)/algorithm/, $(ALGORITHM_SRC))
ERRORHANDLE_SRCS = $(addprefix $(SRC_PATH)/handle/, $(ERRORHANDLE_SRC))
UTILS_SRCS = $(addprefix $(SRC_PATH)/utils/, $(UTILS_SRC))

SRCS = $(PATH_SRCS)/philosopher.c $(ERRORHANDLE_SRCS) $(UTILS_SRCS) $(ALGORITHM_SRCS)
OBJS = $(SRCS:$(SRC_PATH)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "[$(COLOR_YELLOW)$(NAME) --> OK$(COLOR_RESET)]"
	@echo "$(COLOR_PINK)\tUsage: $(NAME) [Argument 5 - 6]$(COLOR_RESET)"

$(OBJ_DIR)/%.o: $(PATH_SRCS)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(COLOR_GREEN)$(CFLAGS)$(COLOR_RESET) $<"

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(COLOR_RED)Cleaned up object files$(COLOR_RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(COLOR_RED)Cleaned up executables$(COLOR_RESET)"
	@echo "$(COLOR_RED)Delete $(NAME)$(COLOR_RESET)"

re: fclean all

leaks:
	@valgrind ./$(NAME) 5 900 295 60 10

helgrind:
	@valgrind --tool=helgrind ./$(NAME) 5 900 295 60 10

run: $(NAME)
	@./$(NAME) 5 900 295 60 10

.PHONY: all clean fclean re run leaks
