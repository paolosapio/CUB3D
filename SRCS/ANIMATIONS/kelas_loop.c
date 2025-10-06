/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kelas_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:32:11 by psapio            #+#    #+#             */
/*   Updated: 2025/10/06 15:32:18 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animations.h"

#define KELAS_WIGGLE_FREQUENCY 100

void	shift_kelas_loop(unsigned long current_time, mlx_image_t **kelas_up)
{
	static unsigned long	last_wiggle_loop;

	if (current_time - last_wiggle_loop >= KELAS_WIGGLE_FREQUENCY)
	{
		if (kelas_up[0]->enabled == false && kelas_up[1]->enabled == false)
			kelas_up[0]->enabled = true;
		kelas_up[0]->enabled = !kelas_up[0]->enabled;
		kelas_up[1]->enabled = !kelas_up[1]->enabled;
		last_wiggle_loop = current_time;
	}
}
