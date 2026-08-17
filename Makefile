# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/26 03:07:24 by belam             #+#    #+#              #
#    Updated: 2026/08/17 17:52:06 by belam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############ VARIABLES ###############
SRC_DIR		=	./src
BUILD_DIR	=	./build
LIBFT_DIR 	= 	./libft
INCLUDE_DIR = 	./include

NAME		=	push_swap
CC 			=	cc
CFLAGS 		=	-Wall -Wextra -Werror
AR 			=	ar -crs
RM 			=	rm -rf 

LIBFT_A 	= 	$(BUILD_DIR)/libft.a
SRC_FILES	=	main.c stack_utils.c
SRC 		=	$(addprefix $(SRC_DIR)/,$(SRC_FILES))
OBJ_FILES	=	$(SRC_FILES:.c=.o)
OBJ			= 	$(addprefix $(BUILD_DIR)/,$(OBJ_FILES))
HEADER_FILES=	push_swap.h libft.h
HEADERS 	= 	$(addprefix $(INCLUDE_DIR)/,$(HEADER_FILES))

############# RULES ##################
all: $(NAME)

bonus: all

# only linking libft and .o files
$(NAME): $(LIBFT_A) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_A) -o $@

# dependencies for libft is checked within its own makefile
$(LIBFT_A):
	make -C $(LIBFT_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJ)

fclean:
	$(RM) $(BUILD_DIR)
	$(RM) $(NAME)

re			: 	fclean all

.PHONY		:	all bonus clean fclean re
