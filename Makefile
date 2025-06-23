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
FUNKY_INIT = srcs/funky_init/
FUNKY_DESTROY = srcs/funky_destroy/

SRCS=	$(SRC_DIR)main.c\
		$(SRC_DIR)check_map.c\
		$(SRC_DIR)draw_game.c\
		$(SRC_DIR)get_map_info.c\
		$(SRC_DIR)map_encasketeitor.c\
		$(FUNKY_INIT)init_game_struct.c\
		$(FUNKY_INIT)init_images.c\
		$(FUNKY_DESTROY)destroy_map.c\
		$(FUNKY_DESTROY)destroy_images.c\
		$(SRC_DIR)check_line.c
	
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