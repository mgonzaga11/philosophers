/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 22:50:29 by mgonzaga          #+#    #+#             */
/*   Updated: 2024/09/29 06:20:46 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



t_data	convert_inputs(char **argv, int argc)
{
	t_data	s_data;
	
	s_data.philos = ph_atoi(argv[1]);
	s_data.time_to_die = ph_atoi(argv[2]);
	s_data.time_to_eat = ph_atoi(argv[3]);
	s_data.time_to_sleep = ph_atoi(argv[4]);
	if(argc == 6)
		s_data.times_must_eat = ph_atoi(argv[5]);
	else
		s_data.times_must_eat = 0;
	s_data.forks = init_mutex(s_data);
	s_data.philo_died = 0;
	pthread_mutex_init(&s_data.died_mutex, NULL);
	return(s_data);
}

t_philo  *init_philo(t_data *s_data)
{
	int	count;
	t_philo *s_philo;
	
	count = 0;
    s_philo = (t_philo *)malloc(s_data->philos * sizeof(t_philo));
   if (!s_philo)
        return (NULL); 
	while (count < s_data->philos)
	{
		s_philo[count].philos = s_data->philos;
		s_philo[count].number_philo = count + 1;
		s_philo[count].fork_left = &s_data->forks[count];
		s_philo[count].fork_right = &s_data->forks[(count + 1) % s_data->philos];  
		s_philo[count].s_data = s_data;
		s_philo[count].last_meal_time = 0;
		s_philo[count].thread = 0;
		s_philo[count].time_to_die = s_data->time_to_die;
		s_philo[count].time_to_eat = s_data->time_to_eat;
		s_philo[count].time_to_sleep = s_data->time_to_sleep;
		s_philo[count].times_must_eat = s_data->times_must_eat;
		s_philo[count].start_time = s_data->start_time;
		count++;
	}
	return(s_philo);
}

pthread_mutex_t *init_mutex(t_data s_data)
{
	int i;
	pthread_mutex_t *forks;

	i = 0;
	forks = malloc(s_data.philos * sizeof(pthread_mutex_t));
	while(i < s_data.philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;	
	}
	return(forks);
}

       
                                                                                                                                               