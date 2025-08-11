#########################################
## ARGUMENTS
#########################################

INCLUDES_PATH = ../include
NAME		= libft.a
CFLAGS		= -Wextra -Wall -Werror -I$(INCLUDES_PATH) -g3
CC			= gcc

########################################
## SOURCES
########################################

SRC_FILES = ft_strlen.c \
			ft_putstr_fd.c \
			ft_calloc.c \
			ft_bzero.c \
			get_next_line.c \
			ft_substr.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strchr.c \
			ft_isdigit.c \
			ft_atoi.c \
			ft_strncmp.c \
			garbage_collector.c \
			garbage_collector_manager.c \
			error.c \
			del_if_same.c \
			ft_isalpha.c

OBJ_FILES =	$(SRC_FILES:.c=.o)

########################################
## RULES
########################################

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(AR) rcs $@ $(OBJ_FILES)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
