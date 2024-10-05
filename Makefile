FILES	=	main.c ft_free.c malloc.c
SRCS	=	$(addprefix srcs/, $(FILES))
OBJS	=	$(addprefix objs/, $(FILES:.c=.o))
NAME	=	cub3D
CFLAGS	=	-Wall -Wextra -Werror -Iincs

all:	$(NAME)

-include $(OBJS:.o=.d)

$(NAME):	$(OBJS)
	cc $(CFLAGS) $(OBJS) -o $@

objs/%.o:	srcs/%.c
	mkdir -p objs
	cc -c $(CFLAGS) $< -o $@ -MMD

clean:
	rm -rf $(OBJS)
	rm -rf objs

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean