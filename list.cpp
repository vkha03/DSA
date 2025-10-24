#include<stdio.h>

// Khai bao cau truc node
typedef struct tagnode{
int data;
tagnode *next;
} Node; // Dat ten kieu du lieu cau truc node

// Khai bao cau truc list
typedef struct nodelist{
Node *pHead;
Node *pTail;
} List; // Dat ten kieu du lieu cau truc list

// Ham tao node kieu du lieu tra ve la mot con tro node
Node *createnode(int x){
    Node *p;
    p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

// Ham tao mot cau truc list null
void createnulllist(List &L){
L.pHead = NULL;
L.pTail = NULL;
}

// Them node vao list
void addTail(List &L, Node* p) {
    if (L.pHead == NULL) {    // danh sách rỗng
        L.pHead = L.pTail = p;
    } else {
        L.pTail->next = p;    // nối node mới vào cuối
        L.pTail = p;          // cập nhật pTail
    }
}

// Print list node
void printList(List L) {
    Node* p = L.pHead;
    while (p != NULL) {
        if(p->data == 20) printf("Da tim thay");
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(){
List L;
createnulllist(L);
int arr[] = {10, 20, 30, 40, 50};
int n = sizeof(arr) / sizeof(arr[0]);
for(int i = 0; i < n; i++){
    addTail(L, createnode(arr[i]));
}
printList(L);
}
