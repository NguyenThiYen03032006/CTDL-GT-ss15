#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define NAME 31
typedef struct {
    char name[NAME];
} Customer;
typedef struct {
    Customer data[MAX];
    int front;
    int rear;
    int size;
} Queue;
void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}
int isEmpty(Queue* q) {
    return q->size == 0;
}
int isFull(Queue* q) {
    return q->size == MAX;
}
void enqueue(Queue* q, char name[]) {
    if (isFull(q)) {
        printf("Khong them duoc khach moi.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    strncpy(q->data[q->rear].name, name, NAME - 1);
    q->data[q->rear].name[NAME - 1] = '\0'; // đảm bảo null-terminated
    q->size++;
    printf("Them khach thanh cong: %s\n", name);
}
void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Khong co khach cho.\n");
        return;
    }
    printf("Dang phuc vu khach: %s\n", q->data[q->front].name);
    q->front = (q->front + 1) % MAX;
    q->size--;
}
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Khong co khach cho.\n");
        return;
    }
    printf("Danh sach khach dang cho:\n");
    int count = 0;
    int i = q->front;
    while (count < q->size) {
        printf("  - %s\n", q->data[i].name);
        i = (i + 1) % MAX;
        count++;
    }
}
int main() {
    Queue q;
    initQueue(&q);
    int choice;
    char tempName[NAME];

    do {
        printf("MENU\n");
        printf("1. Them khach hang\n");
        printf("2. Phuc vu khach hang\n");
        printf("3. Hien thi danh sach khach\n");
        printf("4. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar(); // Xóa ký tự newline sau scanf
        switch (choice) {
            case 1:
                printf("Nhap ten khach hang: ");
                fgets(tempName, NAME, stdin);
                tempName[strcspn(tempName, "\n")] = '\0';  // loại bỏ ký tự newline
                enqueue(&q, tempName);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                displayQueue(&q);
                break;
            case 4:
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 4);
    return 0;
}

