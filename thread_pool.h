#ifndef _THREADPOOL_H
#define _THREADPOOL_H

#include <pthread.h>

typedef struct __tpool_worker_t {
	pthread_t tid;
	pthread_mutex_t mutex;
	pthread_cond_t cond;
	struct __tpool_worker_t *next;
} tpool_worker_t;


typedef struct __tpool_t {
	int nthreads;
	struct __tpool_worker_t *head;
	struct __tpool_worker_t *tail;
} tpool_t;


#endif
