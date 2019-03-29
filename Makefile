NAME = fillit

LIB_FOLDER = libft
LIB = $(LIB_FOLDER)/libft.a

CFLAGS = -Wall -Wextra -Werror
CC = gcc

SRCS_FOLDER = srcs
SRCS = $(SRCS_FOLDER)/main.c			\
	   $(SRCS_FOLDER)/ft_list.c			\
	   $(SRCS_FOLDER)/ft_count.c		\
	   $(SRCS_FOLDER)/ft_count_next.c	\
	   $(SRCS_FOLDER)/ft_checker.c		\
	   $(SRCS_FOLDER)/ft_parser.c		\
	   $(SRCS_FOLDER)/ft_position.c		\
	   $(SRCS_FOLDER)/ft_area.c			\
	   $(SRCS_FOLDER)/ft_piece.c		\
	   $(SRCS_FOLDER)/ft_resolver.c

OBJS_FOLDER = objs
OBJS = $(SRCS:$(SRCS_FOLDER)/%.c=$(OBJS_FOLDER)/%.o)

INC_FOLDER = includes
INCLUDES = $(INC_FOLDER)/fillit.h

all: $(NAME)

$(NAME): $(OBJS)
	@ make -C $(LIB_FOLDER)
	@ $(CC) $(CFLAGS) -I $(INCLUDES) -o $@ $^ $(LIB)
	@ echo "Compilation $(NAME) ..."\
	".............................................. \033[32m[OK]\033[0m"

$(OBJS_FOLDER):
	@ mkdir $(OBJS_FOLDER)

$(OBJS_FOLDER)/%.o: $(SRCS_FOLDER)/%.c | $(OBJS_FOLDER)
	@ $(CC) $(CFLAGS) -I $(INCLUDES) -o $@ -c $<

clean:
	@ rm -f $(OBJS)
	@ rm -rf $(OBJS_FOLDER)
	@ make -C $(LIB_FOLDER) clean
	@ echo "Delete *.o ($(NAME)) ..."\
	"............................................. \033[32m[OK]\033[0m"

fclean: clean
	@ rm -f $(NAME) $(LIB)
	@ echo "Delete $(LIB) ..."\
	"............................................ \033[32m[OK]\033[0m"
	@ echo "Delete $(NAME) ..."\
	"................................................... \033[32m[OK]\033[0m"

re: fclean all
