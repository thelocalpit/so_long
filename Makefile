# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/31 13:27:03 by pfalasch          #+#    #+#              #
#    Updated: 2023/04/04 12:16:23 by pfalasch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BNAME = so_long_bonus
INC = INC
HEADER = -I inc
LIBFT = lib/libft/
MINILIBX = lib/minilibx/
SRC_DIR = src/
OBJ_DIR = obj/
CC = gcc
CFLAGS = -Wextra -Wall -Werror
FSANITIZE	= -fsanitize=address -g3
RM = rm -f
ECHO = echo -e
MINILIBXCC	= -I mlx -L lib/minilibx -lmlx
#questo open gl cosa mi serve?
OPENGL		= -framework OpenGL -framework AppKit

DEF_COLOR	=	\033[0;39m
ORANGE		=	\033[0;33m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[1;92m
YELLOW		=	\033[1;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

SL_DIR		=	mandatory/
MAND_FILES = so_long 
#map_validation check_limits window window_fill keyhook
#BONUS_DIR = bonus/
#BONUS_FILES	=	so_long_bonus map_validation_bonus check_limits_bonus \
				window_bonus window_fill_bonus keyhook_bonus utils_bonus

SRC_FILES	=	$(addprefix $(SL_DIR), $(MAND_FILES))
#SRC_BFILES	=	$(addprefix $(BONUS_DIR), $(BONUS_FILES))

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o $(SRC_FILES)))

#BSRC		=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_BFILES)))
#BOBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_BFILES)))

OBJF		=	.cache_exists

#cosa mi serve questo start?
#start:
#			@$(ECHO) -n "$(YELLOW)[Dependencies]:\t$(DEF_COLOR)"
#			@$(ECHO) -n "$(RED)[$(DEF_COLOR)"
#			@make all

all: $(NAME)

#-n dopo echo evita di andare a capo
$(NAME):	$(OBJ) $(OBJF)
#			@$(ECHO) -n "$(RED)]$(DEF_COLOR)"
#			@$(ECHO) -n "$(GREEN) => 100%$(DEF_COLOR)\n"
			@make -C $(LIBFT)
			@cp lib/libft/libft.a .
			@make -s -C $(MINILIBX)
#			tutta la prossima pappardella è solo per fare la grafica
			@$(ECHO) -n "$(YELLOW)[MINILIBX]:\t$(DEF_COLOR)"
			@$(ECHO) -n "$(RED)[$(DEF_COLOR)"
			@$(ECHO) -n "$(ORANGE)=======$(DEF_COLOR)"
			@$(ECHO) -n "$(RED)]$(DEF_COLOR)"
			@$(ECHO) "$(GREEN) => Success!$(DEF_COLOR)"
#			fino qui
			@$(ECHO) -n "$(YELLOW)[$(NAME)]:\t$(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(OBJ) $(HEADER) libft.a $(MINILIBXCC) $(OPENGL) -o $(NAME)
			@$(ECHO) "$(GREEN) => Success!$(DEF_COLOR)"

#non ho capito cosa succede qui
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(OBJF)
			@$(ECHO) -n "$(ORANGE)=$(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@
			
#non capisco cosa faccio qui e la vera utilità di .cache_exists
$(OBJF):
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)$(SL_DIR)
			@mkdir -p $(OBJ_DIR)$(BONUS_DIR)
			@touch $(OBJF)
			
clean:
			@$(RM) -r $(OBJ_DIR)
			@make clean -C $(LIBFT)
			@$(RM) $(OBJF)
			@make clean -C $(MINILIBX)
			@$(ECHO) -n "$(BLUE)[so_long]:\tobject files$(DEF_COLOR)$(GREEN)  => Cleaned!$(DEF_COLOR)\n"
			@$(ECHO) -n "$(BLUE)[minilibx]:\tobject files$(DEF_COLOR)$(GREEN)  => Cleaned!$(DEF_COLOR)\n"

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(BNAME)
			@$(RM) libft.a
			@$(RM) $(LIBFT)/libft.a
			@rm -rf *.dSYM
			@find . -name ".DS_Store" -delete
			@$(ECHO) -n "$(CYAN)[LIBFT]:\texec. files$(DEF_COLOR)$(GREEN)  => Cleaned!$(DEF_COLOR)\n"
			@$(ECHO) -n "$(CYAN)[so_long]:\texec. files$(DEF_COLOR)$(GREEN)  => Cleaned!$(DEF_COLOR)\n"
			@$(ECHO) -n "$(CYAN)[minilibx]:\texec. files$(DEF_COLOR)$(GREEN)  => Cleaned!$(DEF_COLOR)\n"

re:			fclean all
			@$(ECHO) -n "$(GREEN)Cleaned and rebuilt everything for [so_long]!$(DEF_COLOR)\n"

#bonus:
#			@$(ECHO) -n "$(YELLOW)[Dependencies]:\t$(DEF_COLOR)"
#			@$(ECHO) -n "$(RED)[$(DEF_COLOR)"
#			@make allbonus

#allbonus:	$(BNAME)
#
#$(BNAME):	$(BOBJ)
#			@$(ECHO) -n "$(RED)]$(DEF_COLOR)"
#			@$(ECHO) -n "$(GREEN) => 100%$(DEF_COLOR)\n"
#			@make -C $(LIBFT)
#			@cp lib/libft/libft.a .
#			@make -s -C $(MINILIBX)
#			@$(ECHO) -n "$(YELLOW)[MINILIBX]:\t$(DEF_COLOR)"
#			@$(ECHO) -n "$(RED)[$(DEF_COLOR)"
#			@$(ECHO) -n "$(ORANGE)=$(DEF_COLOR)"
#			@$(ECHO) -n "$(RED)]$(DEF_COLOR)"
#			@$(ECHO) "$(GREEN) => Success!$(DEF_COLOR)"
#			@$(ECHO) -n "$(YELLOW)[$(BNAME)]:$(DEF_COLOR)"
#			@$(CC) $(CFLAGS) $(BSRC) $(HEADER) libft.a  $(MINILIBXCC) $(OPENGL) -o $(BNAME)
#			@$(ECHO) "$(GREEN) => Success!$(DEF_COLOR)"

norm:
			@clear
			@norminette $(SRC_DIR) $(INC) $(LIBFT) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm