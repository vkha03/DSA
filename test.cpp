#include<stdio.h>

typedef struct Node{
    int data;
    Node *next;
} Node;

typedef struct List{
    Node *pHead;
    Node *pTail;
} List;

void createNullList(List &l){
    l.pHead = NULL;
    l.pTail = NULL;
}

Node *createNode(int data){
    Node *p;
    p = new Node;
    p->data = data;
    p->next = NULL;
    return p;
}

void addNodeBefore(List &l, Node *p){
    if(l.pHead == NULL){
        l.pHead = p;
        l.pTail = p;
    } else {
        p->next = l.pHead;
        l.pHead = p;
    }
}

void addNodeAfter(List &l, Node *p){
    if(l.pTail == NULL){
        l.pTail = p;
        l.pHead = p;
    } else {
    l.pTail->next = p;
    l.pTail = p;
    }
}

void addNode(List &l, Node *newnode, int vitri){
    Node *p = l.pHead;
    int dem = 1;
    while(p != NULL && dem != vitri){
        p = p->next;
        dem++;
    }
    if(dem != vitri){
        printf("Khong tim duoc vi ti can add node\n");
        return;
    }
    newnode->next = p->next;
    p->next = newnode;
    if(p == l.pTail){
        l.pTail = newnode;
    }
}

int deleteHead(List &l){
    if(l.pHead != NULL){
    Node *p;
    p = l.pHead;
    l.pHead = l.pHead->next;
    delete p;
    if(l.pHead == NULL) l.pTail = NULL;
    printf("Xoa thanh cong\n");
    }
}

int deleteNodeToData(List &l, int data){
    Node *p, *q;
    q = NULL;
    p = l.pHead;
    while(p != NULL && p->data != data){
        q = p;
        p = p->next;
    }
    if(p == NULL) return 0;
    if(q == NULL){
            deleteHead(l);
            return 1;
    }
    if(q != NULL){
        if(p == l.pTail){
            l.pTail = q;
            delete p;
            return 1;
        } else {
        q->next = p->next;
        delete p;
        return 1;
        }
    }

}

void selectionsort(List &l){
Node *p, *q;
p = l.pHead;
while(p != NULL){
    Node *minn;
    minn = p;
    q = p->next;
    while(q != NULL){
        if(q->data < minn->data) minn = q;
        q = q->next;
    }
    int tmp = p->data;
    p->data = minn->data;
    minn->data = tmp;
    p = p->next;
}
}

void bublesort(List &l){
    Node *p, *x, *y;
    p = l.pHead;
    while(p != NULL){
            x = l.pHead;
        while(x->next != NULL){
            y = x->next;
            if(x->data > y->data){
                int tmp = x->data;
                x->data = y->data;
                y->data = tmp;
            }
            x = x->next;
        }
        p = p->next;
    }
}

int main(){
    List l;
    createNullList(l);
    int n = 10;
    int arr[n] = {52,265,2426,1,43,564,15,58,56,9};
    for(int i = 0; i < n; i++){
        addNodeBefore(l, createNode(arr[i]));
    }
    addNode(l, createNode(10000), 7);
    deleteHead(l);
    Node *p = l.pHead;
    bublesort(l);
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
}
