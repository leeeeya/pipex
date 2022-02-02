NAME = pipex
NAME_B = pipex_bonus

SRC =	pipex.c \
		errors.c \
		check_arguments.c \

SRC_B = pipex_bonus.c \
        errors_bonus.c \
        check_arguments_bonus.c \

FLAGS = -Wall -Wextra -Werror
OBJ = $(patsubst %.c,%.o,$(SRC))
OBJ_B = $(patsubst %.c,%.o,$(SRC_B))
HEADER = pipex.h
HEADER_B = pipex_bonus.h
LIB = ./lib/libft.a

LIB = ./lib -lft
LINK_LIB = -L $(LIB)

all : $(NAME) $(SRC)

$(NAME) : $(OBJ) $(HEADER)
	make -C $(LIB)
	gcc $(FLAGS) $(OBJ)  $(LINK_LIB) -o $@

$(OBJ) : %.o : %.c
	gcc $(FLAGS) -c  $< -o $@

bonus : $(OBJ_B) $(HEADER_B)
	make -C $(LIB)
	gcc $(FLAGS) $(OBJ_B) $(LINK_LIB) -o $(NAME_B)

$(OBJ_B) :%.o : %.c
	gcc $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ) $(OBJ_B)
	make clean -C $(LIB)

fclean : clean
	rm -f $(NAME)
	rm -f $(NAME_B)
	make fclean -C $(LIB)

re :  fclean all

re_bonus : fclean bonus

.PHONY : all clean fclean re bonus