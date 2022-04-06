# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 16:38:11 by ytakii            #+#    #+#              #
#    Updated: 2022/04/06 16:41:52 by ytakii           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= gnl.a 

CC= cc

CFLAGS= -Wall -Wextra -Werror

SRCS= get_next_line.c get_next_line_utils.c

OBJS= $(SRCS:.c=.o)
	AR= ar rcs
	RM= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)     
	     
%.o: %.c     
	$(CC) $(CFLAGS) -c $< -o $@     
	     
clean:     
	$(RM) $(OBJS)     
	     
fclean: clean     
	$(RM) $(NAME)     
	     
re:fclean all     
	     
test: re all     
	$(CC) $(CFLAGS) $(NAME)     
	./a.out     

.PHONY: all, clean, fclean, re, test
