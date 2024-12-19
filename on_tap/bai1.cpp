#include<stdio.h>
#include<stdlib.h>

// Dinh nghia mot Node
typedef struct Node {
    int data; // Phan du lieu cua node
    struct Node* next; // Con tro tro den node tiep theo
} Node;

// Tao mot Node
Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Khong the cap phat bo nho!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Them phan tu vao dau danh sach
void insertHead(Node** head, int value) {
    Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

// Them phan tu vao cuoi danh sach
void insertEnd(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Them phan tu vao vi tri bat ky
void insertElement(Node** head, int value, int position) {
    Node* newNode = createNode(value);
    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    Node* temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Vi tri khong hop le!\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Xoa phan tu o dau danh sach
void deleteHead(Node** head) {
    if (*head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Xoa phan tu o cuoi danh sach
void deleteEnd(Node** head) {
    if (*head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Duyet danh sach
void printList(Node* head) {
    if (head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ---> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Tim kiem phan tu theo gia tri
void searchElement(Node* head, int value) {
    int position = 0;
    int found = 0;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Gia tri %d duoc tim thay tai vi tri %d\n", value, position);
            found = 1;
        }
        temp = temp->next;
        position++;
    }
    if (!found) {
        printf("Gia tri %d khong ton tai trong danh sach.\n", value);
    }
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
    int choice, value, position;

    do {
        printf("\n========== MENU =========\n");
        printf("1. Them 1 phan tu vao dau danh sach\n");
        printf("2. Them 1 phan tu vao cuoi danh sach\n");
        printf("3. Them 1 phan tu vao vi tri bat ky\n");
        printf("4. Xoa phan tu o dau danh sach\n");
        printf("5. Xoa phan tu o cuoi danh sach\n");
        printf("6. Xem danh sach\n");
        printf("7. Tim kiem phan tu theo gia tri\n");
        printf("8. Thoat\n");
        printf("===========================\n");
        printf("Moi ban chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                insertHead(&head, value);
                break;
            case 2:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;
            case 3:
                printf("Nhap vi tri can them: ");
                scanf("%d", &position);
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                insertElement(&head, value, position);
                break;
            case 4:
                deleteHead(&head);
                break;
            case 5:
                deleteEnd(&head);
                break;
            case 6:
                printf("Danh sach hien tai: \n");
                printList(head);
                break;
            case 7:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                searchElement(head, value);
                break;
            case 8:
                freeList(&head);
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le, vui long chon lai!\n");
        }
    } while (choice != 8);

    return 0;
}
