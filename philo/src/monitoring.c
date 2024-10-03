/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:20:43 by mgonzaga          #+#    #+#             */
/*   Updated: 2024/10/03 20:08:19 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check(t_data *s_data)
{
	int	someone_died;

	pthread_mutex_lock(&s_data->died_mutex);
	someone_died = s_data->philo_died;
	pthread_mutex_unlock(&s_data->died_mutex);
	return (someone_died);
}

int	check_philo_death(t_philo *s_philo)
{
	pthread_mutex_lock(&s_philo->s_data->died_mutex);
	pthread_mutex_lock(&s_philo->last_meal_mutex);
	if (!s_philo->s_data->philo_died
		&& (get_actual_time() - s_philo->last_meal_time) > s_philo->time_to_die)
	{
		pthread_mutex_unlock(&s_philo->last_meal_mutex);
		s_philo->s_data->philo_died = 1;
		pthread_mutex_lock(&s_philo->s_data->print_mutex);
		printf("%9ld %d %s\n", get_actual_time() - s_philo->start_time,
			s_philo->number_philo, "died");
		pthread_mutex_unlock(&s_philo->s_data->print_mutex);
		pthread_mutex_unlock(&s_philo->s_data->died_mutex);
		return (1);
	}
	else if (s_philo->s_data->philo_died == 1)
	{
		pthread_mutex_unlock(&s_philo->s_data->died_mutex);
		pthread_mutex_unlock(&s_philo->last_meal_mutex);
		return (1);
	}
	pthread_mutex_unlock(&s_philo->last_meal_mutex);
	pthread_mutex_unlock(&s_philo->s_data->died_mutex);
	return (0);
}

int	everyone_is_full(t_philo *s_philo)
{
	int	i;

	i = 0;
	// if (s_philo->times_must_eat == 0)
	// {
	// 	pthread_mutex_lock(&s_philo->s_data->died_mutex);
	// 	s_philo->s_data->philo_died = 1;
	// 	pthread_mutex_unlock(&s_philo->s_data->died_mutex);
	// 	return (1);
	// }
	while (i < s_philo->philos)
	{
		if (s_philo[i].count_meals < s_philo[i].times_must_eat)
			return (0);
		i++;
	}
	pthread_mutex_lock(&s_philo->s_data->died_mutex);
	s_philo->s_data->philo_died = 1;
	pthread_mutex_unlock(&s_philo->s_data->died_mutex);
	return (1);
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
