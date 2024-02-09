# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 17:04:07 by sdel-gra          #+#    #+#              #
#    Updated: 2023/11/05 17:52:05 by sdel-gra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
INCLUDE = includes

#			FLAGS			#

CFLAGS = -Wall -Werror -Wextra -Iincludes

#			DEFINITIONS		#

CC	= cc -g
INC	= -I.
AR	= ar
RM	= rm -rf


#			FILE			#

SRC	=	child_handler\
		cmd_handler\
		error_handler\
		file_handler\
		main\
		pipe_handler

#SRC_PATH =
SRCFC	= $(addprefix $(SRC_PATH),$(addsuffix .c, $(SRC)))
SRCO	= $(SRCFC:.c=.o)
OBJS	= $(SRCFC:.c=.o)

#			COLORS			#

DEF_COLOR = \033[0;39m
G = \033[0;92m
R = \033[0;91m
C = \033[0;96m

#			FLAG			#



#			COMMAND		#

%.o : $(SRCS_DIR)%.c
			$(CC) $(CFLAGS) -c $< -o $@ -I includes

all: ${NAME}

${NAME}:	$(OBJS)
			@echo "$(C)compiling $(NAME) $(DEF_COLOR)"
			make -C libft
			@$(CC) $(CFLAG) $(OBJS) -o $(NAME) libft/libft.a
			@echo "$(G)$(NAME) compiled$(DEF_COLOR)"

clean:
			make -C ./libft clean
			${RM} ${OBJS}
			@echo "$(G)$(NAME) cleaned!$(DEF_COLOR)"

fclean:		clean
			make -C ./libft fclean
			${RM} ${NAME}
			@echo "$(G)$(NAME) full cleaned!$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re