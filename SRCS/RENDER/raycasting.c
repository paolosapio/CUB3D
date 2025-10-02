/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:29:07 by psapio            #+#    #+#             */
/*   Updated: 2025/10/02 17:17:38 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

float	y_start_pos(t_ray ray)
{
	float	y_start_to_paint;

	y_start_to_paint = (HEIGHT / 2) - (ray.vertical_line / 2);
	return (y_start_to_paint);
}

void	set_dir(t_ray_len sides, t_ray *ray, t_coor start_pos, t_int_coor map)
{
	if (sides.x < 0)
	{
		ray->dir.x = -1;
		ray->hypo_supreme.x = (start_pos.x - (float)map.x)
			* ray->hypo_unitary.x;
	}
	else
	{
		ray->dir.x = 1;
		ray->hypo_supreme.x = ((float)(map.x + 1) - start_pos.x)
			* ray->hypo_unitary.x;
	}
	if (sides.y < 0)
	{
		ray->dir.y = -1;
		ray->hypo_supreme.y = (start_pos.y - (float)map.y)
			* ray->hypo_unitary.y;
	}
	else
	{
		ray->dir.y = 1;
		ray->hypo_supreme.y = ((float)(map.y + 1) - start_pos.y)
			* ray->hypo_unitary.y;
	}
}

void	init_ray(t_coor start_pos, t_coor end_pos, t_ray *ray, t_int_coor *map)
{
	t_ray_len	sides;

	map->x = (int)start_pos.x;
	map->y = (int)start_pos.y;
	sides.x = end_pos.x - start_pos.x;
	sides.y = end_pos.y - start_pos.y;
	ray->hypo_unitary.x = (float)sqrt(1 + (sides.y / sides.x) * (sides.y / sides.x));
	ray->hypo_unitary.y = (float)sqrt(1 + (sides.x / sides.y) * (sides.x / sides.y));
	set_dir(sides, ray, start_pos, *map);
}


t_ray	raycasting(t_coor start_pos, t_coor end_pos, t_map map)
{
	t_ray		ray;
	t_int_coor	map_coor;

	init_ray(start_pos, end_pos, &ray, &map_coor);
	while (map.array[map_coor.y][map_coor.x] != '1')
	{
		if (ray.hypo_supreme.x < ray.hypo_supreme.y)
		{
			map_coor.x += ray.dir.x;
			ray.colision_len = ray.hypo_supreme.x;
			ray.hypo_supreme.x += ray.hypo_unitary.x;
		}
		else
		{
			map_coor.y += ray.dir.y;
			ray.colision_len = ray.hypo_supreme.y;
			ray.hypo_supreme.y += ray.hypo_unitary.y;
		}
	}
	ray.colision_point.x = start_pos.x + ray.dir.x *
		(ray.colision_len / ray.hypo_unitary.x);
	ray.colision_point.y = start_pos.y + ray.dir.y *
		(ray.colision_len / ray.hypo_unitary.y);
	return (ray);
}
