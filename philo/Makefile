# NAME
NAME = philosophers

# DIRECTORIES
INCLUDE_DIR = include/
OBJECT_DIR = obj/
SOURCE_DIR = src/

# COMPILER & FLAGS
CC = gcc
CFLAGS = -Wall -Wextra -I$(INCLUDE_DIR) -g
RM = rm -f
AR = ar rcs

# SOURCES
SOURCES = main.c parser.c utils.c
SRCS = $(addprefix $(SOURCE_DIR), $(SOURCES))
OBJS = $(SRCS:$(SOURCE_DIR)%.c=$(OBJECT_DIR)%.o)

# RULES
all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

#COMPILE OBJECTS FROM SOURCE FILES
$(OBJECT_DIR)%.o: $(SOURCE_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -r $(OBJECT_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re