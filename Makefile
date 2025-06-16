NAME = cub3D

CC = cc

# CFLAGS	 =	-Wextra -Wall -Werror 
CFLAGS	+= -I inc
CFLAGS	+= -I libft
CFLAGS	+= -I include
#CFLAGS	+= -O3 #-> NO DESCOMENTAR HASTA EL FINAL PORQUE EVITA DETECTAR LEAKS
#CFLAGS	+= -lglfw

DEBUG	 =	-fsanitize=address -g3

CPPFLAGS =	-MMD
LIBFT	= ./libft

HEADERS = -I ./inc -I $(LIBFT)  

LIBS	+=	$(LIBFT)/libft.a
MLX42	+=	MLX42/build/libmlx42.a

SRC_DIR = srcs/
LIST_DIR = list_functions/
PRINT_DIR = printers/
PEPEX_DIR = srcs/pepex/

SRCS=	$(SRC_DIR)main.c\
		$(SRC_DIR)draw_map.c\
		$(SRC_DIR)gnl/get_next_line.c\
		$(SRC_DIR)gnl/get_next_line_utils.c


OBJS = $(patsubst srcs/%.c, objs/srcs/%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

all: libft $(NAME)

libft:
	@make -C $(LIBFT)

$(NAME): $(OBJS)
	echo $(OBJS)

	$(CC) $(DEBUG) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) $(MLX42) $(READLINE) $(CFLAGS) -lglfw && printf "Linking: $(NAME)\n"

objs/srcs/%.o: ./srcs/%.c
	mkdir -p $(dir $@)
	$(CC) $(DEBUG) $(CPPFLAGS) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

clean:
	rm -rf objs
	rm -rf $(LIBMLX)/build
	make fclean -C $(LIBFT)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re libft