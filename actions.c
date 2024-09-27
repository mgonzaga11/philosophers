/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:59:08 by mgonzaga          #+#    #+#             */
/*   Updated: 2024/09/27 19:26:10 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
 
void philo_eat(t_philo *s_philo)
{
	if(s_philo->number_philo % 2 == 0)
	{
		pthread_mutex_lock(s_philo->fork_left);
		printf("philo %i pegou o garfo esquerdo\n", s_philo->number_philo);
		pthread_mutex_lock(s_philo->fork_right);
		printf("philo %i pegou o direito\n", s_philo->number_philo);
		printf("esta comendo\n");
		usleep(s_philo->time_to_eat * 1000);
		pthread_mutex_unlock(s_philo->fork_left);
		pthread_mutex_unlock(s_philo->fork_right);
		printf("parou de comer\n");
	}
	else if(s_philo->number_philo % 2 != 0)
	{
		pthread_mutex_lock(s_philo->fork_right);
		printf("philo %i pegou o direito\n", s_philo->number_philo);
		pthread_mutex_lock(s_philo->fork_left);
		printf("philo %i pegou o garfo esquerdo\n", s_philo->number_philo);
		printf("esta comendo\n");
		usleep(s_philo->time_to_eat * 1000);
		pthread_mutex_unlock(s_philo->fork_left);
		pthread_mutex_unlock(s_philo->fork_right);
		printf("parou de comer\n");
	}
}

void	sleeping(t_philo *s_philo)
{
	global_print(get_actual_time(), s_philo, "is sleeping");
	usleep(philo->table->time_to_sleep * 1000);
}
