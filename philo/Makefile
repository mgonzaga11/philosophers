# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/30 16:51:06 by mgonzaga          #+#    #+#              #
#    Updated: 2024/10/03 19:29:07 by mgonzaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
FLAGS = -pthread -g -Wall -Wextra -Werror
RM = rm -f


SRC_PATH = ./src/
FILES = $(addprefix $(SRC_PATH), $(addsuffix .c, actions init_dinner init_struct main monitoring valid_functions2 valid_functions))
			 
OBJ = $(FILES:%.c=%.o)			

all: $(NAME)
	
$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -I .

clean:
	@$(RM)  $(OBJ)

fclean: clean
	@$(RM) $(NAME) 

re: fclean all


.PHONY: all clean fclean re
