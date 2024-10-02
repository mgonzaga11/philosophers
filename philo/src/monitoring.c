/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:20:43 by mgonzaga          #+#    #+#             */
/*   Updated: 2024/10/02 17:32:41 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		check(t_data *s_data)
{
	int someone_died;
	
	pthread_mutex_lock(&s_data->died_mutex);
	someone_died = s_data->philo_died;
	pthread_mutex_unlock(&s_data->died_mutex);
	return(someone_died);
}

int	check_philo_death(t_philo *s_philo)
{
	long	actual_time;
	long	time_passed;

	actual_time = get_actual_time();
	if(s_philo->s_data->philos == 1)
	{
		unic_philo(s_philo);
		return(1);
	}
	pthread_mutex_lock(&s_philo->s_data->meals_count_mutex);
	if(s_philo->s_data->times_must_eat != 0 && 
		s_philo->s_data->count_meals == (s_philo->s_data->times_must_eat * s_philo->philos))
	{
	 	s_philo->s_data->philo_died = 1;
		pthread_mutex_unlock(&s_philo->s_data->meals_count_mutex);
	 	return(1);
	}
	pthread_mutex_unlock(&s_philo->s_data->meals_count_mutex);
	pthread_mutex_lock(&s_philo->last_meal_mutex);
	time_passed = actual_time - s_philo->last_meal_time;
	pthread_mutex_unlock(&s_philo->last_meal_mutex);
	pthread_mutex_lock(&s_philo->s_data->died_mutex);
	if (!s_philo->s_data->philo_died
		&& (get_actual_time() - s_philo->last_meal_time) > s_philo->time_to_die)
	{
		s_philo->s_data->philo_died = 1;
		pthread_mutex_lock(&s_philo->s_data->print_mutex);
		printf("%9ld %d %s\n", actual_time - s_philo->start_time,
			s_philo->number_philo, "died");
		pthread_mutex_unlock(&s_philo->s_data->print_mutex);
		pthread_mutex_unlock(&s_philo->s_data->died_mutex);
		return (1);
	}
	else if (s_philo->s_data->philo_died == 1)
	{
		pthread_mutex_unlock(&s_philo->s_data->died_mutex);
		return (1);
	}
	pthread_mutex_unlock(&s_philo->s_data->died_mutex);
	return (0);
}

void	finish_dinner(t_philo *s_philo, t_data *s_data, int total)
{
	int	i;

	i = 0;
	while (i < total)
		pthread_mutex_destroy(&s_data->forks[i++]);
	pthread_mutex_destroy(&s_data->died_mutex);
	free(s_philo);
	free(s_data->forks);
}

