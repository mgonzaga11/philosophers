/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dinner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:35:22 by mgonzaga          #+#    #+#             */
/*   Updated: 2024/09/25 20:17:05 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_dinner(t_imputs s_imputs, t_philo *s_philo)
{
	int	i;
	i = 0;
	while (i < s_imputs.philos)
	{
		pthread_create(&s_philo[i].thread, NULL, dinner, &s_philo[i]);
		i++;
	}
}


void	*dinner(void *p_param)
{
	t_philo *s_philo;
	
	s_philo = (t_philo *)p_param;
		printf("philo %i is eating", s_philo->number_philo);
	return NULL;
}
