// void	quadriculeitor_aligner(mlx_image_t *image, t_coor start, t_coor end, t_gradient m, t_map map)
// {
// 	float		ray_x_length;
// 	float		ray_y_length;
// 	(void)image;
// 	(void)map;
// 	t_coor		raycast_start_point;
// 	raycast_start_point.x = 0.0;
// 	raycast_start_point.y = 0.0;

// 	t_int_coor	map_coor;
// 	map_coor.x = start.x;
// 	map_coor.y = start.y;
	
// 	printf("start.x = %f, end.x = %f\n", start.x, end.x);
// 	printf(">>>> end.x - start.x = %f\n", end.x - start.x);
// 	if (end.x - start.x < 0)
// 	{
// 		map_coor.x = start.x;
// 		ray_x_length = ((float)map_coor.x - start.x) * m.x;
// 	}
// 	else
// 	{
// 		map_coor.x = start.x + 1;
// 		ray_x_length = -(start.x - (float)map_coor.x) * m.x;
// 	}
// 	printf("start.y = %f, end.y = %f\n", start.y, end.y);
// 	printf(">>>> end.y - start.y = %f\n", end.y - start.y);
// 	if (end.y - start.y < 0)
// 	{
// 		map_coor.y = start.y;
// 		ray_y_length = ((float)map_coor.y - start.y) * m.y;
// 	}
// 	else
// 	{
// 		map_coor.y = start.y + 1;
// 		ray_y_length = -(start.y - (float)map_coor.y) * m.y;
// 	}
// 	printf("ray_x_length = %f - gradient.x: %f\n", ray_x_length, m.x);
// 	printf("ray_y_length = %f - gradient.y: %f\n\n", ray_y_length, m.y);
// 	if (smallest_ray(ray_y_length, ray_x_length) == ray_y_length)
// 	{
// 		printf("entré aquí\n\n");
// 		mlx_put_pixel(
// 			image,
// 			(start.x + ray_y_length) * g_size_tile,
// 			map_coor.y * g_size_tile,
// 			ft_color(255, 255, 255, 255)
// 		);
// 	}
// 	else
// 	{
// 		mlx_put_pixel(
// 			image,
// 			map_coor.x * g_size_tile,
// 			(start.y + ray_x_length) * g_size_tile,
// 			ft_color(255, 255, 255, 255)
// 		);
// 	}



// }