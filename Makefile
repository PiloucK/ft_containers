NAME				:=	test

SRC_EXTENSION		:= \
	.cpp

H_EXTENSION			:= \
 	.hpp

SRCS				:= \
	$(addprefix vector/, $(VECTOR))
	main

VECTOR				:= \
	Vector

H_NAME				:= \

SRC_DIR		 		:= \
	src/

OBJ_DIR				:= \
	obj/

I					:= \
	$(addprefix -I, $(shell find $(SRC_DIR) -type d))

OBJS					= \
	$(addprefix $(O_DIR), $(addsuffix .o, $(SRC_NAME)))

C					:= clang++
CPPFLAGS			:= -Wall -Wextra -Werror -std=c++98
DEPFLAGS			:= -MMD -MP

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

-include $(DEPS)
