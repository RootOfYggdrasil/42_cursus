# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 18:26:48 by sdel-gra          #+#    #+#              #
#    Updated: 2024/02/05 12:11:02 by sdel-gra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = megaphone

#			FLAGS			#

CFLAGS = -Wall -Wextra -Werror

#			DEFINITIONS		#

CC	= c++ -std=c++98
AR	= ar
RM	= rm -rf

#			PATH & SOURCES	#
SRC	= megaphone
SRCFC	= $(addsuffix .cpp, $(SRC))
SRCO	= $(SRCFC:.cpp=.o)
OBJS	= $(SRCFC:.cpp=.o)

#			COLORS			#

DEF_COLOR = \033[0;39m
G = \033[0;92m
R = \033[0;91m
C = \033[0;96m

#			RULES			#

%.o : $(SRCS_DIR)%.c
			$(CC) $(CFLAGS) -c $< -o

all: 	${NAME}
	

$(NAME):	$(OBJS)
		@echo "$(C)compiling $(NAME) $(DEF_COLOR)"
		@$(CC) $(CFLAG) $(OBJS) -o $(NAME)
		@echo "$(G)$(NAME) compiled$(DEF_COLOR)"

clean: 
	@${RM} ${OBJS}

fclean:	clean
		$(RM) $(NAME)
		@echo "$(G)$(NAME) full cleaned!$(DEF_COLOR)"

re: fclean all