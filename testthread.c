
#include <stdio.h>
#include <pthread.h>

pthread_t rotina[2];

struct struct_f2
{
	char 	texto[20];
	float valor;
} typedef struct_f2;

void *rotina_f1(void *p_param)
{
	int x = *((int *) p_param);
	int i = 0;
	int j = 1;

	printf("parametro: %d\n", x);
	while(i < 5)
	{
		printf("numero %d id thread: %lu\n", i, pthread_self());
		while(j <= 10)
		{
			printf("filosofo %d comendo\n", j);
			j++;
		}
		i++;
	}
	pthread_exit(0);
}



void *rotina_f2(void *p_param)
{
	int i = 0;
	struct_f2 *f2 = (struct_f2 *)p_param;
	while(i < 5)
	{
		printf("texto %s, valor: %f id thread %lu\n\n", f2->texto, f2->valor, pthread_self());
		i++;
		for (int j = 0; j < 200000; ++j) 
		{

		}
	}
	pthread_exit(NULL);
}

int main()
{
	printf("iniciando...\n\n");
	int parametro = 1;
	struct_f2 f2 = {"banana", 1.23};
	
	

	pthread_create(&rotina[0], NULL, rotina_f1, &parametro);
	pthread_create(&rotina[1], NULL, rotina_f2, &f2);

	printf("id da thread 1: %lu\n ", rotina[0]);
	printf("id da thread 2: %lu\n ", rotina[1]);

	int rc = (int)pthread_join(rotina[0], NULL);
	rc = (int)pthread_join(rotina[1], NULL);

	printf("finalizado com rc %d \n", rc);
}