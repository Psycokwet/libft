NAME	=	executable

SRC		=	main.c							## No need for a \ on the last line

OBJ		=	$(SRC:.c=.o)					## get all .o names from .c names

CC	=	cc

CFLAGS	+=	-W -Wall -ansi -pedantic		## '+=' allow to keep default flags.

LDFLAGS	=									## specify the full lib's path if not local

RM	=	rm -f

all	:
		@make $(NAME)						

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

clean	:
		$(RM) $(OBJ)						## delete all .o

fclean	:	clean							## clean + delete executable
		$(RM) $(NAME)				

re	:	fclean all							## delete all .o and recompile all. Must use when editing a .h