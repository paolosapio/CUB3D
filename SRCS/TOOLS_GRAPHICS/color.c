/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:07:48 by psapio            #+#    #+#             */
/*   Updated: 2025/10/02 12:10:46 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

uint32_t	ft_color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	uint32_t	final_color;

	final_color = 0;
	final_color |= red << 24;
	final_color |= green << 16;
	final_color |= blue << 8;
	final_color |= alpha;
	return (final_color);
}
