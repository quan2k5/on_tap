#include<stdio.h>
#include<stdlib.h>
#define MAX 5

// Cau truc ngan xep
typedef struct {
    int array[MAX]; // Mang luu tru phan tu trong ngan xep
    int top;        // Chi so phan tu tren cung cua ngan xep
} Stack;

// Khoi tao ngan xep rong
void init(Stack* stack) {
    stack->top = -1; // Dat top ve -1 de bieu thi ngan xep rong
}

// Kiem tra ngan xep co rong khong
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Kiem tra ngan xep co day khong
int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

// Them phan tu vao ngan xep (Push)
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Ngan xep da day. Khong the them phan tu moi.\n");
        return;
    }
    stack->array[++(stack->top)] = value; // Tang top va luu gia tri moi vao
    printf("Da them %d vao ngan xep.\n", value);
}

// Lay phan tu tren cung cua ngan xep
void getTop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong.\n");
        return;
    }
    printf("Phan tu tren cung cua ngan xep la: %d\n", stack->array[stack->top]);
}

// Xoa phan tu tren cung khoi ngan xep (Pop)
void pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong. Khong the xoa phan tu.\n");
        return;
    }
    int removedValue = stack->array[(stack->top)--]; // Giam top va lay gia tri bi xoa
    printf("Da xoa phan tu %d khoi ngan xep.\n", removedValue);
}

// In cac phan tu trong ngan xep
void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong.\n");
        return;
    }
    printf("Cac phan tu trong ngan xep:\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->array[i]);
    }
}

int main() {
    int value;
    Stack stack;
    init(&stack); // Khoi tao ngan xep

    do {
        // Menu lua chon thao tac voi ngan xep
        printf("\n===============MENU==============\n");
        printf("1. Them phan tu vao ngan xep (Push).\n");
        printf("2. Hien thi cac phan tu trong ngan xep.\n");
        printf("3. Xoa phan tu khoi ngan xep (Pop).\n");
        printf("4. Xem phan tu tren cung cua ngan xep (Top).\n");
        printf("0. Thoat chuong trinh.\n");
        printf("Moi ban chon: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                exit(0); // Thoat chuong trinh
            case 1:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                printStack(&stack);
                break;
            case 3:
                pop(&stack);
                break;
            case 4:
                getTop(&stack);
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (1);

    return 0;
}
