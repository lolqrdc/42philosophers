# NAME
NAME = philo

INC_DIR = inc/
OBJ_DIR = obj/

# FLAGS
CC = cc
CFLAGS = -Wall -Wextra -I$(INC_DIR) -pthread
RM = rm -f

# SOURCES
SRCS = \
    src/main.c \
    src/parsing/parser.c \
	src/init/init.c \
	src/run/one_philo.c \
	src/run/philo_routine.c \
	src/run/spy_routine.c \
	src/run/threads.c \
    src/utils/for_arg.c \
	src/utils/gettime.c \
	src/utils/print.c \

# SRC TO OBJECTS
OBJS = $(SRCS:%.c=$(OBJ_DIR)%.o)

# RULES
all: $(NAME)

$(NAME): $(OBJS)
	@echo "Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Compilation terminée."

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
