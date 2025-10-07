/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasyting_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 20:21:21 by anfi              #+#    #+#             */
/*   Updated: 2025/10/07 21:47:01 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

/**
 * @brief Calculates the gradient of each axys.
 * 
 * - gradient || slope: The inclination of the line with respect to one axys.
 * 
 * If I move one unit in one axys, the gradient will tell how much did we move
 * in the other axys. This means our unitary hypotenuse.
 */
void	gradienteitor(t_ray_len sides, t_ray *ray)
{
	ray->hypo_unitary.x = (float)sqrtf(1
			+ (sides.y / sides.x) * (sides.y / sides.x));
	ray->hypo_unitary.y = (float)sqrtf(1
			+ (sides.x / sides.y) * (sides.x / sides.y));
}

//???????
float	y_start_pos(t_ray ray)
{
	float	y_start_to_paint;

	y_start_to_paint = (HEIGHT / 2) - (ray.vertical_line / 2);
	return (y_start_to_paint);
}

void	set_collision_point(t_ray *ray, t_coor start)
{
	ray->colision_point.x = start.x + ray->dir.x
		* (ray->colision_len / ray->hypo_unitary.x);
	ray->colision_point.y = start.y + ray->dir.y
		* (ray->colision_len / ray->hypo_unitary.y);
}
