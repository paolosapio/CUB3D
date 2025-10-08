/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:42:45 by psapio            #+#    #+#             */
/*   Updated: 2025/10/08 15:47:13 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>

# include "t_map.h"
# include "t_player.h"
# include "t_game.h"
# include "../SRCS/INIT_GAME/init_game.h"
# include "../SRCS/INPUT_KEYS/input_keys.h"

/* DEFINES DE ft_putendl_fd */

# define USAGE "\033[1;31mERROR: Invalid arguments\
\033[0m → Usage: ./cub3D maps/map.cub\n\
\033[0;35mYou can find different maps inside the map folder\033[0m"

/*   COLORS PRINTF  */

# define STD "\033[0m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define PURPLE "\033[0;35m"
# define BLUE "\033[1;36m"
# define ORANG "\033[1;33m"
# define WHITE "\033[1;37m"

#endif