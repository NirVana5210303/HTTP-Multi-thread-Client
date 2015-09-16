
#include "queue.h"

#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <assert.h>
#include <unistd.h>

#define handle_error_en(en, msg) \
        do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

#define handle_error(msg) \
        do { perror(msg); exit(EXIT_FAILURE); } while (0)




// orig: typedef struct QueueStruct {
// but we need to remove typedef to avoid warning
typedef struct QueueStruct {
    int enqueue;
    int dequeue;
    int size;

} Queue;


Queue *queue_alloc(int size) {
    int pfd[2];
    Queue *queue = (Queue *) malloc(sizeof(Queue));

    if (pipe(pfd) < 0)
    {
        perror("pipe");
        exit(1);
    }

    queue->enqueue = pfd[1];
    queue->dequeue = pfd[0];
    queue->size = size;


    return queue;
}

void queue_free(Queue *queue) {

  assert(0 && "not implemented yet!");
}

void queue_put(Queue *queue, void *item) {

  write(queue->enqueue, &item, sizeof(item));

}

void queue_put2(Queue *queue, void *item) {

  assert(0 && "not implemented yet!");

}



void *queue_get(Queue *queue) {

  void *item;
  read(queue->dequeue, &item, sizeof(item));


  return item;

}
