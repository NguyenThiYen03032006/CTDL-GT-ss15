#include <stdio.h>
#define MAX 100
typedef struct{
    int data[MAX];
    int front;
    int rear;
}Queue;
void initQueue(Queue* q) {
    q->front=0;
    q->rear=-1;
}
int main(void) {
    Queue q;
    initQueue(&q);
    return 0;
}