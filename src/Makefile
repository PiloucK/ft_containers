NAME				:= ft_containers

SRC_EXTENSION		:= \
	.cpp

H_EXTENSION			:= \
 	.hpp

SRC_NAME			:= \

H_NAME				:= \

S_DIR		 		:= \
	src/

O_DIR				:= \
	$(../obj/vector)

I					:= \
	-I ./

O					= \
	$(addprefix $(O_DIR), $(addsuffix .o, $(SRC_NAME)))

C					:= clang++
CFLAGS				:= -Wall -Wextra -Werror -std=c++98

R					:= rm -f

$(O_DIR)%.o:		$(S_DIR)%$(SRC_EXTENSION) Makefile
	$C $(CFLAGS) $I -c $< -o $@

# vector/Vector.o : vector/Vector.hpp ft.hpp

all:				$(NAME)

debug: CFLAGS += -DDEBUG -g
debug: all

$(NAME):			$O
	$C $^ -o $@

clean:
	$R $O

fclean:				clean
	$R $(NAME)

re:					fclean all

.PHONY: all clean fclean re
