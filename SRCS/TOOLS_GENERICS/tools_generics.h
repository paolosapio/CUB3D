/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_generics.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:18:24 by psapio            #+#    #+#             */
/*   Updated: 2025/10/08 11:50:55 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_GENERICS_H
# define TOOLS_GENERICS_H

# include "t_game.h"
# define M_PI 3.14159265358979323846

int				tile_size_calculator(int map_height, int map_width);
float			to_radians(float degrees);
unsigned long	get_time(void);

#endif
