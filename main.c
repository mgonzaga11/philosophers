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
	
	if(valid_imputs(argv, argc) == 0)
	{
		//convert_imputs(argv, s_imputs);
		s_imputs.philos = ft_atoi(argv[1]);
		s_imputs.time_to_die = ft_atoi(argv[2]);
		s_imputs.time_to_eat = ft_atoi(argv[3]);
		s_imputs.time_to_sleep = ft_atoi(argv[4]);
		printf("Número de philos: %d\n", s_imputs.philos);
		sleep(5);
		init_philo(s_imputs, s_philo);
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
