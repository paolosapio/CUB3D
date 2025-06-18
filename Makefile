NAME = cub3D

CC = cc

CFLAGS	 =	-Wextra -Wall -Werror 
CFLAGS	+= -I inc
CFLAGS	+= -I libft
CFLAGS	+= -I include
#CFLAGS	+= -O3 #-> NO DESCOMENTAR HASTA EL FINAL PORQUE EVITA DETECTAR LEAKS
#CFLAGS	+= -lglfw

DEBUG	 =	-g3 -fsanitize=address

CPPFLAGS =	-MMD
LIBFT	= ./libft

HEADERS = -I ./inc -I $(LIBFT)  

LIBS	+=	$(LIBFT)/libft.a
MLX42	+=	MLX42/build/libmlx42.a

SRC_DIR = srcs/
LIST_DIR = list_functions/
PRINT_DIR = printers/
INIT_FUNKY = srcs/init_funky/

SRCS=	$(SRC_DIR)main.c\
		$(SRC_DIR)check_map.c\
		$(SRC_DIR)draw_game.c\
		$(SRC_DIR)get_map_info.c\
		$(INIT_FUNKY)init_game_struct.c\
		$(INIT_FUNKY)init_images.c\

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