#pragma once
#include <stdlib.h>


typedef struct queueNode {
    struct queueNode* next;
    void* value;
} *QueueNode;

typedef struct queue {
    QueueNode head;
    QueueNode tail;
    int numNodes;
} *Queue;



Queue newQueue();
QueueNode newQueueNode(void* data);

void queueAddNode(Queue queue, void* data);
void* queuePop(Queue queue);

void deleteQueueNode(QueueNode queueNode);
void deleteQueue(Queue queue);
