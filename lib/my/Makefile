##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## libc
##

CC	=	gcc

NAME	=	libmy.a

SRC	=	flag_c.c				\
		flag_d.c				\
		flag_e.c				\
		flag_emaj.c				\
		flag_f.c				\
		flag_g.c				\
		flag_hashtag.c			\
		flag_i.c				\
		flag_o.c				\
		flag_p.c				\
		flag_s.c				\
		flag_u.c				\
		flag_x.c				\
		length_l.c				\
		my_compute_power_rec.c	\
		my_getnbr.c				\
		my_isneg.c				\
		my_printf.c				\
		my_put_nbr.c			\
		my_putchar.c			\
		my_putstr.c				\
		my_str_isalpha.c		\
		my_str_isnum.c			\
		my_strcat.c				\
		my_strcmp.c				\
		my_strcpy.c				\
		my_strdup.c				\
		my_strlen.c				\
		my_swap.c				\
		put_nbr_base.c

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ) $(CFLAGS)
	@cp $(NAME) ../../$(NAME)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)
	@rm -f ../../$(NAME)

re:	fclean all
