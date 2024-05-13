# Colors
COLOR_RESET = \033[0m
COLOR_YELLOW = \033[1;33m
COLOR_CYAN = \033[1;36m
COLOR_RED = \033[91m
COLOR_GREEN = \033[92m
COLOR_PINK = \033[95m

NAME = libft.a

LOCAL_SRC_PATH = srcs
LOCAL_HEADER_PATH = includes
OBJ_DIR = objs

IO_SRC =		io/ft_putchar_fd.c				\
				io/ft_putendl_fd.c				\
				io/ft_putnbr_fd.c				\
				io/ft_putstr_fd.c

LSTS_SRC =		lsts/ft_lstadd_back.c			\
				lsts/ft_lstadd_front.c			\
				lsts/ft_lstclear.c				\
				lsts/ft_lstdelone.c				\
				lsts/ft_lstiter.c				\
				lsts/ft_lstlast.c				\
				lsts/ft_lstmap.c				\
				lsts/ft_lstnew.c				\
				lsts/ft_lstsize.c

MEMS_SRC =		mems/ft_memchr.c				\
 				mems/ft_memcmp.c				\
 				mems/ft_memcpy.c				\
 				mems/ft_memmove.c				\
 				mems/ft_memset.c				\
 				mems/ft_bzero.c					\
 				mems/ft_calloc.c

STRS_SRC =		strs/ft_atoi.c					\
				strs/ft_itoa.c					\
				strs/ft_split.c					\
				strs/ft_strchr.c				\
				strs/ft_strdup.c				\
				strs/ft_striteri.c				\
				strs/ft_strjoin.c				\
				strs/ft_strlcat.c				\
				strs/ft_strlcpy.c				\
				strs/ft_strlen.c 				\
				strs/ft_strmapi.c				\
				strs/ft_strncmp.c				\
				strs/ft_strnstr.c				\
				strs/ft_strrchr.c				\
				strs/ft_strtrim.c				\
				strs/ft_substr.c				\
				strs/ft_isalnum.c				\
				strs/ft_isalpha.c				\
				strs/ft_isascii.c				\
				strs/ft_isdigit.c				\
				strs/ft_isprint.c				\
				strs/ft_tolower.c				\
				strs/ft_toupper.c

GNL_SRC =		ft_gnl/get_next_line.c

FT_PRINTF_SRC = ft_printf/ft_printf_char.c		\
				ft_printf/ft_printf_hex.c		\
				ft_printf/ft_printf_nbr.c		\
				ft_printf/ft_printf_ptr.c		\
				ft_printf/ft_printf_string.c	\
				ft_printf/ft_printf_unit.c		\
				ft_printf/ft_printf.c

OTHER_SRC =		other/ft_error.c \
				other/ft_free_and_null.c \
				other/ft_multiple_free.c \
				other/ft_abs.c \
				other/ft_freeandjoin.c \
				other/ft_count_word.c \
				other/ft_isspace.c \
				other/ft_hex_to_dec.c


# Objects
IO_SRCS = ${addprefix ${LOCAL_SRC_PATH}/, ${IO_SRC}}
LSTS_SRCS = ${addprefix ${LOCAL_SRC_PATH}/, ${LSTS_SRC}}
MEMS_SRCS = ${addprefix ${LOCAL_SRC_PATH}/, ${MEMS_SRC}}
STRS_SRCS = ${addprefix ${LOCAL_SRC_PATH}/, ${STRS_SRC}}
FT_PRINTF_SRCS = ${addprefix ${LOCAL_SRC_PATH}/, ${FT_PRINTF_SRC}}
GNL_SRCS = ${addprefix ${LOCAL_SRC_PATH}/, ${GNL_SRC}}
OTHER_SRCS = ${addprefix ${LOCAL_SRC_PATH}/, ${OTHER_SRC}}

IO_OBJS = $(patsubst ${LOCAL_SRC_PATH}/%.c, ${OBJ_DIR}/%.o, $(IO_SRCS))
LSTS_OBJS = $(patsubst ${LOCAL_SRC_PATH}/%.c, ${OBJ_DIR}/%.o, $(LSTS_SRCS))
MEMS_OBJS = $(patsubst ${LOCAL_SRC_PATH}/%.c, ${OBJ_DIR}/%.o, $(MEMS_SRCS))
STRS_OBJS = $(patsubst ${LOCAL_SRC_PATH}/%.c, ${OBJ_DIR}/%.o, $(STRS_SRCS))
FT_PRINTF_OBJS = $(patsubst ${LOCAL_SRC_PATH}/%.c, ${OBJ_DIR}/%.o, $(FT_PRINTF_SRCS))
GNL_OBJS = $(patsubst ${LOCAL_SRC_PATH}/%.c, ${OBJ_DIR}/%.o, $(GNL_SRCS))
OTHER_OBJS = $(patsubst ${LOCAL_SRC_PATH}/%.c, ${OBJ_DIR}/%.o, $(OTHER_SRCS))

# Compiler
CC = 		gcc
CFLAGS =	-Wall \
			-Wextra \
			-Werror \
			-I $(LOCAL_HEADER_PATH)

# Targets
all: $(NAME)

$(NAME): $(IO_OBJS) $(LSTS_OBJS) $(MEMS_OBJS) $(STRS_OBJS) $(FT_PRINTF_OBJS) $(GNL_OBJS) $(OTHER_OBJS)
	@ar rcs $(NAME) $(IO_OBJS) $(LSTS_OBJS) $(MEMS_OBJS) $(STRS_OBJS) $(FT_PRINTF_OBJS) $(GNL_OBJS) $(OTHER_OBJS)
	@echo "[$(COLOR_YELLOW)$(NAME) --> OK$(COLOR_RESET)]\n ${COLOR_GREEN}Success!${COLOR_RESET}"
	@echo "$(COLOR_PINK)\tUsage: libft.a$(COLOR_RESET)"

${OBJ_DIR}/%.o: ${LOCAL_SRC_PATH}/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(COLOR_RED)Cleaning object files...$(COLOR_RESET)"
	@rm -rf $(OBJ_DIR)
	@rm -rf .DS_Store

fclean: clean
	@echo "$(COLOR_RED)Cleaning$(COLOR_RESET)$(COLOR_PINK) $(NAME)!$(COLOR_RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
