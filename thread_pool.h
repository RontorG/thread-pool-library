#ifndef _THREADPOOL_H
#define _THREADPOOL_H

#include <pthread.h>

typedef struct __tpool_task_t {
	struct __tpool_task_t *next;
	void (*function)(void *);
	void *arg;
} tpool_task_t;


typedef struct __tpool_task_queue_t {
	int ntasks;
	struct __tpool_task_t *head;
	struct __tpool_task_t *tail;
} tpool_task_queue_t;


typedef struct __tpool_worker_t {
	pthread_t tid;
	struct __tpool_worker_t *next;
	struct __tpool_task_t task;
} tpool_worker_t;


typedef struct __tpool_t {
	int nworkers;
	struct __tpool_worker_t *head;
	struct __tpool_worker_t *tail;
	pthread_mutex_t mutex;
	pthread_cond_t cond;
} tpool_t;


int tpool_init(size_t nthreads);
int tpool_add_task(tpool_task_t task);

#endif
