#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Tao node moi
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Khong the cap phat bo nho!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Them phan tu vao dau danh sach
void insertHead(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// Them phan tu vao cuoi danh sach
void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Chen 1 phan tu vao vi tri bat ky
void insertElement(Node** head, int value, int position) {
    if (position < 0) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    if (position == 0) {
        insertHead(head, value);
        return;
    }
    Node* newNode = createNode(value);
    Node* temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Vi tri vuot qua do dai danh sach!\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Duyet danh sach tu dau den cuoi
void printList(Node* head) {
    Node* temp = head;
    printf("NULL");
    while (temp != NULL) {
        printf(" <--> %d", temp->data);
        temp = temp->next;
    }
    printf(" <--> NULL\n");
}

// Duyet danh sach tu cuoi ve dau
void printListReverse(Node* head) {
    if (head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("NULL");
    while (temp != NULL) {
        printf(" <--> %d", temp->data);
        temp = temp->prev;
    }
    printf(" <--> NULL\n");
}

// Giai phong danh sach
void freeList(Node** head) {
    Node* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    int data, position;
    int choice;

    do {
        printf("\n==================== MENU ====================\n");
        printf("1. Them 1 phan tu vao dau danh sach\n");
        printf("2. Them 1 phan tu vao cuoi danh sach\n");
        printf("3. Chen 1 phan tu vao vi tri bat ky\n");
        printf("4. Hien thi danh sach tu dau den cuoi\n");
        printf("5. Hien thi danh sach tu cuoi ve dau\n");
        printf("6. Thoat\n");
        printf("============================================\n");
        printf("Moi ban chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri can them: ");
                scanf("%d", &data);
                insertHead(&head, data);
                break;
            case 2:
                printf("Nhap gia tri can them: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                break;
            case 3:
                printf("Nhap vi tri can chen: ");
                scanf("%d", &position);
                printf("Nhap gia tri can them: ");
                scanf("%d", &data);
                insertElement(&head, data, position);
                break;
            case 4:
                printf("Danh sach hien tai: \n");
                printList(head);
                break;
            case 5:
                printf("Danh sach tu cuoi ve dau: \n");
                printListReverse(head);
                break;
            case 6:
                freeList(&head);
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le, vui long chon lai!\n");
        }
    } while (choice != 6);

    return 0;
}
