
#include "tools_graphics.h"

void	clean_image(mlx_image_t *image)
{
	ft_memset(image->pixels, 0, image->width * image->height * RGBA_SIZE);
}