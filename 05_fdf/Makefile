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

NAME = fdf
BONUS = bonus
INCLUDE = includes
MLX_PATH = minilibx-linux

#			FLAGS			#

CFLAGS = -Wall -Wextra -Werror -g -Wuninitialized
ARFLAGS = -rcs
MLXFLAGS = -lm -lX11 -lXext -lmlx

#			DEFINITIONS		#


CC	= cc
INC	= -I.
AR	= ar
RM	= rm -f

#			PATH & SOURCES	#

SRC_PATH = sources/

SRC	= fdf_read\
fdf_draw\
fdf_handler\
fdf_hook\
fdf_image\
fdf_math\
fdf_utils\
fdf_main

SRCFC	= $(addprefix $(SRC_PATH),$(addsuffix .c, $(SRC)))
SRCO	= $(SRCFC:.c=.o)
OBJDIR	= test
OBJS	= $(SRCFC:.c=.o)
ARDIR	= archive/

#			COLORS			#

DEF_COLOR = \033[0;39m
GREEN = \033[0;92m
RED = \033[0;91m
CIANO = \033[0;96m

#			RULES			#



all:			$(NAME)
	



$(NAME):		$(OBJS)
			$(MAKE) all -C libft/
			$(MAKE) all -C minilibx-linux/
			cp -f libft/libft.a $(ARDIR)
			cp -f minilibx-linux/libmlx_Linux.a $(ARDIR)
			${CC} ${CFLAGS} $(OBJS) -L minilibx-linux $(MLXFLAGS) archive/libft.a -o fdf
#			@echo "$(RED)CONVERTED:\n$(SRCFC)\nTO:\n"
#			@echo "$(GREEN)fdf compiled!$(DEF_COLOR)"

clean:			
	$(MAKE) clean -C libft/
	$(RM) $(OBJS) $(BONUS_OBJS)
	echo "$(GREEN)fdf cleaned!$(DEF_COLOR)"

fclean:		clean
		$(MAKE) fclean -C libft/
		$(RM) $(NAME)
		echo "$(GREEN)fdf full cleaned!$(DEF_COLOR)"

re:			fclean all

bonus: all

$(ODIR)%.o : $(SRCS_DIR)%.c
				$(CC) $(CFLAGS) -c $< -o $@ -I includes -I minilibx-linux  -I libft

#			SPECIAL RULE	#


.PHONY : all re fclean clean

.SILENT :
