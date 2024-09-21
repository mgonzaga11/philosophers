/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:34:47 by mgonzaga          #+#    #+#             */
/*   Updated: 2024/09/21 07:46:16 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "philo.h"

int main(int argc, char **argv)
{
	t_imputs	s_imputs;
	
	if(valid_imputs(argv, argc) == 0)
	{
		if(convert_imputs(argv, s_imputs) == 0 && init_philo(s_imputs) != NULL);
			if(init_dinner();)
			{
				free_all;
			}
		else
			return
	}
	else
		return(printf("nao validou"));

}
