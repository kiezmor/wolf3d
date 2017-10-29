# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/16 05:28:33 by vpluchar          #+#    #+#              #
#    Updated: 2017/10/19 22:27:11 by vpluchar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Name

NAME	=	libft.a

## Compilation

CC		=	gcc $(FLAGS) $(INC)
FLAGS	=	-Wall -Wextra -Werror
INC		= 	-I includes

## Directories

SRC_D	=	src
OBJ_D	= 	obj

DIS_D	=	display
INT_D	=	int
LST_D	=	list
MEM_D	=	memory
OTH_D	=	other
STR_D	=	string

## Colors

R		=	\x1b[31m
G		=	\x1b[32m
Y		=	\x1b[33m
NC		=	\x1b[0m

## Files

DIS		=	ft_putchar.c\
			ft_putchar_fd.c\
			ft_putendl.c\
			ft_putendl_fd.c\
			ft_putnbr.c\
			ft_putnbr_fd.c\
			ft_putstr.c\
			ft_putstr_fd.c\
			ft_putwchar.c\
			ft_putwcs.c\
			get_next_line.c

INT		=	ft_isdigit.c\
			ft_itoa.c

LST		=	ft_lstadd.c\
			ft_lstdel.c\
			ft_lstdelone.c\
			ft_lstiter.c\
			ft_lstmap.c\
			ft_lstnew.c

MEM		=	ft_memalloc.c\
			ft_memccpy.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memdel.c\
			ft_memmove.c\
			ft_memset.c

OTH		=	ft_fibonacci.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_range.c\
			ft_sqrt.c

STR		=	ft_atoi.c\
			ft_bzero.c\
			ft_countwords.c\
			ft_isprint.c\
			ft_isspace.c\
			ft_strcat.c\
			ft_strchr.c\
			ft_strclr.c\
			ft_strcmp.c\
			ft_strcpy.c\
			ft_strdel.c\
			ft_strdup.c\
			ft_strequ.c\
			ft_striter.c\
			ft_striteri.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_strmap.c\
			ft_strmapi.c\
			ft_strncat.c\
			ft_strncmp.c\
			ft_strncpy.c\
			ft_strndup.c\
			ft_strnequ.c\
			ft_strnew.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strrev.c\
			ft_strsplit.c\
			ft_strstr.c\
			ft_strsub.c\
			ft_strtrim.c\
			ft_tolower.c\
			ft_toupper.c\
			ft_wcslen.c\
			ft_wcstombs.c\
			ft_wctomb.c

## Utils

SRC		=	$(DIS:%=$(SRC_D)/$(DIS_D)/%)\
			$(INT:%=$(SRC_D)/$(INT_D)/%)\
			$(LST:%=$(SRC_D)/$(LST_D)/%)\
			$(MEM:%=$(SRC_D)/$(MEM_D)/%)\
			$(OTH:%=$(SRC_D)/$(OTH_D)/%)\
			$(STR:%=$(SRC_D)/$(STR_D)/%)

OBJ		=	$(SRC:$(SRC_D)%.c=$(OBJ_D)%.o)

OBJ_DS	=	$(DIS_D:%=$(OBJ_D)/%)\
			$(INT_D:%=$(OBJ_D)/%)\
			$(LST_D:%=$(OBJ_D)/%)\
			$(MEM_D:%=$(OBJ_D)/%)\
			$(OTH_D:%=$(OBJ_D)/%)\
			$(STR_D:%=$(OBJ_D)/%)

## Rules

all: $(NAME)

$(OBJ_DS):
	@mkdir -p $@
	@echo	"${G}Creating	: ${Y}$@ ${NC}"

$(SRC):

$(OBJ_D)/%.o: $(SRC_D)/%.c
	@$(CC) -c $< -o $@
	@echo "${G}[OK]${NC}	${Y}Compiling:${NC}" $<

$(NAME): $(OBJ_DS) $(SRC)
	@$(MAKE) $(OBJ)
	@echo "${G}objects created${NC}"
	@ar rcs $@ $(OBJ)
	@echo "${G}$(NAME) created${NC}"

clean: 
	@rm -rf $(OBJ_D)
	@echo "${R}objects deleted${NC}"

fclean : clean
	@rm -f $(NAME)
	@echo "${Y}$(NAME) ${R}deleted${NC}"

re: fclean all
