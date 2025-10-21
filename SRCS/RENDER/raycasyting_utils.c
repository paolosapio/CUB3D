/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasyting_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 20:21:21 by anfi              #+#    #+#             */
/*   Updated: 2025/10/21 23:04:59 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

// [../../INFO/gradient_pythagoras.png]
/**
 * @brief Calculates the unitary hypothenuse of each axys thanks to the gradient
 * 
 * - gradient || slope: The inclination of the line with respect to one axys.
 * 
 * If I move one unit in one axys, the gradient will tell how much did we move
 * in the other axys. with that information I can use pythagoras to find how
 * much the hypothenuse moves when moving one unit in each axys. 
 * 
 * These are out unitary hypotenuses.
 */
void	gradienteitor(t_ray_len sides, t_ray *ray)
{
	ray->hypo_unitary.x = (float)sqrtf(1
			+ (sides.y / sides.x) * (sides.y / sides.x));
	ray->hypo_unitary.y = (float)sqrtf(1
			+ (sides.x / sides.y) * (sides.x / sides.y));
}

/**
 * @brief Once the collision has been found, we have the ray length, the unitary
 * hypothenuse and direction of each axys.
 * 
 * So we make a rule of three to see how many unitary hypotenuses enter inside
 * the collision ray, which will give us how many units we have to move from
 * the player's position (start) to the collision coordinate.
 */
void	set_collision_point(t_ray *ray, t_coor start)
{
	ray->colision_point.x = start.x + ray->dir.x
		* (ray->colision_len / ray->hypo_unitary.x);
	ray->colision_point.y = start.y + ray->dir.y
		* (ray->colision_len / ray->hypo_unitary.y);
}
