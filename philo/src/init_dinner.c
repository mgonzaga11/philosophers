/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dinner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:35:22 by mgonzaga          #+#    #+#             */
/*   Updated: 2024/10/01 20:18:15 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	unic_philo(t_philo *s_philo)
{
	global_print(get_actual_time(), s_philo, "has taken a fork");
	usleep(s_philo->time_to_die * 1000);
	global_print(get_actual_time(), s_philo, "died");
}

void	init_dinner(t_data s_data, t_philo *s_philo)
{
	int	i;

	i = 0;
	while (i < s_data.philos)
	{
		pthread_create(&s_philo[i].thread, NULL, dinner, &s_philo[i]);
		i++;
	}
	i = 0;
	while(!check_philo_death(&s_philo[i]))
		i = (i + 1) % s_data.philos;
	i = 0;
	while (i < s_data.philos)
	{
		pthread_join(s_philo[i].thread, NULL);
		i++;
	}
}

void	*dinner(void *p_param)
{
	t_philo	*s_philo;
	int	i;
	int a;

	a = 0;
	i = 0;
	s_philo = (t_philo *)p_param;

	while (!check(s_philo->s_data))
	{
		philo_eat(s_philo);
		sleeping(s_philo);
		thinking(s_philo);
	}
	return (NULL);
}
