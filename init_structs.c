/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 22:50:29 by mgonzaga          #+#    #+#             */
/*   Updated: 2024/09/21 07:34:56 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	convert_imputs(char **argv, t_imputs s_imputs)
{
	s_imputs.philos = atoi(argv[1]);
	s_imputs.time_to_die = atoi(argv[2]);
	s_imputs.time_to_eat = atoi(argv[3]);
	s_imputs.time_to_sleep = atoi(argv[4]);
	s_imputs.times_must_eat = atoi(argv[5]);
	init_mutex(&s_imputs.forks,s_imputs);
}

void	init_philo(t_imputs s_imputs)
{
	int	count;
	
	count = 0;
    t_philo* s_philo = (t_philo*)malloc(s_imputs.philos * sizeof(t_philo));
    if (!s_philo)
        return NULL; 
	while (count < s_imputs.philos)
	{
		s_philo[count].id = count;
		s_philo[count].fork_left = &s_imputs.forks[count];
		s_philo[count].fork_right = &s_imputs.forks[(count + 1) % s_imputs.philos];  
		s_philo[count].time_to_die = s_imputs.time_to_die;  
		s_philo[count].time_to_eat = s_imputs.time_to_eat;  
		s_philo[count].time_to_sleep
	}
}

void	init_mutex(pthread_mutex_t *forks, t_imputs s_imputs)
{
	int i;

	i = 0;
	while(i < s_imputs.philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;	
	}
}