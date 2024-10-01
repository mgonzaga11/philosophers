/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:59:08 by mgonzaga          #+#    #+#             */
/*   Updated: 2024/10/01 16:49:42 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eat(t_philo *s_philo)
{
	if (s_philo->number_philo % 2 == 0)
	{
		pthread_mutex_lock(s_philo->fork_right);
		global_print(get_actual_time(), s_philo, "has taken a fork");
		pthread_mutex_lock(s_philo->fork_left);
		global_print(get_actual_time(), s_philo, "has taken a fork");
		s_philo->last_meal_time = get_actual_time();
		global_print(get_actual_time(), s_philo, "is eating");
		usleep(s_philo->s_data->time_to_eat * 1000);
		pthread_mutex_unlock(s_philo->fork_left);
		pthread_mutex_unlock(s_philo->fork_right);
	}
	else if (s_philo->number_philo % 2 != 0)
	{
		pthread_mutex_lock(s_philo->fork_left);
		global_print(get_actual_time(), s_philo, "has taken a fork");
		pthread_mutex_lock(s_philo->fork_right);
		global_print(get_actual_time(), s_philo, "has taken a fork");
		pthread_mutex_lock(&s_philo->last_meal_mutex);
		s_philo->last_meal_time = get_actual_time();
		pthread_mutex_unlock(&s_philo->last_meal_mutex);
		global_print(get_actual_time(), s_philo, "is eating");
		usleep(s_philo->s_data->time_to_eat * 1000);
		pthread_mutex_unlock(s_philo->fork_right);
		pthread_mutex_unlock(s_philo->fork_left);
	}
	return (1);
}

void	sleeping(t_philo *s_philo)
{
	global_print(get_actual_time(), s_philo, "is sleeping");
	usleep(s_philo->time_to_sleep * 1000);
}

void	thinking(t_philo *s_philo)
{
	global_print(get_actual_time(), s_philo, "is thinking");
}

void	global_print(long time, t_philo *s_philo, char *action)
{
	pthread_mutex_lock(&s_philo->s_data->died_mutex);
	if (s_philo->s_data->philo_died == 0)
	{
		pthread_mutex_lock(&s_philo->s_data->print_mutex);
		printf("%9ld %d %s\n", time - s_philo->start_time,
				s_philo->number_philo, action);
		pthread_mutex_unlock(&s_philo->s_data->print_mutex);
	}
	pthread_mutex_unlock(&s_philo->s_data->died_mutex);
}
