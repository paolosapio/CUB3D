NAME = cub3D

CC = cc

CFLAGS	 =	#-Wextra -Wall -Werror 
# CFLAGS	+= -I INC
CFLAGS	+= -I libft
CFLAGS	+= -O3 #-> NO DESCOMENTAR HASTA EL FINAL PORQUE EVITA DETECTAR LEAKS //*bueno quizás en verdad si mejora mucho el rendimiento
#CFLAGS	+= -lglfw

DEBUG	 =	-g3 -fsanitize=address,leak

CPPFLAGS = -MMD

LIBFT = ./libft
MLX42 = ./MLX42

HEADERS = -I ./INC -I $(LIBFT) -I $(MLX42)/include

LIBS = $(LIBFT)/libft.a
LIBS += $(MLX42)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRC_DIR = SRCS/
FUNKY_INIT = srcs/FUNKY_INIT/
FUNKY_DESTROY = srcs/FUNKY_DESTROY/
PARSER = srcs/PARSER/
DRAW_GAME = srcs/DRAW_GAME


SRCS = $(shell find SRCS -name "*.c")

#hola paolo y yolanda:lo de arriba recordis
#de poner todos los archivos que salen en la terminal con
#find SRCS -name "*.c"



OBJS = $(patsubst SRCS/%.c, objs/srcs/%.o, $(SRCS))
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

objs/srcs/%.o: ./SRCS/%.c
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