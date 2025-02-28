# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seruff <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 15:55:32 by seruff            #+#    #+#              #
#    Updated: 2025/02/06 15:22:41 by seruff           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Include
INC =	-L$(LIBFT_DIR) -lft
HEAD = push_swap.h
HEAD_DIR = include

# Source
SRC_DIR = src
#SRC = 	$(SRC_DIR)/liste.c 		\
	$(SRC_DIR)/insert_sort.c	\
	$(SRC_DIR)/check_input.c	\
	$(SRC_DIR)/push.c		\
	$(SRC_DIR)/main.c		\
	$(SRC_DIR)/init.c		\
	$(SRC_DIR)/swap.c		\
	$(SRC_DIR)/rotate.c		\
	$(SRC_DIR)/reverse.c		\
	$(SRC_DIR)/sorted.c		\
	$(SRC_DIR)/order.c		\
	$(SRC_DIR)/search.c		\
	$(SRC_DIR)/search2.c		\
	$(SRC_DIR)/opti.c		

SRC = *.c
# Program
PROG = push_swap

# Libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Color
GC = \033[0;32m
RC = \033[0;31m
ENDC = \033[0m


all:		$(LIBFT) $(PROG)

$(PROG):	$(SRC)
		@echo "$(GC)Compiling program..$(ENDC)"
		$(CC) $(CFLAGS) -o $(PROG) $(SRC) $(LIBFT) $(INC)
		@echo "$(RC)Pogram Push_Swap is ready to be used$(ENDC)"

$(LIBFT):
		@echo "$(GC)Building Libft$(ENDC)"
		@make all -C$(LIBFT_DIR)
		@echo "$(RC)Libft is ready$(ENDC)"
clean:
		@make fclean -C$(LIBFT_DIR)
		@echo "$(RC)Libft.a is removed$(ENDC)"

fclean:		clean
		@rm -f $(PROG)

re:		fclean all

.PHONY: 	re all fclean clean
