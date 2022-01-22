SRC =	pipex.c \
		errors.c \
		check_arguments.c \


FLAGS = -Wall -Wextra -Werror
OBJ = $(patsubst %.c,%.o,$(SRC))
HEADER = pipex.h
LIB = ./lib/libft.a
EXECUTABLE = pipex
LIB = ./lib -lft
LINK_LIB = -L $(LIB)

all : $(EXECUTABLE) $(SRC)

$(EXECUTABLE) : $(OBJ) $(HEADER)
	make -C $(LIB)
	gcc $(FLAGS) $(OBJ)  $(LINK_LIB) -o $@

$(OBJ) : %.o : %.c
	gcc $(FLAGS) -c  $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(EXECUTABLE)

re :  fclean all

.PHONY : all clean fclean re