/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:43:57 by psapio            #+#    #+#             */
/*   Updated: 2025/10/08 15:54:15 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include "libft.h"

//get_next_line.c

char	*get_next_line(int fd);
char	*ft_read(int fd, char *remain);
char	*clean_remain(char *remain);
int		ft_find_end_line(char *line);
char	*gnl_strnjoin(char *s1, char *s2, int n);

//get_next_line_utils.c

void	ft_free(char **str);
char	*gnl_strdup(char *s1, int n);

#endif