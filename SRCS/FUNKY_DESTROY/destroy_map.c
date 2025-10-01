/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:42:14 by psapio            #+#    #+#             */
/*   Updated: 2025/10/01 19:42:21 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funky_destroy.h"

void	destroy_map(t_map *map)
{
	if (map && map->array)
		free_double_pointer(map->array);
}
