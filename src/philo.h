/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:18:17 by mgonzaga          #+#    #+#             */
/*   Updated: 2024/09/30 20:36:28 by mgonzaga         ###   ########.fr       */
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
    long start_time;
    int philo_died;
    pthread_mutex_t died_mutex;
    pthread_mutex_t print_mutex;
}	t_data;

typedef struct s_philo
{
    int	philos;
    int number_philo;
    int	time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int times_must_eat;
    pthread_mutex_t* fork_left;
    pthread_mutex_t* fork_right; 
    long last_meal_time; 
    int meals_count;  
    pthread_t thread;
    t_data *s_data;
    long start_time;
    
}t_philo;

int philo_isalpha(int c);
int check_arguments_number(int argc);
int check_numeric_arguments(char **argv);
int valid_imputs(char **argv, int argc);
int max_philo(char	**argv);
int min_time_die(char **argv);
t_philo *init_philo(t_data *s_data);
pthread_mutex_t *init_mutex(t_data s_data);
t_data  convert_inputs(char **argv, int argc);
void    *dinner(void *p_param);
void    init_dinner(t_data s_data, t_philo *s_philo);
int	    ph_atoi(const char *str);
long    get_actual_time(void);
int     philo_eat(t_philo *s_philo);
void	sleeping(t_philo *s_philo);
void	thinking(t_philo *s_philo);
void    global_print(long time, t_philo *s_philo, char *action);
int     check_philo_death(t_philo *s_philo);
void    finish_dinner(t_philo *s_philo, t_data *s_data, int total);

#endif