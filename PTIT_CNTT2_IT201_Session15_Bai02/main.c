#include <stdio.h>
#define MAX 5
typedef struct{
    int data[MAX];
    int front;
    int rear;
}Queue;
void initQueue(Queue* q) {
    q->front=0;
    q->rear=-1;
}
int isQueueEmpty(Queue* q){
    return q->front>q->rear;
}
int isQueueFull(Queue* q) {
    return q->rear==(MAX-1);
}
void enQueue(Queue* q, int data) {
    if(isQueueFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->rear++;
    q->data[q->rear]=data;
}
int main(void) {
    Queue q;
    initQueue(&q);
    for (int i = 0; i < MAX; i++) {
        int x;
        scanf("%d", &x);
        enQueue(&q, x);
    }
    if (isQueueEmpty(&q)) {
        printf("Them that bai");
    }else {
        printf("Them thanh cong");
    }
    return 0;
}