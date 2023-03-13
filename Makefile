# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llion <llion@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 12:05:59 by llion             #+#    #+#              #
#    Updated: 2023/01/23 16:44:50 by llion            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= src/main.c				\
				  src/check_map.c			\
				  src/errors.c				\
				  src/manage_map.c			\
				  src/parse_map.c			\
				  src/check_map_utils.c		\
				  src/utils.c				\
				  src/display_map.c			\
				  src/free_memory.c			\
				  src/hook.c				\
				  src/player.c				\
				  src/elements.c			

OBJS			= $(SRCS:.c=.o)
LIBFT			= libft/libft.a
NAME			= so_long
CC				= gcc
FLAGS			= -Wall -Wextra -Werror
RM				= rm -rf

%.o: %.c
				$(CC) $(FLAGS) -Imlx -c $< -o $@ -g3

all: 			$(NAME)

$(NAME): 		$(OBJS) $(LIBFT)
				$(CC) $(OBJS) libft/libft.a libmlx42.a -I include -lglfw \
					-L /Users/llion/.brew/Cellar/glfw/3.3.8/lib -o so_long

linux:	 		$(OBJS) $(LIBFT)
				$(CC) $(OBJS) libft/libft.a libmlx42.a -I include -lglfw -ldl \
					-pthread -lm -L /Users/llion/.brew/Cellar/glfw/3.3.8/lib  \
					-o so_long

bonus:	 		$(OBJS) $(LIBFT)
				$(CC) $(OBJS) libft/libft.a libmlx42.a -I include -lglfw \
					-L /Users/llion/.brew/Cellar/glfw/3.3.8/lib -o so_long

$(LIBFT):
				$(MAKE) -C "libft" 	

debug:	 		fclean $(OBJS) $(LIBFT)
				$(CC) $(OBJS) -g3 libmlx42.a libft/libft.a -lglfw \
					-L /Users/llion/.brew/Cellar/glfw/3.3.8/lib -o so_long
				valgrind ./so_long "maps/map.ber"

sanitize:	 	clean $(OBJS) $(LIBFT)
				$(CC) $(OBJS) -fsanitize=address libmlx42.a -lglfw libft/libft.a \
					-L /Users/llion/.brew/Cellar/glfw/3.3.8/lib -o so_long

clean:
				$(RM) $(OBJS)
				$(MAKE) clean -C "libft"

fclean: 		clean
				$(RM) $(NAME) *.dSYM .DS_* .vscode logs
				$(MAKE) fclean -C "libft"

re:				fclean all

.PHONY:			clean re all fclean debug
