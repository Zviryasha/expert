NAME = expert_system

SRC = main.c \
	  get_next_line.c \
	  checking.c \
	  list.c \
	  wings.c \
	  algorithm.c  

OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): libft/libft.a $(OBJ) get_next_line.h systemexpert.h
	gcc $(OBJ) libft/libft.a -I libft -o $(NAME) $(GFLAGS)

%.o: %.c get_next_line.h systemexpert.h
	gcc $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all

libft/libft.a:
	make -C libft
