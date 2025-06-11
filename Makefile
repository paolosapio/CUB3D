NAME = cub3D

CC = cc

CFLAGS	 =	-Wextra -Wall -Werror 
CFLAGS	+= -I inc
CFLAGS	+= -I libft
CFLAGS	+= -O0
CFLAGS	+= -g3
CFLAGS	+= -Iinclude
CFLAGS	+= -lglfw

READLINE	= -lreadline

DEBUG	 =	-fsanitize=address

CPPFLAGS =	-MMD
LIBFT	= ./libft

HEADERS = -I ./inc -I $(LIBFT)  

LIBS	+=	$(LIBFT)/libft.a
MLX42	+=	MLX42/build/libmlx42.a

SRC_DIR = srcs/
LIST_DIR = list_functions/
PRINT_DIR = printers/
PEPEX_DIR = srcs/pepex/

SRCS=			\
				$(SRC_DIR)test.c

OBJS = $(patsubst srcs/%.c, objs/srcs/%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

all: libft $(NAME)

libft:
	@make -C $(LIBFT)

$(NAME): $(OBJS)
	$(CC) $(DEBUG) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) $(MLX42) $(READLINE) $(CFLAGS) && printf "Linking: $(NAME)\n"

objs/srcs/%.o: ./srcs/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

clean:
	@rm -rf objs
	@rm -rf $(LIBMLX)/build
	@make fclean -C $(LIBFT)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re libft