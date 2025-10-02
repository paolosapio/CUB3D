/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:07:34 by psapio            #+#    #+#             */
/*   Updated: 2025/10/02 12:07:37 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools_graphics.h"

void	clean_image(mlx_image_t *image)
{
	ft_memset(image->pixels, 0, image->width * image->height * RGBA_SIZE);
}
