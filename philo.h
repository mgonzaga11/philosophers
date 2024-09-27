/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:18:17 by mgonzaga          #+#    #+#             */
/*   Updated: 2024/09/27 18:52:37 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data
{
	int	philos;
	int	time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int times_must_eat;
	pthread_mutex_t *forks;
	
}	t_data;


typedef struct s_philo
{
    int	philos;
    int number_philo;
    int id;  // ID do filósofo
    pthread_mutex_t* fork_left;  // Garfo à esquerda
    pthread_mutex_t* fork_right;  // Garfo à direita
    long last_meal_time;  // Momento da última refeição gettimeofday
    int meals_count;  // Número de refeições realizadas  apenas se o quinto argumento existir
    int time_to_die;  // Tempo máximo sem comer
    int time_to_eat;  // Tempo necessário para comer
    int time_to_sleep;  // Tempo que o filósofo dorme
    long start_time;  // Tempo de início da simulação gettimeofday
    pthread_t thread;
    
    t_data s_data;
    
}t_philo;



    

int	philo_isalpha(int c);
int check_arguments_number(int argc);
int check_numeric_arguments(char **argv);
int	valid_imputs(char **argv, int argc);
int	max_philo(char	**argv);
int min_time_die(char **argv);
t_philo    *init_philo(t_data s_data);
pthread_mutex_t *init_mutex(t_data s_data);
t_data    convert_inputs(char **argv, int argc);
void	*dinner(void *p_param);
void init_dinner(t_data s_data, t_philo *s_philo);
int	ft_atoi(const char *str);
long	get_actual_time(void);
void philo_eat(t_philo *s_philo);

#endif