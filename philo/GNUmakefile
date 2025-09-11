# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/07 13:06:06 by itakumi           #+#    #+#              #
#    Updated: 2025/09/07 14:13:26 by itakumi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

override NAME			:= philo

override NAME_DEV		:= $(NAME)_dev

SRCS					:=	main.c \
							admin.c \
							parse_args.c \
							ut_atoi_with_error.c \
							philosophers.c \
							calc_elapsed_time.c \
							timestamp.c \
							ut_issign.c \
							ut_isspace.c \
							ut_now_time.c \
							ut_usleep.c

VPATH					= src:include:src/admin:src/parse:src/philosophers:src/utils

LIB_DIR					:= lib
LIBS					:=	libft
LIBS_INC				:= $(foreach l, $(LIBS), -I $(LIB_DIR)/$(l))
LIBS_A					:= $(foreach l, $(LIBS), $(LIB_DIR)/$(l)/$(l).a)

OBJ_DIR					:= build
OBJS					:= $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))
OBJS_DEV				:= $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))
DEPS					:= $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.d))
DEPS_DEV				:= $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.d))

TEST_DIR				:= test
TEST_SRCS				:= $(wildcard $(TEST_DIR)/**/*.c)
TEST_OBJS				:= $(TEST_SRCS:$(TEST_DIR)/%.c=$(OBJ_DIR)/$(TEST_DIR)/%.o)
TEST_PROGS				:= $(patsubst $(OBJ_DIR)/%.o, %, $(TEST_OBJS))

CC						:= cc

override CFLAGS			:= -Wall -Wextra -Werror -pedantic
CFLAGS					+= -fno-common
CFLAGS					+= -fPIC -MMD -MP

CFLAGS_OPT				:= -O3 -DNDEBUG
CFLAGS_DEV				:= -g -fsanitize=address

PTHREAD_FLAG			:= -lpthread

INC						:= -I include
INC						+= $(LIBS_INC)

.PHONY: all clean fclean re debug test test_all run_all

all: $(NAME)

$(NAME): CFLAGS += $(CFLAGS_OPT)
$(NAME): $(OBJS) $(LIBS_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS_A) $(PTHREAD_FLAG) -o $@

$(NAME_DEV): CFLAGS += $(CFLAGS_DEV)
$(NAME_DEV): $(OBJS_DEV) $(LIBS_A)
	$(CC) $(CFLAGS) $(OBJS_DEV) $(LIBS_A) $(PTHREAD_FLAG) -o $@

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

%.a:
	$(MAKE) all -C $(@D)

$(TEST_DIR)/%: $(OBJ_DIR)/$(TEST_DIR)/%.o $(filter-out $(OBJ_DIR)/main.o, $(OBJS)) $(LIBS_A)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) $< $(filter-out $(OBJ_DIR)/main.o, $(OBJS)) $(LIBS_A) $(PTHREAD_FLAG) -o $@

$(OBJ_DIR)/$(TEST_DIR)/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

-include $(DEPS)
-include $(DEPS_DEV)

debug: CFLAGS=
debug: $(NAME_DEV)

test: $(TEST_PROGS)
	@$(MAKE) run

run: $(TEST_PROGS)
	@for prog in $^; do \
		echo "--- Running Test $$(basename $$prog) ---"; \
		if [ -f $$prog ]; then \
			./$$prog \
		else \
			echo "Test $$prog not found"; \
		fi; \
	done

clean:
	$(foreach l, $(LIBS), $(MAKE) -C $(LIB_DIR)/$(l) clean;)
	rm -rf $(OBJ_DIR)

fclean: clean
	$(foreach l, $(LIBS), $(MAKE) -C $(LIB_DIR)/$(l) fclean;)
	$(foreach l, $(TEST_PROGS), rm -f $(l);)
	rm -f $(NAME) $(NAME_DEV)

re: fclean
	@$(MAKE) all

.SECONDARY:
