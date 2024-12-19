
147 lines (126 loc) · 3.12 KB
#include <stdio.h>
#include <stdlib.h>

#define V 4 // So dinh cua do thi
#define MAX 100

// Cau truc cho danh sach lien ket (dung cho danh sach ke)
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Ham tao node moi
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Them canh vao do thi duoi dang danh sach ke
void addEdge(Node* arr[], int i, int j) {
    // Them canh tu i -> j
    Node* newNode = createNode(j);
    newNode->next = arr[i];
    arr[i] = newNode;

    // Them canh tu j -> i (vi do thi khong co huong)
    newNode = createNode(i);
    newNode->next = arr[j];
    arr[j] = newNode;
}

// Ham in ra do thi duoi dang danh sach ke
void printList(Node* arr[]) {
    for (int i = 0; i < V; i++) {
        printf("%d: ", i);
        Node* temp = arr[i];
        while (temp != NULL) {
            printf("%d \t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Khai bao ma tran ke va bien quan ly hang doi cho BFS
int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1;
int rear = -1;

// Ham them vao hang doi
void enqueue(int value) {
    if (rear == MAX - 1) {
        return;
    }
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = value;
}

// Lay phan tu khoi hang doi
int dequeue() {
    if (front == -1 || front > rear) {
        return -1;
    }
    return queue[front++];
}

// Thuat toan BFS
void BFSFunction(int start, int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    enqueue(start);
    visited[start] = 1;
    while (front <= rear) {
        int current = dequeue();
        printf("%d ", current);
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

// Thuat toan DFS (Duyet theo chieu sau) su dung de quy
void DFSFunction(int node, int n) {
    visited[node] = 1;
    printf("%d ", node);
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            DFSFunction(i, n);
        }
    }
}

int main() {
    // Khai bao mang danh sach ke cho do thi co 4 dinh
    Node* adj[V];
    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
    }
    
    // Them canh vao do thi
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    
    // In ra do thi duoi dang danh sach ke
    printList(adj);
    
    // Khai bao ma tran ke cho thuat toan BFS va DFS
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    // Them canh vao ma tran ke
    graph[0][1] = graph[1][0] = 1;
    graph[0][2] = graph[2][0] = 1;
    graph[1][2] = graph[2][1] = 1;
    graph[2][3] = graph[3][2] = 1;

    // Thuc hien BFS
    printf("\nBFS starting from node 0: ");
    BFSFunction(0, V);
    
    // Reset visited mang
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }

    // Thuc hien DFS
    printf("\nDFS starting from node 0: ");
    DFSFunction(0, V);

    return 0;
}

