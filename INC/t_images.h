#ifndef T_IMAGES_H
# define T_IMAGES_H

typedef struct mlx_image mlx_image_t;
typedef struct mlx_texture mlx_texture_t;

typedef struct	s_images
{
	mlx_image_t		*sky;
	mlx_image_t		*floor;
	mlx_image_t		*gradient_bgr;
	mlx_image_t		*mirilla;
	mlx_image_t		*background_map;
	mlx_image_t		*map_ray;
	mlx_image_t		*greco_map[8];
	mlx_image_t		*map_greco;
	mlx_image_t		*map_sand;
	mlx_image_t		*map_rock;
	mlx_image_t		*cuadricula;
	mlx_image_t		*tridy;
	mlx_image_t		*bubble_array[20];
	mlx_image_t		*start[2];
	mlx_image_t		*fauna[2];
	mlx_image_t		*ambient;
	mlx_image_t		*info;
	mlx_image_t		*frame[6];




	mlx_image_t	*kelas_open;
	mlx_image_t	*kelas_closed;
	mlx_image_t	*kelas_sx;
	mlx_image_t	*kelas_dx;
	mlx_image_t	*kelas_up[2];
	// mlx_image_t	*waves;

	mlx_texture_t	*wall_alga;
	mlx_texture_t	*map_texture_N;
	mlx_texture_t	*map_texture_S;
	mlx_texture_t	*map_texture_E;
	mlx_texture_t	*map_texture_W;

	mlx_texture_t	*waves[2];


	mlx_texture_t	*greco_texture;
}				t_images;

#endif