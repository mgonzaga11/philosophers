/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   times.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:31:59 by mgonzaga          #+#    #+#             */
/*   Updated: 2024/09/27 16:35:41 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_actual_time(void)
{
	struct timeval	time;

	gettimeofday(&time, 0);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

