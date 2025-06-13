# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/10 17:09:12 by vloureir          #+#    #+#              #
#    Updated: 2025/06/13 09:15:32 by vloureir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#MAKEFLAGS += --silent

NAME := push_swap

NAME_BONUS := checker

SRC_MAIN := main.c

SRC := functions_a.c functions_b.c organize_data.c \
		parse_data.c parse_print.c quicksort_array.c quicksort_list.c \
		small_sort.c utils_list.c utils_print.c utils_sorting.c

SRC_BONUS := main_bonus.c get_next_line/get_next_line.c \
			utils_bonus.c get_next_line/get_next_line_utils.c

OBJ_MAIN := $(SRC_MAIN:.c=.o)

OBJ := $(SRC:.c=.o)

OBJ_BONUS := $(SRC_BONUS:.c=.o)

OBJ := $(SRC:.c=.o)

HEADER := push_swap.h

CFLAGS := -Wall -Wextra -Werror

CC := cc

RED := \033[0;30;41m

GREEN := \033[0;30;42m

OFF := \033[0m

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_MAIN) $(HEADER)
	$(CC) $(OBJ) $(OBJ_MAIN) -o $(NAME) -I.
	@echo "$(GREEN) Push_Swap Compiled $(OFF)"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ) $(OBJ_BONUS) $(HEADER)
	$(CC) $(OBJ) $(OBJ_BONUS) -o $(NAME_BONUS) -I.
	@echo "$(GREEN) Checker Compiled $(OFF)"

clean:
	$(RM) $(OBJ) $(OBJ_MAIN) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	@echo "$(RED) Executables Removed $(OFF)"

re: fclean all

.PHONY: all clean fclean re bonus
