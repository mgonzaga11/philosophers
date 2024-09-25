/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 22:50:29 by mgonzaga          #+#    #+#             */
/*   Updated: 2024/09/25 20:27:47 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"




void	convert_imputs(char **argv, t_imputs s_imputs)
{
	s_imputs.philos = ft_atoi(argv[1]);
	s_imputs.time_to_die = ft_atoi(argv[2]);
	s_imputs.time_to_eat = ft_atoi(argv[3]);
	s_imputs.time_to_sleep = ft_atoi(argv[4]);
	//s_imputs.times_must_eat = ft_atoi(argv[5]);
	//init_mutex(s_imputs.forks, s_imputs);
}

int  init_philo(t_imputs s_imputs, t_philo *s_philo)
{
	int	count;
	
	count = 0;
    s_philo = (t_philo *)malloc(s_imputs.philos * sizeof(t_philo));
   if (!s_philo)
        return (0); 
	while (count < s_imputs.philos)
	{
		s_philo[count].philos = s_imputs.philos;
		s_philo[count].number_philo = count;
		s_philo[count].id = count;
		s_philo[count].fork_left = &s_imputs.forks[count];
		s_philo[count].fork_right = &s_imputs.forks[(count + 1) % s_imputs.philos];  
		s_philo[count].time_to_die = s_imputs.time_to_die;  
		s_philo[count].time_to_eat = s_imputs.time_to_eat;  
		s_philo[count].time_to_sleep = s_imputs.time_to_sleep;
		count++;
	}
	return(1);
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

       
                                                                                                                                               