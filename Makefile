# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 15:09:18 by lbourniq          #+#    #+#              #
#    Updated: 2022/12/08 16:43:33 by lbourniq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

# Colors
GREEN = \033[1;32m
PURPLE = \033[1;35m
NC = \033[0m

# Header(s)
HEADER_DIR = ./includes/

HEADER_NAME = pipex.h
B_HEADER_NAME = pipex_bonus.h

HEADER = $(addprefix $(HEADER_DIR), $(HEADER_NAME))
B_HEADER = $(addprefix $(HEADER_DIR), $(B_HEADER_NAME))

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm
RM_FLAGS = -rf

# --- SRCS files and objs ---
# Mandatory
SRCS_DIR = ./srcs/

SRCS_FILES = pipex.c\
	ft_check.c\
	ft_create.c\
	ft_exit.c\
	ft_free.c\
	ft_execute.c\
	ft_close.c\
	ft_utils.c\
	ft_utils2.c

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS = $(SRCS:.c=.o)

# Bonus
B_SRCS_DIR = ./bonus/

B_SRCS_FILES = pipex_bonus.c\
	ft_check_bonus.c\
	ft_create_bonus.c\
	ft_exit_bonus.c\
	ft_free_bonus.c\
	ft_execute_bonus.c\
	ft_close_bonus.c\
	ft_utils_bonus.c\
	ft_utils2_bonus.c

B_SRCS = $(addprefix $(B_SRCS_DIR), $(B_SRCS_FILES))
B_OBJS = $(B_SRCS:.c=.o)

# .c.o rule (mandatory part)
$(SRCS_DIR)%.o: $(SRCS_DIR)%.c Makefile $(HEADER) ./libft/libft.a
	@$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@

# .c.o rule (bonus part)
$(B_SRCS_DIR)%.o: $(B_SRCS_DIR)%.c Makefile $(B_HEADER) ./libft/libft.a
	@$(CC) $(CFLAGS) -I$(B_HEADER) -c $< -o $@

all: makelibft $(NAME)

makelibft:
	@make -C ./libft/.

$(NAME): makelibft $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)
	@echo "${GREEN}-> pipex executable compiled successfully${NC}"

clean:
	@make -C ./libft/. clean
	@$(RM) $(RM_FLAGS) $(OBJS)
	@echo "${PURPLE}-> All pipex objs files removed successfully${NC}"

fclean :
	@make -C ./libft/. fclean
	@$(RM) $(RM_FLAGS) $(NAME) $(OBJS) $(B_OBJS)
	@echo "${PURPLE}-> pipex executable and pipex objs + bonus objs files removed successfully${NC}"

re: fclean all

bonus: makelibft $(B_OBJS)
	@$(CC) $(CFLAGS) $(B_OBJS) libft/libft.a -o $(NAME)
	@echo "${GREEN}-> pipex executable with bonus compiled successfully${NC}"
	
.PHONY: all re fclean clean makelibft bonus