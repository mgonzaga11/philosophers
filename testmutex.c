/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmutex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:06:48 by mgonzaga          #+#    #+#             */
/*   Updated: 2024/09/24 19:56:52 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t rotina[2];
pthread_mutex_t lock;

struct struct_f2
{
	char 	texto[20];
	float valor;
} typedef struct_f2;

void *rotina_f1(void *p_param)
{
	
	int *x = (int *) p_param;
	srand(1);
	int i = 0;

	//printf("parametro: %d\n", *x);
	while(i < 3)
	{
		pthread_mutex_lock(&lock);
		int tmp = *x / 2;
		tmp++;
		printf("f1 id : %i, valor %d\n\n", tmp, *x);
		sleep(rand() % 1);
		*x = tmp;
		i++;
		pthread_mutex_unlock(&lock);
	}
	pthread_exit(0);
}

void *rotina_f2(void *p_param)
{
	int *x = (int *) p_param;
	srand(1);
	int i = 0;
	//printf("parametro: %d\n", *x);
	while(i < 3)
	{
		pthread_mutex_lock(&lock);
		int tmp = *x / 4;
		tmp++;
		printf("f2 id : %i, valor %d\n\n", tmp, *x);
		sleep(rand() % 1);
		*x = tmp;
		i++;
		pthread_mutex_unlock(&lock);
	}
	pthread_exit(0);
}


int main()
{
	printf("iniciando...\n\n");
	int valor = 1000000;

	pthread_create(&rotina[0], NULL, rotina_f1, &valor);
	pthread_create(&rotina[1], NULL, rotina_f2, &valor);

	// pthread_join(rotina[0], NULL);
	// pthread_join(rotina[1], NULL);
	sleep(3);
	printf("valor final %d\n\n", valor);
	printf("ENCERRANDO,\n\n");
	return(0);
}