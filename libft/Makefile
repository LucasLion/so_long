# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llion <llion@student.42mulhouse.fr >       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/27 19:07:53 by llion             #+#    #+#              #
#    Updated: 2023/01/24 15:48:45 by llion            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_isalpha.c      \
			  ft_isdigit.c      \
			  ft_isalnum.c      \
			  ft_isascii.c      \
			  ft_isprint.c      \
			  ft_strlen.c       \
			  ft_memset.c	    \
			  ft_bzero.c        \
			  ft_memcpy.c       \
			  ft_memmove.c      \
			  ft_strlcpy.c      \
			  ft_strlcat.c      \
			  ft_toupper.c      \
			  ft_tolower.c      \
			  ft_strchr.c       \
			  ft_strrchr.c      \
			  ft_strncmp.c      \
			  ft_memchr.c       \
			  ft_memcmp.c       \
			  ft_strnstr.c      \
			  ft_atoi.c         \
			  ft_calloc.c       \
			  ft_strdup.c       \
			  ft_substr.c       \
			  ft_strjoin.c      \
			  ft_strtrim.c      \
			  ft_split.c        \
			  ft_itoa.c         \
			  ft_strmapi.c      \
			  ft_striteri.c     \
			  ft_putchar_fd.c   \
			  ft_putstr_fd.c    \
			  ft_putendl_fd.c   \
			  ft_putnbr_fd.c	\
			  ft_printf.c		\
			  ft_printnbr.c		\
			  ft_printchar.c	\
			  ft_printstr.c		\
			  ft_printuint.c	\
			  ft_printx_min.c	\
			  ft_printx.c		\
			  ft_printp.c		\
			  ft_printpct.c		\
			  ft_numlen.c		\
			  ft_lstnew.c       \
			  ft_lstadd_front.c \
			  ft_lstsize.c      \
			  ft_lstlast.c      \
			  ft_lstadd_back.c  \
			  ft_lstdelone.c    \
			  ft_lstclear.c     \
			  ft_lstiter.c      \
			  ft_lstmap.c		\
			  get_next_line.c	\
			  get_next_line_utils.c

			  

NAME		= libft.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
OBJS		= ${SRCS:.c=.o}
AR			= ar rc
RM			= rm -f
LIB			= ranlib

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	
$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS) 
			$(LIB) $(NAME)

all:		$(NAME)

clean:		
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean 
