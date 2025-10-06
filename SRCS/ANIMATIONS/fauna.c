/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fauna.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:31:43 by psapio            #+#    #+#             */
/*   Updated: 2025/10/06 15:32:03 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animations.h"

#define FAUNA_SWITCH_RATE 1000

void	switch_fauna(unsigned long current_time, mlx_image_t **fauna)
{
	static unsigned long	last_fauna_switch;

	if (current_time - last_fauna_switch >= FAUNA_SWITCH_RATE)
	{
		if (fauna[0]->enabled == false && fauna[1]->enabled == false)
			fauna[0]->enabled = true;
		fauna[0]->enabled = !fauna[0]->enabled;
		fauna[1]->enabled = !fauna[1]->enabled;
		last_fauna_switch = current_time;
	}
}
