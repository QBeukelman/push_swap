# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: qbeukelm <qbeukelm@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/02/01 11:21:13 by qbeukelm      #+#    #+#                  #
#    Updated: 2023/03/06 14:49:55 by quentinbeuk   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# ===== Names =====
NAME = push_swap.a
NANE_EXCUITABLE = push_swap


# ===== Compile =====
CC = gcc
CFLAGS = -I./INCLUDES -g -fsanitize=address


# ===== Colors =====
BOLD	:= \033[1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
RESET	:= \033[0m


# ===== Sources =====
SOURCES = push_swap_main.c \

SOURCES_ERRORS = error_checks.c \
			error_handler.c \

SOURCES_BUCKET = place_into_buckets_opps.c \
			place_into_buckets.c \
			sort_buckets.c \

SOURCES_RADIX = sort_radix.c \

SOURCES_SMALL = sort_five.c \
			sort_three.c \

SOURCES_STACK = index.c \
			initialize_struct.c \
			is_sorted.c \
			operations.c \
			print_stacks.c \
			stack.c \


# ===== Manage Directries =====
INC = inc
DIR_OBJ = obj

DIR_SOURCES = sources
DIR_SOURCES_ERRORS = sources/errors
DIR_SOURCES_BUCKETS = sources/sort_bucket
DIR_SOURCES_RADIX = sources/sort_radix
DIR_SOURCES_SMALL = sources/sort_small
DIR_SOURCES_STACK = sources/stack

O_SOURCES = $(SOURCES:%.c=$(DIR_OBJ)/$(DIR_SOURCES)/%.o)
O_SOURCES_ERRORS = $(SOURCES_ERRORS:%.c=$(DIR_OBJ)/$(DIR_SOURCES_ERRORS)/%.o)
O_SOURCES_BUCKETS = $(SOURCES_BUCKETS:%.c=$(DIR_OBJ)/$(DIR_SOURCES_BUCKETS)/%.o)
O_SOURCES_RADIX = $(SOURCES_RADIX:%.c=$(DIR_OBJ)/$(DIR_SOURCES_RADIX)/%.o)
O_SOURCES_SMALL = $(SOURCES_SMALL:%.c=$(DIR_OBJ)/$(DIR_SOURCES_SMALL)/%.o)
O_SOURCES_STACK = $(SOURCES_STACK:%.c=$(DIR_OBJ)/$(DIR_SOURCES_STACK)/%.o)

$(DIR_OBJ)/$(DIR_SOURCES)/%.o: $(DIR_SOURCES)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

$(DIR_OBJ)/$(DIR_SOURCES_ERRORS)/%.o: $(DIR_SOURCES_ERRORS)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

$(DIR_OBJ)/$(DIR_SOURCES_BUCKETS)/%.o: $(DIR_SOURCES_BUCKETS)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

$(DIR_OBJ)/$(DIR_SOURCES_RADIX)/%.o: $(DIR_SOURCES_RADIX)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

$(DIR_OBJ)/$(DIR_SOURCES_SMALL)/%.o: $(DIR_SOURCES_SMALL)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

$(DIR_OBJ)/$(DIR_SOURCES_STACK)/%.o: $(DIR_SOURCES_STACK)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@


# ===== Rules =====
all: $(NAME)

$(NAME): $(O_SOURCES) $(O_SOURCES_ERRORS) $(O_SOURCES_BUCKETS) $(O_SOURCES_RADIX) $(O_SOURCES_SMALL) $(O_SOURCES_STACK)
	@echo "$(BLUE)$(BOLD)\nCompiling library: LIBFT ...$(RESET)"
	@$(MAKE) all -C ./includes/libft/
	@cp includes/libft/libft.a $(NAME)
	@mv $(NAME) $(DIR_SOURCES)
	@$(AR) rcs $@ $^
	@ranlib $@
	@echo "$(BLUE)$(BOLD)\nCompiling program: push_swap ...$(RESET)"
	@rm $(NAME)
	@$(CC) -o $(NANE_EXCUITABLE) $(DIR_SOURCES)/$(SOURCES) $(DIR_SOURCES_ERRORS)/*.c $(DIR_SOURCES_BUCKETS)/*.c $(DIR_SOURCES_RADIX)/*.c $(DIR_SOURCES_SMALL)/*.c $(DIR_SOURCES_STACK)/*.c $(DIR_SOURCES)/$(NAME)
	@echo "$(GREEN)$(BOLD)\nCompile sucessfull!\n$(RESET)"

clean:
	@echo "$(BLUE)\nCleaning ...$(RESET)"
	@$(RM) -rf $(DIR_OBJ)
	@$(MAKE) clean -C ./includes/libft/
	@rm -rf $(EXTRA_O)
	@rm -rf $(OBJS)
	@echo "$(GREEN)$(BOLD)\nAll clean!\n$(RESET)"

fclean: clean
	@rm -rf $(NANE_EXCUITABLE)
	@$(RM) $(DIR_SOURCES)/$(NAME)
	@$(MAKE) fclean -C ./includes/libft/

re: fclean all

.PHONY: clean fclean re all