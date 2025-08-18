#ifndef T_IMAGES_H
# define T_IMAGES_H

typedef struct mlx_image mlx_image_t;

typedef struct	s_images
{
	mlx_image_t	*sky;
	mlx_image_t	*floor;
	mlx_image_t	*mirilla;
	mlx_image_t	*minimap;
	mlx_image_t	*map_texture_N;
	mlx_image_t	*map_texture_S;
	mlx_image_t	*map_texture_E;
	mlx_image_t	*map_texture_O;
	mlx_image_t	*map_player;
}				t_images;

#endif