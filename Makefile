# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 15:09:18 by lbourniq          #+#    #+#              #
#    Updated: 2022/12/07 16:22:34 by lbourniq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

# Colors
GREEN = \033[1;32m
PURPLE = \033[1;35m
NC = \033[0m

# Header(s)
HEADER = pipex.h

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(HEADER)
RM = rm
RM_FLAGS = -rf

# SRCS Files and objs
SRCS = pipex.c\
	ft_check.c\
	ft_create.c\
	ft_exit.c\
	ft_free.c\
	ft_execute.c\
	ft_close.c
		
OBJS = $(SRCS:.c=.o)

# .c.o rule
%.o: %.c Makefile $(HEADER) ./libft/libft.a
	@$(CC) $(CFLAGS) -c $< -o $@

all: makelibft $(NAME)

makelibft:
	@make -C ./libft/.

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)
	@echo "${GREEN}-> pipex executable compiled successfully${NC}"

clean:
	@make -C ./libft/. clean
	@$(RM) $(RM_FLAGS) $(OBJS)
	@echo "${PURPLE}-> All pipex objs files removed successfully${NC}"

fclean :
	@make -C ./libft/. fclean
	@$(RM) $(RM_FLAGS) $(NAME) $(OBJS)
	@echo "${PURPLE}-> pipex executable and push_swap objs files removed successfully${NC}"

re: fclean all
	
.PHONY: all re fclean clean makelibft