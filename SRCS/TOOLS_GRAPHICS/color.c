// #include "tools_graphics.h"

unsigned int	ft_color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
{
	unsigned int final_color;
	
	final_color = 0;
	final_color |= red << 24;
	final_color |= green << 16;
	final_color |= blue << 8;
	final_color |= alpha;
	return (final_color);
}

#include <stdio.h>
#include <stdint.h>

// typedef union color
// {
// 	uint32_t hex;
// 	uint8_t	 channels[5];
// } t_cooolor;


// int main(void) {
// 	t_cooolor red = {.channels[0] = 255, .channels[1] = 255, .channels[2] = 255};

// 	printf("%x\n", red.hex);

// 	printf("hex:      %p\n", &red.hex);
// 	printf("channels: %p\n", &red.channels[0]);
// 	printf("sizeof:   %ld\n", sizeof(t_cooolor));
// }

/**
 * typedef union colors
{
	unsigned int exa_color;
	unsigned
}			t_numbers;

 */

#define RED 0
#define GREEN 1
#define BLUE 2
#define ALPHA 3

typedef union colors
{
	unsigned int	exacolors;
	unsigned char	canales[4];
}			t_colors;

// int main(void)
// {
// 	t_colors	colors;

// 	colors.canales[RED] = 255;
// 	colors.canales[GREEN] = 0;
// 	colors.canales[BLUE] = 0;
// 	colors.canales[ALPHA] = 255;

// 	printf("%x\n", colors.exacolors);
// }
// 0XFFFFFFFF == 255, 255, 255, 255