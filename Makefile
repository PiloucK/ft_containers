NAME				:=	containers

SRC_DIRS		 	:= \
	tests

BUILD_DIR				:= \
	build

SRCS				:= \
	$(shell find $(SRC_DIRS) -name '*.cpp')

OBJS				:= \
	$(SRCS:%=$(BUILD_DIR)/%.o)

I					:= \
	$(addprefix -I, $(shell find $(SRC_DIR) -type d))

DEPS				:= \
	$(OBJS:.o=.d)

C					:= clang++
CPPFLAGS			:= -Wall -Wextra -Werror -std=c++98
DEPFLAGS			:= -MMD -MP

R					:= rm -f

$(BUILD_DIR)/%.cpp.o:		%.cpp
	mkdir -p $(dir $@)
	$C $(CPPFLAGS) $(DEPFLAGS) -I tests -D USING_STD=1 -c $< -o $@

all:				$(NAME)

debug: CFLAGS += -DDEBUG -g
debug: all

$(NAME):			$(OBJS)
	$C $^ -o $@

ft_containers:		$(OBJS)
	$C $^ -o $@

clean:
	$R $(OBJS)

fclean:				clean
	$R $(NAME) $(DEPS)

re:					fclean all

.PHONY: all clean fclean re

-include $(DEPS)
