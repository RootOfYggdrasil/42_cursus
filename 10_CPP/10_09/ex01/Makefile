# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdel-gra <sdel-gra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 18:26:48 by sdel-gra          #+#    #+#              #
#    Updated: 2024/06/19 16:01:45 by sdel-gra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = btc

#			FLAGS			#

CPPFLAGS = -Wall -Wextra -Werror -g -Wshadow -Wno-shadow

#			DEFINITIONS		#

CC	= c++ -std=c++98
RM	= rm -rf

#			PATH & SOURCES	#
SRC	= 	main	\
		RPN

SRCFC	= $(addsuffix .cpp, $(SRC))

#			COLORS			#

DEF_COLOR = \033[0;39m
G = \033[0;92m
R = \033[0;91m
C = \033[0;96m

#			RULES			#

$(NAME):  $(SRCFC)
	@echo "$(SRCFC)"
	@echo "$(C)Compiling $(NAME) $(DEF_COLOR)"
	$(CC) $(SRCFC) $(CPPFLAGS) -o $(NAME) -I includes/
	@echo "'${G}all${DEF_COLOR}' for mandatory ${NAME} executed successfully!"

all: $(NAME)

clean:
	@echo "'${G}clean${DEF_COLOR}' for ${NAME} executed successfully!"

fclean: clean
	$(RM) $(NAME)
	@echo "'${G}fclean${DEF_COLOR}' for ${NAME} executed successfully!"

re: fclean
	make all
	@echo "'${G}re${DEF_COLOR}' for ${NAME} executed successfully!"


.PHONY: all clean fclean re
