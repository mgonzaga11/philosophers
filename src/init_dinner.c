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
	int	i;

	i = 0;
	s_philo = (t_philo *)p_param;
	while (1)
	{
		if (s_philo->s_data->times_must_eat != 0
			&& i == s_philo->s_data->times_must_eat)
			break ;
		i = i + philo_eat(s_philo);
		sleeping(s_philo);
		thinking(s_philo);
		if (check_philo_death(s_philo) != 0)
			break ;
	}
	return (NULL);
}
