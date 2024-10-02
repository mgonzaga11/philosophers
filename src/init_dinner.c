/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dinner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:35:22 by mgonzaga          #+#    #+#             */
/*   Updated: 2024/09/30 21:00:52 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	while (i < s_data.philos)
	{
		pthread_join(s_philo[i].thread, NULL);
		i++;
	}
}

void	*dinner(void *p_param)
{
	t_philo	*s_philo;
	s_philo = (t_philo *)p_param;

	while (!check_death(s_philo))
	{
		if (s_philo->s_data->times_must_eat != 0
			&& s_philo->num_meals == s_philo->s_data->times_must_eat)
			break ;
		philo_eat(s_philo);
		pthread_mutex_lock(&s_philo->mutex_num_meals);
		s_philo->num_meals += 1;
		pthread_mutex_unlock(&s_philo->mutex_num_meals);
		sleeping(s_philo);
		thinking(s_philo);
	}
	return (NULL);
}
