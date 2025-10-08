/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_coordinate.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:47:20 by psapio            #+#    #+#             */
/*   Updated: 2025/10/08 15:48:12 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_COORDINATE_H
# define T_COORDINATE_H

typedef struct s_coor
{
	float	x;
	float	y;
}				t_coor;

typedef t_coor	t_vector;

typedef struct s_segment
{
	t_coor	start;
	t_coor	end;
	float	size;
}				t_segment;

typedef struct s_int_coor
{
	int	x;
	int	y;
}				t_int_coor;

#endif
