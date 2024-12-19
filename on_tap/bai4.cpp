#include<stdio.h>
#include<stdlib.h>
#define MAX 5

// Cau truc hang doi (Queue)
typedef struct Queue {
    int array[MAX]; // Mang luu tru phan tu trong hang doi
    int front;      // Chi so dau hang
    int rear;       // Chi so cuoi hang
} Queue;

// Khoi tao hang doi rong
void initQueue(Queue* queue) {
    queue->front = -1; // Dau hang la -1 bieu thi hang doi rong
    queue->rear = -1;  // Cuoi hang cung -1
}

// Kiem tra hang doi rong
int isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Kiem tra hang doi day
int isFull(Queue* queue) {
    return queue->rear == MAX - 1;
}

// Them phan tu vao cuoi hang doi (enqueue)
void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Hang doi da day. Khong the them phan tu moi.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0; // Neu hang doi rong, dat front = 0
    }
    queue->rear++; // Tang rear de them phan tu moi
    queue->array[queue->rear] = value;
    printf("Da them %d vao hang doi.\n", value);
}

// Xoa phan tu dau tien khoi hang doi (dequeue)
int dequeue(Queue* queue) {
    if (isEmpty(queue) || queue->front > queue->rear) {
        printf("Hang doi rong. Khong co phan tu de xoa.\n");
        return -1;
    }
    int temp = queue->array[queue->front]; // Lay gia tri dau tien
    queue->front++; // Tang front de xoa phan tu
    if (queue->front > queue->rear) { // Neu khong con phan tu, reset hang doi
        queue->front = -1;
        queue->rear = -1;
    }
    printf("Da xoa phan tu %d khoi hang doi.\n", temp);
    return temp;
}

// Hien thi cac phan tu trong hang doi
void displayQueue(Queue* queue) {
    if (isEmpty(queue) || queue->front > queue->rear) {
        printf("Hang doi rong.\n");
        return;
    }
    printf("Cac phan tu trong hang doi: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d\t", queue->array[i]);
    }
    printf("\n");
}

// Lay ra phan tu dau tien cua hang doi (peek)
void peek(Queue* queue) {
    if (isEmpty(queue) || queue->front > queue->rear) {
        printf("Hang doi rong.\n");
        return;
    }
    printf("Phan tu dau tien cua hang doi la: %d\n", queue->array[queue->front]);
}

int main() {
    Queue queue;
    initQueue(&queue); // Khoi tao hang doi

    int value;
    do {
        // Menu lua chon thao tac voi hang doi
        printf("\n===========MENU============\n");
        printf("0. Thoat chuong trinh.\n");
        printf("1. Them phan tu vao cuoi hang doi (enqueue).\n");
        printf("2. Hien thi hang doi.\n");
        printf("3. Xoa dau hang doi (dequeue).\n");
        printf("4. Xem phan tu dau tien cua hang doi (peek).\n");
        printf("Moi ban lua chon (0 - 4): ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                exit(0); // Thoat chuong trinh
            case 1:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
            case 2:
                displayQueue(&queue);
                break;
            case 3:
                dequeue(&queue);
                break;
            case 4:
                peek(&queue);
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (1);

    return 0;
}
