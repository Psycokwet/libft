NAMETESTP1	=	test_p1
NAMETESTP2	=	test_p2
NAME		=	libft.a

SRCTESTP1		=	main_p1.c	
SRCTESTP2		=	main_p2.c						

## No need for a \ on the last line
SRC			=	ft_memset.c		\
				ft_bzero.c		\
				ft_memcpy.c		\
				ft_memccpy.c	\
				ft_memmove.c	\
				ft_memchr.c		\
				ft_memcmp.c		\
				ft_strlen.c		\
				ft_isalpha.c	\
				ft_isdigit.c	\
				ft_isalnum.c	\
				ft_isascii.c	\
				ft_isprint.c	\
				ft_toupper.c	\
				ft_tolower.c	\
				ft_strchr.c		\
				ft_strrchr.c	\
				ft_strncmp.c	\
				ft_strlcpy.c	\
				ft_strlcat.c	\
				ft_strnstr.c	\
				ft_atoi.c		\
				ft_calloc.c		\
				ft_strdup.c		\
				ft_toupper.c	\
				ft_substr.c		\
				ft_strjoin.c	\
				ft_strtrim.c	\
				ft_split.c		\
				ft_itoa.c


OBJTESTP1		=	$(SRCTESTP1:.c=.o) 				## get all .o names from .c names
OBJTESTP2		=	$(SRCTESTP2:.c=.o) 				## get all .o names from .c names
OBJ			=	$(SRC:.c=.o) 					## get all .o names from .c names

CC			=	cc

CFLAGS		+=	-W -Wall -Wextra -Werror -g3 -pedantic		## '+=' allow to keep default flags.

LDFLAGS		= 	libft.a							## example : -L/home/user/lib -lmyLib/ ou pas en fait

RM			= 	rm -f

all	: $(NAME)						

$(NAME)	: $(OBJ)
		AR -rcv $(NAME) $(OBJ)

$(NAMETESTP1)	:	$(OBJTESTP1) $(NAME)
		$(CC) -o $(NAMETESTP1) $(OBJTESTP1) $(LDFLAGS) $(CFLAGS)

$(NAMETESTP2)	:	$(OBJTESTP2) $(NAME)
		$(CC) -o $(NAMETESTP2) $(OBJTESTP2) $(LDFLAGS) $(CFLAGS)

clean	:									## delete all .o
		$(RM) $(OBJTEST) $(OBJ)				

fclean	:	clean							## clean + delete executable
		$(RM) $(NAMETEST) $(NAME)				

re		:	fclean all							## delete all .o and recompile all. Must use when editing a .h
rep1	:	fclean $(NAMETESTP1)							## delete all .o and recompile all. Must use when editing a .h
rep2	:	fclean $(NAMETESTP2)							## delete all .o and recompile all. Must use when editing a .h

## voir dependances plus tard 
