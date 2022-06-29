SRC		=	cub3d.c			\
			src/utils.c		\
			src/init.c		\
			src/draw_2D.c	\
			src/draw_3D.c	\

OBJS	=	$(SRC:.c=.o)

FLAGS	=	-Wall -Wextra -Werror

GCC		=	gcc

RM		=	rm -rf

NAME	=	cub3d

all:		$(NAME)

%.o: %.c
			@$(GCC) $(FLAGS) -Imlx -c $< -o $@

$(NAME):	$(OBJS)
			@$(MAKE) -C ./lib42
			@$(GCC) $(FLAGS) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) ./lib42/libft.a
			@echo "\033[1;32mCompilation complete ✅"

clean:
			@$(RM) $(OBJS)
			@$(MAKE) clean -C ./lib42
			@echo "\033[1;32mCleaning complete 🧽"

fclean:		clean
			@$(RM) $(NAME)
			@$(MAKE) fclean -C ./lib42
			@echo "\033[1;32mFull cleaning complete 🧹"

re:			fclean all
			@echo "\033[1;32mRebuild complete 🔨"

.PHONY:		all fclean clean re
