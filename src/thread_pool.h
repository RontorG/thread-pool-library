#ifndef _THREADPOOL_H
#define _THREADPOOL_H

#include <pthread.h>

typedef struct __tpool_task_t {
	void (*function)(void *);
	void *arg;
} tpool_task_t;


typedef struct __tpool_task_queue_t {
	int size;
	int todo;
	int head;
	int tail;
	struct __tpool_task_t *task;
} tpool_task_queue_t;


typedef struct __tpool_worker_t {
	pthread_t tid;
	struct __tpool_task_t task;
} tpool_worker_t;


typedef struct __tpool_t {
	int head;
	int tail;
	int nworkers;
	pthread_cond_t cond;
	pthread_mutex_t mutex;
	struct __tpool_worker_t *workers;
	struct __tpool_task_queue_t tasks;
} tpool_t;



int tpool_init(tpool_t *tp, int nthreads, int ntasks);
void *tpool_worker_instance(tpool_t *tp);
int tpool_task_add(tpool_t *tp, void(*func)(void*), void* arg);
int tpool_task_isfull(tpool_t *tp);
int tpool_task_isempty(tpool_t *tp);

#endif
