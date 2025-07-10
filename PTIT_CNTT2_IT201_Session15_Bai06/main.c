#include <stdio.h>

#define  MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
}Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}
int isEmptyQueue(Queue* q) {
    return q->front > q->rear;
}
int isFullQueue(Queue* q) {
    return q->rear == MAX - 1;
}
void enQueue(Queue* q, int x) {
    if (isFullQueue(q)) {
        printf("Queue is full\n");
        return;
    }
    q->rear++;
    q->data[q->rear] = x;

}
int checkQueue(Queue* q) {
    for (int i=q->front+1; i<q->rear; i++) {
        if (q->data[i] - q->data[i-1]!=1) {
            return 0;
        }
    }
    return 1;
}
int main() {
    int x;
    Queue q;
    initQueue(&q);
    printf("Nhap vao so phan tu cua hang doi: ");
    scanf("%d", &x);
    printf("Nhap phan tu vao hang doi: \n");
    for (int i=0; i<x; i++) {
        int temp;
        scanf("%d", &temp);
        enQueue(&q, temp);
    }
    if (checkQueue(&q)) {
        printf("True");
    }else {
        printf("False");
    }

    return 0;
}