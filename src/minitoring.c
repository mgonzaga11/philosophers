/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:20:43 by mgonzaga          #+#    #+#             */
/*   Updated: 2024/09/30 20:45:03 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

int	check_philo_death(t_philo *s_philo)
{
	long	actual_time;
	long	time_passed;

	actual_time = get_actual_time();
	pthread_mutex_lock(&s_philo->mutex_last_meal);
	time_passed = actual_time - s_philo->last_meal_time;
	pthread_mutex_unlock(&s_philo->mutex_last_meal);
	pthread_mutex_lock(&s_philo->s_data->died_mutex);
	if (!s_philo->s_data->philo_died
		&& time_passed >= s_philo->s_data->time_to_die)
	{
		s_philo->s_data->philo_died = 1;
		pthread_mutex_lock(&s_philo->s_data->print_mutex);
		printf("%9ld %d %s\n", actual_time - s_philo->start_time,
			s_philo->number_philo, "died");
		pthread_mutex_unlock(&s_philo->s_data->print_mutex);
		pthread_mutex_unlock(&s_philo->s_data->died_mutex);
		return (1);
	}
	pthread_mutex_unlock(&s_philo->s_data->died_mutex);
	return (0);
}

void	finish_dinner(t_philo *s_philo, t_data *s_data, int total)
{
	int	i;

	i = -1;
	while (++i < total)
	{
		pthread_mutex_destroy(&s_data->forks[i]);
		pthread_mutex_destroy(&s_data->philo[i].mutex_last_meal);
		pthread_mutex_destroy(&s_data->philo[i].mutex_num_meals);
	}
	pthread_mutex_destroy(&s_data->died_mutex);
	free(s_philo);
	free(s_data->forks);
}

bool	check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->s_data->died_mutex);
	if (philo->s_data->philo_died)
	{
		pthread_mutex_unlock(&philo->s_data->died_mutex);
		return (true);
	}
	pthread_mutex_unlock(&philo->s_data->died_mutex);
	return (false);
}

void	monitoring(t_data *data)
{
	int	i;
	int	end_enten;

	end_enten = 0;
	while (1)
	{
		i = -1;
		while (++i < data->philos)
		{
			pthread_mutex_lock(&data->philo[i].mutex_num_meals);
			if (data->times_must_eat \
				&& data->philo[i].num_meals <= data->times_must_eat)
				end_enten += data->philo[i].meals_count;
			pthread_mutex_unlock(&data->philo[i].mutex_num_meals);
			if (check_philo_death(&data->philo[i]))
				return ;
		}
		if (end_enten >= (data->philos * data->times_must_eat))
			return ;
		usleep(1000);
	}
}
