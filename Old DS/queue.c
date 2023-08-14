#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct queueNode{
    int data;
    struct queueNode *next;
};

struct queue{
    int items[MAX_SIZE];
    struct queueNode *front;
    struct queueNode *rear;
    int size;
};

struct queue *createQueue(){
    struct queue *q = (struct queue *) malloc(sizeof(struct queue));
    q->front=0;
    q->rear=-1;
    q->size=0;
    return q;
}

void enqueue(struct queue *q, int data){
    if(isFull(q)){
        printf("Queue is full. Cannot enqueue item.\n");
        return;
    }
    q->rear= (q->rear + 1) % MAX_SIZE;
    q->items[q->rear] = data;
    q->size++;
}

int dequeue(struct queue *q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return -1;
    }

    int data = q->items[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    return data;
}

int front(struct queue *q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return -1;
    }
    return q->items[q->front];
}

int rear(struct queue *q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return -1;
    }
    return q->items[q->rear];
}

int size(struct queue *q){
    return q->size;
}
int isEmpty(struct queue *q){
    return q->size == 0;
}

int isFull(struct queue *q){
    return q->size == MAX_SIZE;
}

void clear(struct queue *q){
    q->front = 0;
    q->rear= -1;
    q->size=0;
}

void display(struct queue *q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return -1;
    }
    printf("Queue contents: ");
    int i = q->front;
    int count =0;
    while(count < q->size){
        printf("%d ", q->items[i]);
        i = (i + 1) % MAX_SIZE;
        count++;
    }
    printf("\n");
}