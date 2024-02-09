# \ = is used to Splitting Long Lines 3.1.1

# ;\ = indicates a multiline command and keeps the instance of the terminal for 
# the next command

# % = the same as * 'wildcard'
# $@ = means what is before the : in the target
# $^ = means what is after the : in the target
# $< = the first prerequisite (usually a source file)
# -I.  = adds include directory of header files.
# -f = force the removal even if the files have been already deleted. 

# -c = Compile or assemble the source files, but do not link.
# The linking stage simply is not done. The ultimate output is
# in the form of an object file for each source file.
# By default, the object file name for a source file is made by replacing
# the suffix .c, .i, .s, etc., with .o. Unrecognized input files,
# not requiring compilation or assembly, are ignored.

# .PHONY : clean
# phony prevent make from getting confused by an actual file called `clean' 
# and causes it to continue in spite of errors from rm
# A rule such as this should not be placed at the beginning of the makefile, because we do not want it to run by default!
# Thus, in the example makefile, we want the rule for edit, which recompiles the editor, to remain the default goal.
# Since clean is not a dependency of edit, this rule will not run at all if we give the command `make' with no arguments. 
# In order to make the rule run, we have to type `make clean'

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = -I.
AR = ar
ARFLAGS = -rcs
NAME = libftprintf.a

SRC_PATH = src/
SRC	= ft_printf\
char\
flag_handler\
flag\
hex_conv\
int_conv\
nbr_print\
width_handler\
utils

SRCFC	= $(addprefix $(SRC_PATH),$(addsuffix .c, $(SRC)))
SRCO	= $(SRCFC:.c=.o)
OBJDIR	= test
OBJS	= $(SRCFC:.c=.o)

DEF_COLOR = \033[0;39m
GREEN = \033[0;92m
RED = \033[0;91m
CIANO = \033[0;96m


CC			= gcc
RM			= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

all:			$(NAME)


$(NAME):		$(OBJS)
			$(MAKE) all -C src/libft/
			cp src/libft/libft.a $(NAME)
			ar -rc $(NAME) $(OBJS)
			@echo "$(RED)CONVERTED:\n$(SRCFC)\nTO:\n$(SRCO)"
			@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

clean:			
	$(MAKE) clean -C src/libft/
	$(RM) $(OBJS) $(BONUS_OBJS)
	echo "$(GREEN)ft_printf cleaned!$(DEF_COLOR)"

fclean:		clean
		$(MAKE) fclean -C src/libft/
		$(RM) $(NAME)
		echo "$(GREEN)ft_printf full cleaned!$(DEF_COLOR)"

re:			fclean all
$(OBJDIR)/%.o: %.c

bonus: all

.PHONY : all re fclean clean bonus

.SILENT :
