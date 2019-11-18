NAMETEST	=	test
NAME		=	libft.a

SRCTEST		=	main.c							## No need for a \ on the last line
SRC			=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c	ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c	 ft_isascii.c ft_isprint.c ft_toupper.c	ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c	ft_calloc.c ft_strdup.c ft_toupper.c	## No need for a \ on the last line

OBJTEST		=	$(SRCTEST:.c=.o) 				## get all .o names from .c names
OBJ			=	$(SRC:.c=.o) 					## get all .o names from .c names

CC			=	cc

CFLAGS		+=	-W -Wall -Wextra -Werror -g3 -pedantic		## '+=' allow to keep default flags.

LDFLAGS		= 	libft.a							## example : -L/home/user/lib -lmyLib/ ou pas en fait

RM			= 	rm -f

all	: $(NAME)						

$(NAME)	: $(OBJ)
		AR -rcv $(NAME) $(OBJ)

$(NAMETEST)	:	$(OBJTEST) $(NAME)
		$(CC) -o $(NAMETEST) $(OBJTEST) $(LDFLAGS) $(CFLAGS)

clean	:									## delete all .o
		$(RM) $(OBJTEST) $(OBJ)				

fclean	:	clean							## clean + delete executable
		$(RM) $(NAMETEST) $(NAME)				

re		:	fclean all							## delete all .o and recompile all. Must use when editing a .h
retst	:	fclean $(NAMETEST)							## delete all .o and recompile all. Must use when editing a .h

## voir dependances plus tard 
