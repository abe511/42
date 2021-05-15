NAME = libft.a
FLAGS = -Wall -Werror -Wextra
SOURCES = 		ft_atoi.c ft_bzero.c ft_calloc.c\
				ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
				ft_isspace.c ft_isupper.c ft_islower.c ft_itoa.c\
				ft_memccpy.c ft_memchr.c ft_memcmp.c\
				ft_memcpy.c ft_memmove.c ft_memset.c ft_numlen.c\
				ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c\
				ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c\
				ft_strlen.c ft_strlcat.c ft_strlcpy.c ft_strmapi.c ft_substr.c\
				ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_strtrim.c\
				ft_tolower.c ft_toupper.c\

SOURCES_BONUS =
INCLUDES = ./
OBJECTS = $(SOURCES:.c=.o)
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(SOURCES)
	gcc $(FLAGS) -I$(INCLUDES) -c $(SOURCES)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

bonus: $(NAME)
	gcc $(FLAGS) -I$(INCLUDES) -c $(SOURCES_BONUS)
	ar rc $(NAME) $(OBJECTS_BONUS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJECTS) $(OBJECTS_BONUS) a.out

fclean: clean
	rm -rf $(NAME)

re: fclean all
