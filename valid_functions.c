/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:17:09 by mgonzaga          #+#    #+#             */
/*   Updated: 2024/09/27 13:55:09 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

int	philo_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

int check_arguments_number(int argc)
{
	if(argc < 5 || argc > 6)
	{
		write(1, "Invalid arguments number", 24);
		return(1);
	}
	return(0);
	
}

int check_numeric_arguments(char **argv)
{
	int	count;
	int	i;

	i = 1;
	count = 0;

	while(argv[i] != NULL)
	{
		count = 0;
		while(argv[i][count] != '\0')
		{
			if(philo_isalpha(argv[i][count]) == 1)
			{
				write(1, "Not numeric arguments", 21);
				return(1);
			}
			count++;
		}
		i++;
	}
	return(0);
}

int	max_philo(char	**argv)
{
	int philo_number;

	philo_number = atoi(argv[1]);
	if(philo_number > 200)
	{
		write(1, "Max philo numbers", 17);
		return(1);
	}
	else
		return(0);
}

int min_time_die(char **argv)
{
	int min_time;
	
	min_time = atoi(argv[2]);
	if(min_time < 60)
	{
		write(1, "very low death time", 20);
		return(1);
	}
	else
		return(0);
}

int	valid_imputs(char **argv, int argc)
{
	if(check_arguments_number(argc) != 0)
		return(1);
	if(check_numeric_arguments(argv) != 0)
		return(1);
	//if(max_philo(argv) != 0)
		//return(1);
	//if(min_time_die(argv) != 0)
	//	return(1);
	return(0);
}

