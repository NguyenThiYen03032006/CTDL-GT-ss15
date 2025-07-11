// CÁC BƯỚC THAO TÁC VS HÀNG ĐỢI SD DANH SÁCH LIÊN KẾT
//B1: KHAI BÁO STRUCT
//+ NODE node trong danh sách liên kết
//+ QUEUE( 2 con trỏ: front,rear)
//B2: KHỞI TẠO( initQueue)
//B3: TẠO HÀM KTRA HÀNG ĐỢI CÓ RỖNG HAY KO(isEmpty)
//B4: THÊM PHẦN TỬ VÀO HÀNG ĐỢI (enqueue)
//B5: XOÁ PHẦN TỬ (dequeue)
//- lưu ý: khi xoá phải ktra hàng đợi có rỗng hay không
//B6: HIỂN THỊ PHẦN TỬ ĐẦU TIÊN CỦA TRONG HÀNG ĐỢI (frontValue)
//B7: HIỂN THỊ CÁC PHẦN TỬ TRONG HÀNG ĐỢI
//B8: TRIỂN KHAI TRONG MAIN

#include <stdio.h>
#include <stdlib.h>

//B1: khai bao
typedef struct Node {
    int data;
    struct Node *next;
}Node;

typedef struct {
    Node* front;// tro den phan tu dau tien cua hang doi
    Node* rear;// tro den phan tu cuoi cung
}Queue;

//B2: khoi tao
void initQueue(Queue* queue) {// khong co phan tu nao thi front va rear deu la NULL
    queue->front = NULL;
    queue->rear = NULL;
}
//B3: ktra rong
int isEmptyQueue(Queue* queue) {
    return queue->front == NULL;
}//ket qua tra ve: 1=> ko co ptu, khac 1=> co ptu

//B4: them ptu
void enqueue(Queue* queue, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong the cap phat bo nho\n");
        return;
    }
    newNode->data=value;
    newNode->next=NULL;
    // neu hang doi ko co ptu-> front=rear=newNode
    if (isEmptyQueue(queue)) {
        queue->front=newNode;
        queue->rear=newNode;
    }else {//hang doi da co ptu
        queue->rear->next=newNode;// lket ptu cuoi vs newNode
        queue->rear=newNode;// cap nhat lai rear phan tu cuoi cung cua hang doi
    }
}
//B5: xoa ptu ( co the tra ve ptu moi xoa)
int dequeue(Queue* queue) {
    if (isEmptyQueue(queue)) {// ktra rong
        printf("Hang doi rong\n");
        return -1;
    }
    // gan ptu dau vs ptu ke tiep
    Node* temp = queue->front;
    int value=temp->data; // luu gtri can xoa de return  ( ham int tra ve ptu moi xoa)
    queue->front=queue->front->next;
    if (queue->front==NULL) {
        // ko con ptu thi gan rear =NULL
        queue->rear=NULL;
    }
    free(temp);
    return value;
}
//B6: hien thi ptu dau tien
int frontValue(Queue* queue) {
    if (isEmptyQueue(queue)) {
        printf("Hang doi rong\n");
        return -1;
    }
    return queue->front->data;
}
//B7: hien thi
void displayQueue(Queue* queue) {
    if (isEmptyQueue(queue)) {
        printf("Hang doi rong\n");
        return;
    }
    Node* temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
//B8: trien khai
int main(void) {
    Queue q;
    // goi ham khoi tao
    initQueue(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    printf("%d\n",dequeue(&q));
    //displayQueue(&q);
    printf("phan tu dinh la: %d\n",frontValue(&q));

    return 0;
}