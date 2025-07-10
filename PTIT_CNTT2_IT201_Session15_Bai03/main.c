#include <stdio.h>
#define MAX 5

typedef struct {
    int data[MAX];
    int front;
    int rear;
}Queue;
void initQueue(Queue* queue) {
    queue->front = 0;
    queue->rear = -1;
}
int isEmptyQueue(Queue* queue) {
    return queue->rear < queue->front;
}
int main() {
    Queue q;
    initQueue(&q);
    // q.data[0] = 1;
    // q.rear++;
    if (isEmptyQueue(&q)) {
        printf("False");
    }else {
        printf("True");
    }
}