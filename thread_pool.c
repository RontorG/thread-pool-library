#include <stdio.h>
#include <stdlib.h>
#include "thread_pool.h"

int tpool_init(tpool_t *tp, int nthreads, int ntasks)
{
	pthread_mutex_init(&tp->mutex, NULL);
	pthread_cond_init(&tp->cond, NULL);

	tp->workers = malloc(sizeof(*tp->workers) * nthreads);

	for (int i = 0; i < nthreads; i++) {
		if (pthread_create(&tp->workers[i].tid, NULL, tpool_worker_wait, NULL) != 0) {
			fprintf(stderr, "Failed to create threads\n");
			exit(EXIT_FAILURE);
		}
	}

	tp->tasks.task = malloc(sizeof(*tp->tasks.task) * ntasks);
	tp->tasks.head = 0;
	tp->tasks.tail = 0;

	tp->head = 0;
	tp->tail = nthreads - 1;

	return 0;
}
