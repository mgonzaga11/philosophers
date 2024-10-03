/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:34:47 by mgonzaga          #+#    #+#             */
/*   Updated: 2024/10/03 19:25:11 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data		s_data;
	t_philo		*s_philo;

	if (valid_imputs(argv, argc) == 0)
	{
		s_data = convert_inputs(argv, argc);
		s_data.start_time = get_actual_time();
		s_philo = init_philo(&s_data);
		s_data.all_philos = s_philo;
		if (s_philo != NULL)
		{
			if (s_data.philos > 1)
				init_dinner(s_data, s_philo);
			else
				unic_philo(s_philo);
		}
	}
	else
		return (0);
	finish_dinner(s_philo, &s_data, s_data.philos);
	return (0);
}
