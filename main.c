/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:34:47 by mgonzaga          #+#    #+#             */
/*   Updated: 2024/09/25 20:26:16 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "philo.h"


int	ft_atoi(const char *str)
{
	int	sign;
	int	result;
	int	i;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			sign = sign * -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}


int main(int argc, char **argv)
{
	t_imputs	s_imputs;
	t_philo		*s_philo;
	int count = 0;
	if(valid_imputs(argv, argc) == 0)
	{
		//convert_imputs(argv, s_imputs);
		s_imputs.philos = ft_atoi(argv[1]);
		s_imputs.time_to_die = ft_atoi(argv[2]);
		s_imputs.time_to_eat = ft_atoi(argv[3]);
		s_imputs.time_to_sleep = ft_atoi(argv[4]);
		//init_mutex(s_imputs.forks, s_imputs);
		int i;

	i = 0;
	s_imputs.forks = malloc(s_imputs.philos * sizeof(pthread_mutex_t));
	while(i < s_imputs.philos)
	{
		pthread_mutex_init(&s_imputs.forks[i], NULL);
		i++;	
	}
		printf("Número de philos: %d\n", s_imputs.philos);
		sleep(5);
		//init_philo(s_imputs, s_philo);
		    s_philo = (t_philo *)malloc(s_imputs.philos * sizeof(t_philo));
   if (!s_philo)
        return (0); 
	while (count < s_imputs.philos)
	{
		s_philo[count].philos = s_imputs.philos;
		s_philo[count].number_philo = count + 1;
		s_philo[count].id = count;
		s_philo[count].fork_left = &s_imputs.forks[count];
		s_philo[count].fork_right = &s_imputs.forks[(count + 1) % s_imputs.philos];  
		s_philo[count].time_to_die = s_imputs.time_to_die;  
		s_philo[count].time_to_eat = s_imputs.time_to_eat;  
		s_philo[count].time_to_sleep = s_imputs.time_to_sleep;
		count++;
	}
		printf("Philos iniciados: %d\n", s_imputs.philos);
		sleep(5);

			if(s_philo != 0)
				init_dinner(s_imputs, s_philo);
			else
				return(printf("deu errado"));
	}
	else
		return(printf("nao validou"));

}
