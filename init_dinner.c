/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dinner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:35:22 by mgonzaga          #+#    #+#             */
/*   Updated: 2024/09/27 16:45:29 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_dinner(t_data s_data, t_philo *s_philo)
{
	int	i;
	i = 0;
	while (i < s_data.philos)
	{
		pthread_create(&s_philo[i].thread, NULL, dinner, &s_philo[i]);
		pthread_join(s_philo[i].thread, NULL);
		i++;
	}
}


void	*dinner_2(void *p_param)
{
	t_philo *s_philo;
	
	s_philo = (t_philo *)p_param;
		printf("philo %i is eating\n", s_philo->number_philo);
	return NULL;
}

void	*dinner(void *p_param)
{
	t_philo *s_philo;
	
	s_philo = (t_philo *)p_param;

	philo_eat(s_philo);
	return(NULL);
}
