NAME = philosopher

INC_DIR = philo/inc/
OBJ_DIR = obj/

CC = cc
CFLAGS = -Wall -Wextra -I$(INC_DIR) -g -pthread
RM = rm -f

SRCS = \
    philo/src/parsing/parser.c \
    philo/src/parsing/utils.c \
    philo/src/main.c \
	philo/src/init/init.c \

OBJS = $(SRCS:philo/%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Linking $(NAME)..."
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: philo/%.c
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
