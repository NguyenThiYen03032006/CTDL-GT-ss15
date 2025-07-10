#include <stdio.h>
#include <string.h>
#define MAX 100
#define NAME 30
typedef struct {
    char name[NAME];
    int age;
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
void enqueue(Queue* q, Customer c) {
    if (isFull(q)) {
        printf("Khong them duoc khach moi.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = c;
    q->size++;
    printf("Them khach thanh cong: %s\n", c.name);
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
        printf("  - %s : %d tuoi\n", q->data[i].name, q->data[i].age);
        i = (i + 1) % MAX;
        count++;
    }
}
int main() {
    Queue queueOld;
    initQueue(&queueOld);
    Queue queueNormal;
    initQueue(&queueNormal);
    Customer c;
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
        getchar();
        switch (choice) {
            case 1:
                printf("Nhap ten khach hang: ");
                fgets(c.name, NAME, stdin);
                c.name[strcspn(c.name, "\n")] = '\0';
                printf("Nhap tuoi khach hang: ");
                scanf("%d", &c.age);
                getchar();
                if (c.age >= 60) {
                    enqueue(&queueOld, c);
                } else {
                    enqueue(&queueNormal, c);
                }
                break;

            case 2:
                if (!isEmpty(&queueOld)) {
                    dequeue(&queueOld);
                }else if (!isEmpty(&queueNormal)) {
                    dequeue(&queueNormal);
                }else {
                    printf("Khong co khach hang cho.\n");
                }
                break;
            case 3:
                displayQueue(&queueOld);
                displayQueue(&queueNormal);
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