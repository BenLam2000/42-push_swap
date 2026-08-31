# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: belam <belam@student.42iskandarputeri.edu  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/26 03:07:24 by belam             #+#    #+#              #
#    Updated: 2026/08/30 13:15:15 by belam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############ VARIABLES ###############
BUILD_DIR = ../build
NAME = $(BUILD_DIR)/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs 
# r (REPLACE/INSERT)	= inserts pre-compiled object (.o) files into archive or replaces existing ones
# c (CREATE)			= creates the archive file if it does not exist		
# s (SYMBOL TABLE) 		= generates/updates object file index stored at the start of the archive itself (faster for linker to reference functions when building final program)
RM = rm -rf 

# cannot use $(wildcard *.c), forbidden although moulinette won't check
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
	ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
	ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
	ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c\
	ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c\
	ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c\
	ft_tolower.c ft_toupper.c\
	ft_strcmp.c ft_split_strict.c ft_arrlen.c ft_arrjoin.c ft_atoi_imp.c\
	ft_error.c ft_atoi_imp.c ft_hasdups.c ft_issorted.c ft_abs.c ft_sign.c\
	ft_max.c ft_min.c ft_append_char.c
OBJ = $(addprefix $(BUILD_DIR)/,$(SRC:.c=.o))
INCLUDE_DIR = ../include
HEADER = $(INCLUDE_DIR)/libft.h

############ RULES ################
# TARGET: DEPENDENCY / PREREQUISITE
# 	RECIPE

# if dependency doesn't exist or is outdated, dependency will be checked and built
# recursively (only what's needed)
# default target = first target in makefile
all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

# $< : automatic variable representing first dependency
# $@ : automatic variable representing target
# %:% : pattern rule for building individual files (%=matches the same name)
# header is only prerequisite, not included in compilation line,
# compiler finds header file from #include in source files OR
# -I include/ folder
$(BUILD_DIR)/%.o: %.c $(HEADER) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# to indicate targets that are not actual files, prevent clashes filenames that are
# same as phony targets
.PHONY: all clean fclean re
