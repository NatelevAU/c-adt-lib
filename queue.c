#include "queue.h"



Queue newQueue() {
    Queue queue = malloc(sizeof(struct queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->numNodes = 0;
    return queue;
}

QueueNode newQueueNode(void* data) {
    QueueNode queueNode = malloc(sizeof(struct queueNode));
    queueNode->next = NULL;
    queueNode->data = data;
    return queueNode;
}



void queueAddNode(Queue queue, void* data) {
    QueueNode newNode = newQueueNode(data);
    if (queue->numNodes == 0) {
        queue->head = newNode;
        queue->tail = newNode;
    } else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
    queue->numNodes++;
}

void* queuePop(Queue queue) {
    if (queue->head == NULL) return NULL;
    void* value;
    QueueNode currNode = queue->head;
    if (currNode->next == NULL) {
        value = currNode->data;
        queue->head = NULL;
        queue->tail = NULL;
    } else {
        for (; currNode->next->next != NULL; currNode = currNode->next);
        queue->tail = currNode;
        currNode = currNode->next;
        queue->tail->next = NULL;
        value = currNode->data;
    }
    deleteQueueNode(currNode);
    queue->numNodes--;
    return value;
}



void deleteQueueNode(QueueNode queueNode) {
    free(queueNode);
}

void deleteQueue(Queue queue) {
    QueueNode currNode = queue->head;
    QueueNode prevNode;
    while (currNode) {
        prevNode = currNode;
        currNode = currNode->next;
        deleteQueueNode(prevNode);
    }
    free(queue);
}
