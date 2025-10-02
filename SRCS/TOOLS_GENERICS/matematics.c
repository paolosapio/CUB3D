/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matematics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:18:07 by psapio            #+#    #+#             */
/*   Updated: 2025/10/02 12:18:16 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools_generics.h"

int	tile_size_calculator(int map_height, int map_width)
{
	if (map_width >= map_height)
	{
		if (HEIGHT < (WIDTH / map_width) * map_height)
			return (HEIGHT / map_height / 2);
		return (WIDTH / map_width / 2);
	}
	return (HEIGHT / map_height / 2);
}

float	to_radians(float degrees)
{
	return ((degrees / 180) * M_PI);
}
