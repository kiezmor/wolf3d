# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/29 17:07:16 by vpluchar          #+#    #+#              #
#    Updated: 2017/10/29 17:12:16 by vpluchar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation

NAME	=	wolf3d
CC		=	gcc
FLAGS	=	-Wall -Werror -Wextra
FRAME	=	-I./mlx -L./mlx -lmlx -framework OpenGL -framework AppKit

# Directories

SDIR	=	src
DOBJ	=	obj
INC		=	-I inc/

# Colors

G		=	\x1b[32m
R		=	\x1b[31m
Y		=	\x1b[33m
NC		=	\x1b[0m

# Files

LIB		=	libft/libft.a

OBJ 	=	$(patsubst %.c, $(DOBJ)/%.o, $(SRC))
ODIR	=	$(addprefix $(DOBJ)/, $(SDIR))

SRC		=	

# Rules

all: $(NAME)

$(NAME): $(OBJ)
	@echo "${Y}create ${G}$(NAME)${NC}"
	@make -C libft/

	@echo "${G}$(NAME) created${NC}"

$(DOBJ)/%.o:%.c
	@mkdir -p $(ODIR)
	@echo "${G}[OK]${NC}	${Y}Compiling:${NC}" $<
	@$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
	@make -C libft/ clean
	@rm -rf obj/
	@echo "${Y}Wolf3D ${R}objects deleted${NC}"

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "${Y}$(NAME) ${R}deleted${NC}"

re: fclean all