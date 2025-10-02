/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:33:22 by psapio            #+#    #+#             */
/*   Updated: 2025/10/02 16:30:00 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools_graphics.h"
#include <stdio.h>
#include <math.h>

void	init_segment(t_segment *s, int tile_size)
{
	if (s->end.x < 0 || s->end.x == INFINITY)
		s->end.x = 0;
	if (s->end.y < 0 || s->end.y == INFINITY)
		s->end.y = 0;
	s->start.x = (int)(s->start.x * tile_size);
	s->start.y = (int)(s->start.y * tile_size);
	s->end.x = (int)(s->end.x * tile_size);
	s->end.y = (int)(s->end.y * tile_size);
}

void	init_bresenham(t_bresenham	*b, t_segment *s)
{
	b->dx = (int)fabsf(s->end.x - s->start.x);
	b->dy = (int)fabsf(s->end.y - s->start.y);
	b->sx = -1;
	b->sy = -1;
	if (s->start.x < s->end.x)
		b->sx = 1;
	if (s->start.y < s->end.y)
		b->sy = 1;
	b->err = b->dx - b->dy;
	b->x = s->start.x;
	b->y = s->start.y;
}

void	bresenham_algorithm(mlx_image_t *image, t_segment s,
		uint32_t color, int tile_size)
{
	t_bresenham	b;

	init_segment(&s, tile_size);
	init_bresenham(&b, &s);
	while (1)
	{
		if (b.x >= 0 && b.y >= 0 && b.x < (int)image->width
			&& b.y < (int)image->height)
			mlx_put_pixel(image, b.x, b.y, color);
		if ((b.x == s.end.x && b.y == s.end.y) || b.x < 0 || b.y < 0
			|| b.x > (int)image->width || b.y > (int)image->height)
			break ;
		b.e2 = 2 * b.err;
		if (b.e2 > -b.dy)
		{
			b.err -= b.dy;
			b.x += b.sx;
		}
		if (b.e2 < b.dx)
		{
			b.err += b.dx;
			b.y += b.sy;
		}
	}
}
