LIBFT = libft.a

LIBFT_DIR = libft

LIBFT_PATH = ${LIBFT_DIR}/

SOURCES = main.c

OBJECTS = $(SOURCES:.c=.o)

FLAGS = -Wall -Werror -Wextra

COMPILER = cc

NAME = push_swap.a

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C ${LIBFT_DIR}
	cp ${LIBFT_PATH}${LIBFT} .
	mv ${LIBFT} ${NAME}
	ar rcs ${NAME} ${OBJECTS}

$(OBJECTS): %.o:%.c push_swap.h
	$(COMPILER) $(FLAGS) -c $< -o $@ -I ${LIBFT_PATH}

clean: 
	make clean -C ${LIBFT_DIR}
	rm -f $(OBJECTS)

fclean: clean
	rm -f ${LIBFT_PATH}${LIBFT}
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
