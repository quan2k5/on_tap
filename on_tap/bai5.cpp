#include<stdio.h>
#include<stdlib.h>

// Dinh nghia mot nut trong cay nhi phan
typedef struct Node {
    int data;             // Gia tri cua nut
    struct Node* left;    // Con trai
    struct Node* right;   // Con phai
} Node;

// Tao mot nut moi
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node)); // Cap phat bo nho cho nut moi
    newNode->data = data;      // Gan gia tri
    newNode->left = NULL;      // Mac dinh con trai la NULL
    newNode->right = NULL;     // Mac dinh con phai la NULL
    return newNode;
}

// Them mot nut vao cay nhi phan
Node* insertNode(Node* node, int data) {
    if (node == NULL) {        // Neu cay rong, tao nut moi
        node = createNode(data);
    } else if (data < node->data) { // Neu gia tri nho hon, them vao nhanh trai
        node->left = insertNode(node->left, data);
    } else if (data > node->data) { // Neu gia tri lon hon, them vao nhanh phai
        node->right = insertNode(node->right, data);
    }
    return node;
}

// Duyet cay theo thu tu truoc (PreOrder: NLR)
void preorderTraversal(Node* node) {
    if (node != NULL) {
        printf("%d\t", node->data);      // In goc
        preorderTraversal(node->left);  // Duyet nhanh trai
        preorderTraversal(node->right); // Duyet nhanh phai
    }
}

// Duyet cay theo thu tu giua (InOrder: LNR)
void inorderTraversal(Node* node) {
    if (node != NULL) {
        inorderTraversal(node->left);   // Duyet nhanh trai
        printf("%d\t", node->data);     // In goc
        inorderTraversal(node->right);  // Duyet nhanh phai
    }
}

// Duyet cay theo thu tu sau (PostOrder: LRN)
void postorderTraversal(Node* node) {
    if (node != NULL) {
        postorderTraversal(node->left);  // Duyet nhanh trai
        postorderTraversal(node->right); // Duyet nhanh phai
        printf("%d\t", node->data);      // In goc
    }
}

// Tim kiem mot phan tu trong cay
Node* searchNode(Node* node, int value) {
    if (node == NULL) { // Neu cay rong
        return NULL;
    }
    if (value == node->data) { // Neu tim thay gia tri
        return node;
    } else if (value < node->data) { // Neu gia tri nho hon, tim ben nhanh trai
        return searchNode(node->left, value);
    } else { // Neu gia tri lon hon, tim ben nhanh phai
        return searchNode(node->right, value);
    }
}

int main() {
    Node* tree = NULL; // Khoi tao cay rong
    int choice, value;

    do {
        // Menu thao tac voi cay nhi phan
        printf("\n==========MENU==========\n");
        printf("0. Thoat chuong trinh.\n");
        printf("1. Them phan tu vao cay.\n");
        printf("2. Duyet cay theo thu tu truoc (NLR).\n");
        printf("3. Duyet cay theo thu tu giua (LNR).\n");
        printf("4. Duyet cay theo thu tu sau (LRN).\n");
        printf("5. Tim kiem mot phan tu trong cay.\n");
        printf("Moi lua chon (0-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Thoat chuong trinh.\n");
                exit(0);

            case 1:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                tree = insertNode(tree, value);
                printf("Da them %d vao cay.\n", value);
                break;

            case 2:
                printf("Duyet cay theo thu tu truoc (NLR):\n");
                preorderTraversal(tree);
                printf("\n");
                break;

            case 3:
                printf("Duyet cay theo thu tu giua (LNR):\n");
                inorderTraversal(tree);
                printf("\n");
                break;

            case 4:
                printf("Duyet cay theo thu tu sau (LRN):\n");
                postorderTraversal(tree);
                printf("\n");
                break;

            case 5:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                Node* result = searchNode(tree, value);
                if (result != NULL) {
                    printf("Tim thay %d trong cay.\n", result->data);
                } else {
                    printf("Khong tim thay %d trong cay.\n", value);
                }
                break;

            default:
                printf("Lua chon khong hop le. Moi nhap lai.\n");
        }
    } while (1);

    return 0;
}
