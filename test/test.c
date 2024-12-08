#include <stdio.h>
#include <unistd.h>
#include "thread_pool.h"

#define NTHREADS 4
#define NTASKS 10


struct args {
	int thread_num;
	int num;
};

void count(void *args)
{
	struct args* data = (struct args*)&args;

	for (int i = 0; i <= data->num; i++) {
		printf("thread %d:\tval %d\n", data->thread_num, i);
		sleep(1);
	}


	printf("thread %d:\tDone!\n", data->thread_num);
}


int main()
{
	tpool_t tp;
	struct args fargs[NTASKS];

	tpool_init(&tp, NTHREADS, NTASKS);

	// Insert tasks in the pool
	for (int i = 0; i < NTASKS; i++) {
		fargs[i].num = 5;
		fargs[i].thread_num = tp.head;
		tpool_task_add(&tp, &count, &fargs);
	}

	tpool_destroy(&tp);

	return 0;
}
