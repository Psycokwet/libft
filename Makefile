BONUS		=	bonus
NAME		=	libft.a
INIT_DIRECTORIES = init_dir

SRC_PATH		= ./
OBJ_PATH		= bin/
OBJ_PATHS_INIT	= 	$(OBJ_PATH)
## No need for a \ on the last line
HEADERS_FILES	=	libft.h
SRC_FILES	=		ft_memset.c			\
					ft_bzero.c			\
					ft_memcpy.c			\
					ft_memccpy.c		\
					ft_memmove.c		\
					ft_memchr.c			\
					ft_memcmp.c			\
					ft_strlen.c			\
					ft_isalpha.c		\
					ft_isdigit.c		\
					ft_isalnum.c		\
					ft_isascii.c		\
					ft_isprint.c		\
					ft_tolower.c		\
					ft_strchr.c			\
					ft_strrchr.c		\
					ft_strncmp.c		\
					ft_strlcpy.c		\
					ft_strlcat.c		\
					ft_strnstr.c		\
					ft_atoi.c			\
					ft_calloc.c			\
					ft_strdup.c			\
					ft_toupper.c		\
					ft_substr.c			\
					ft_strjoin.c		\
					ft_strtrim.c		\
					ft_split.c			\
					ft_itoa.c			\
					ft_strmapi.c		\
					ft_putchar_fd.c		\
					ft_putstr_fd.c		\
					ft_putendl_fd.c		\
					ft_putnbr_fd.c		

SRCBONUS_FILES	=	ft_lstnew.c				\
					ft_lstadd_front.c		\
					ft_lstsize.c			\
					ft_lstlast.c			\
					ft_lstadd_back.c		\
					ft_lstdelone.c			\
					ft_lstclear.c			\
					ft_lstiter.c			\
					ft_lstmap.c

SRC_FILES		+=	ft_lstiter_fun_first.c	\
					get_next_line_utils.c	\
					get_next_line.c			\
					free_array.c			

OBJREGULAR_FILES	= 	$(SRC_FILES:.c=.o)			## get all .o names from .c names
OBJBONUS_FILES		=	$(SRCBONUS_FILES:.c=.o) 					## get all .o names from .c names

ifdef WITH_BONUS
OBJ_FILES = $(OBJREGULAR_FILES) $(OBJBONUS_FILES)
else
OBJ_FILES = $(OBJREGULAR_FILES)
endif

SRC 		= $(addprefix $(SRC_PATH), $(SRC_FILES))
SRCBONUS 	= $(addprefix $(SRC_PATH), $(SRCBONUS_FILES))
OBJBONUS 	= $(addprefix $(OBJ_PATH), $(OBJBONUS_FILES))
OBJ 		= $(addprefix $(OBJ_PATH), $(OBJ_FILES))

CC			=	clang

CFLAGS		+=	-W -Wall -Wextra -D BUFFER_SIZE=32 -g3 -Werror -pedantic  		## '+=' allow to keep default flags.

RM			= 	rm -f

all	: $(OBJ_PATHS_INIT) $(NAME)

$(OBJ_PATHS_INIT)	:
	mkdir -p  $@  

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADERS_FILES)
	$(CC) -o $@ -c $< $(CFLAGS)

$(NAME)		: 	$(OBJ)
	ar -src $(NAME) $(OBJ)

$(BONUS)	:
	$(MAKE) WITH_BONUS=1 all

clean	:									## delete all .o
	$(RM) $(OBJ) $(OBJBONUS)		

fclean	:	clean							## clean + delete executable
	$(RM) $(NAMETEST) $(NAME)				

re		:	fclean all							## delete all .o and recompile all. Must use when editing a .h

.PHONY	: all bonus clean fclean re
## voir dependances plus tard 
