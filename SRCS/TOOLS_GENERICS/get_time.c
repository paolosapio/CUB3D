/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 23:13:39 by anfi              #+#    #+#             */
/*   Updated: 2025/10/07 23:13:41 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools_generics.h"

/**A function that returns in *milliseconds* the elapsed time since the last
 * time the loop_hook animation 
 */
unsigned long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (0);
	return ((time.tv_sec * 1000 + time.tv_usec / 1000));
}