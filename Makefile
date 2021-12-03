NAME				:=	test

SRC_DIRS		 	:= \
	tests/

OBJ_DIR				:= \
	obj/

SRCS				:= \
	$(shell find $(SRC_DIRS) -name *.cpp)

OBJS				= \
	$(addsuffix .o,$(basename $(SRCS)))

I					:= \
	$(addprefix -I, $(shell find $(SRC_DIR) -type d))

DEPS				:= \
	$(OBJS:.o=.d)

C					:= clang++
CPPFLAGS			:= -Wall -Wextra -Werror -std=c++98
DEPFLAGS			:= -MMD -MP

R					:= rm -f

$(O_DIR)%.o:		$(S_DIR)%$(SRC_EXTENSION) Makefile
	$C $(CFLAGS) $I -c $< -o $@

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
