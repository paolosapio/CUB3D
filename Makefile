NAME = cub3D

CC = cc

CFLAGS	 =	-Wextra -Wall -Werror 
CFLAGS	+= -I inc
CFLAGS	+= -I libft
#CFLAGS	+= -O3 #-> NO DESCOMENTAR HASTA EL FINAL PORQUE EVITA DETECTAR LEAKS
#CFLAGS	+= -lglfw

DEBUG	 =	-g3 -fsanitize=address,leak

CPPFLAGS = -MMD

LIBFT = ./libft
MLX42 = ./MLX42

HEADERS = -I ./inc -I $(LIBFT) -I $(MLX42)/include

LIBS = $(LIBFT)/libft.a
LIBS += $(MLX42)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRC_DIR = srcs/
LIST_DIR = list_functions/
PRINT_DIR = printers/
FUNKY_INIT = srcs/funky_init/
FUNKY_DESTROY = srcs/funky_destroy/
PARSER = srcs/parser/
DRAW_GAME = srcs/draw_game/


SRCS=	$(SRC_DIR)main.c\
		$(DRAW_GAME)create_images.c\
		$(FUNKY_INIT)init_game_struct.c\
		$(FUNKY_INIT)init_images.c\
		$(FUNKY_DESTROY)destroy_map.c\
		$(FUNKY_DESTROY)destroy_images.c\
		$(PARSER)check_line.c\
		$(PARSER)check_meta_map.c\
		$(PARSER)map_encasketeitor.c\
		$(PARSER)check_map.c\
		$(PARSER)check_file.c\
		$(SRC_DIR)bresenham.c



	
OBJS = $(patsubst srcs/%.c, objs/srcs/%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

all: $(NAME)

libft:
	@make -C $(LIBFT)

MLX_LIB = $(MLX42)/build/libmlx42.a

$(MLX_LIB):
	@cmake -S $(MLX42) -B $(MLX42)/build
	@cmake --build $(MLX42)/build -j4

LIBFT_LIB = $(LIBFT)/libft.a

$(LIBFT_LIB):
	@make -C $(LIBFT)

$(NAME): $(LIBFT_LIB) $(MLX_LIB) $(OBJS)
	echo $(OBJS)
	$(CC) $(DEBUG) $(CFLAGS) $(OBJS) $(LIBS)  $(HEADERS) -o $(NAME) && printf "Linking: $(NAME)\n"

objs/srcs/%.o: ./srcs/%.c
	mkdir -p $(dir $@)
	$(CC) $(DEBUG) $(CPPFLAGS) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

clean:
	rm -rf objs
	rm -rf $(MLX_LIB)/build
	make fclean -C $(LIBFT)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re libft