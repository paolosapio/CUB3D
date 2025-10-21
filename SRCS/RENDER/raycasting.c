/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:29:07 by psapio            #+#    #+#             */
/*   Updated: 2025/10/21 22:31:22 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

/**
 * @brief This function makes the steps needed before entering the raycasting
 * loop.
 *
 * Inits the ray direction in each axys and based on that, calculates the
 * distance of the ray in each axys until it's first collision, the manual part
 * of the raycasting.
 *
 * @param sides the length of the sides that conform the hypotenuse until the
 * camera plane. Either positive or negative, such as the axys direction.
 * @param ray
 * @param start
 * @param m the map coordenate we are checking the collision in.
 */
void	pre_raycasting(t_ray_len sides, t_ray *ray, t_coor start, t_int_coor m)
{
	if (sides.x < 0)
	{
		ray->dir.x = -1;
		ray->hypo_supreme.x = (start.x - (float)m.x) * ray->hypo_unitary.x;
	}
	else
	{
		ray->dir.x = 1;
		ray->hypo_supreme.x = ((float)(m.x + 1) - start.x)
			* ray->hypo_unitary.x;
	}
	if (sides.y < 0)
	{
		ray->dir.y = -1;
		ray->hypo_supreme.y = (start.y - (float)m.y) * ray->hypo_unitary.y;
	}
	else
	{
		ray->dir.y = 1;
		ray->hypo_supreme.y = ((float)(m.y + 1) - start.y)
			* ray->hypo_unitary.y;
	}
}

/**
 * @brief finds the ray length to a collision thanks to the gradient and
 * pythagoras.
 *
 * @param start The player's position.
 * @param end The camera plane position, a fake end to have the vectors dir.
 * @param map The map array needed to check the collisions.
 * @return t_ray 
 */
t_ray	raycasting(t_coor start, t_coor end, t_map map)
{
	const t_ray_len		sides = {.x = end.x - start.x, .y = end.y - start.y};
	t_ray				ray;
	t_int_coor			map_coor;

	map_coor.x = (int)start.x;
	map_coor.y = (int)start.y;
	gradienteitor(sides, &ray);
	pre_raycasting(sides, &ray, start, map_coor);
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
	set_collision_point(&ray, start);
	return (ray);
}
