NAME				:=	containers

SRC_DIRS		 	:= \
	tests

BUILD_DIR			:= \
	build

SRCS				:= \
	$(shell find $(SRC_DIRS) -name '*.cpp')

STD_OBJS			:= \
	$(SRCS:%=$(BUILD_DIR)/std_%.o)

FT_OBJS				:= \
	$(SRCS:%=$(BUILD_DIR)/ft_%.o)

I					:= \
	$(addprefix -I, $(shell find $(SRC_DIR) -type d))

DEPS				:= \
	$(STD_OBJS:.o=.d) \
	$(FT_OBJS:.o=.d)

C					:= clang++
CPPFLAGS			:= -Wall -Wextra -Werror -std=c++98
DEPFLAGS			:= -MMD -MP

R					:= rm -f

$(BUILD_DIR)/std_%.cpp.o:		%.cpp
	mkdir -p $(dir $@)
	$C $(CPPFLAGS) $(DEPFLAGS) -I tests -I. -D USING_STD=1 -c $< -o $@

$(BUILD_DIR)/ft_%.cpp.o:		%.cpp
	mkdir -p $(dir $@)
	$C $(CPPFLAGS) $(DEPFLAGS) -I tests -I. -D USING_FT=1 -c $< -o $@

all:				std_$(NAME) ft_$(NAME)

debug: CFLAGS += -DDEBUG -g
debug: all

std_$(NAME):		$(STD_OBJS)
	$C $^ -o $@

ft_$(NAME):			$(FT_OBJS)
	$C $^ -o $@

clean:
	$R $(FT_OBJS) $(STD_OBJS)

fclean:				clean
	$R ft_$(NAME) std_$(NAME) $(DEPS)

re:					fclean all

.PHONY: all clean fclean re

-include $(DEPS)
