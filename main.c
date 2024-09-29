/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:34:47 by mgonzaga          #+#    #+#             */
/*   Updated: 2024/09/29 06:21:54 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "philo.h"


int	ph_atoi(const char *str)
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

int	main(int argc, char **argv)
{
	t_data		s_data;
	t_philo		*s_philo;

	if (valid_imputs(argv, argc) == 0)
	{
		s_data = convert_inputs(argv, argc);
		s_data.start_time = get_actual_time();
		s_philo = init_philo(&s_data);
		if (s_philo != NULL)
		{
			if (s_data.philos > 1)
				init_dinner(s_data, s_philo);
			else
				printf("so tem 1 philo");
		}
	}
	else
		return (0);
	finish_dinner(s_philo, &s_data, s_data.philos);
	return (0);
}
