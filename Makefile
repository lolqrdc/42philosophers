NAME = philosopher

INC_DIR = philo/inc/
OBJ_DIR = obj/

CC = cc
CFLAGS = -Wall -Wextra -I$(INC_DIR) -g -pthread
RM = rm -f

SRCS = \
    philo/src/main.c \
    philo/src/parsing/parser.c \
	philo/src/init/init.c \
	philo/src/run/one_philo.c \
	philo/src/run/philo_routine.c \
	philo/src/run/spy_routine.c \
	philo/src/run/threads.c \
    philo/src/utils/for_arg.c \
	philo/src/utils/gettime.c \
	philo/src/utils/print.c \

OBJS = $(SRCS:philo/%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Compilation terminée."

$(OBJ_DIR)%.o: philo/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
