#include <stdio.h>
#include <stdlib.h>
#include "thread_pool.h"

int tpool_init(tpool_t *tp, size_t nthreads)
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

	tp->head = 0;
	tp->tail = nthreads - 1;

	return 0;
}
