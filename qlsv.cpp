#include<stdio.h>
#include <cstring>
typedef struct sinhvien{
    int id;
    char name[30];
    float point;
} sinhvien;
typedef struct tagNode{
    int id;
    char name[30];
    float point;
    tagNode *next;
} Node;
typedef struct tagList{
    Node *pHead;
    Node *pTail;
} List;
void createList(List &l){
    l.pHead = NULL;
    l.pTail = NULL;
}
Node *createNode(sinhvien sv){
    Node *p;
    p = new Node;
    p->id = sv.id;
    strcpy(p->name, sv.name);
    p->point = sv.point;
    p->next = NULL;
    return p;
}
void addNodeHead(List &l, Node *p){
    if(l.pHead == NULL){
        l.pHead = p;
        l.pTail = p;
        printf("Them node vao  dau danh sach thanh cong\n");
        return;
    } else {
        p->next = l.pHead;
        l.pHead = p;
        printf("Them node vao  dau danh sach thanh cong\n");
        return;
    }
    printf("Them that bai hay kiem tra lai code");
}
void addNodeTail(List &l, Node *p){
    if(l.pTail == NULL){
        l.pHead = p;
        l.pTail = p;
        printf("Them node vao cuoi danh sach thanh cong\n");
        return;
    } else {
        l.pTail->next = p;
        l.pTail = p;
        printf("Them node vao cuoi danh sach thanh cong\n");
        return;
    }
    printf("Them that bai hay kiem tra lai code");
}
void addNodeX(List &l, Node *newnode, int x){
    Node *p;
    p = l.pHead;
    int vitri = 1;
    while(p != NULL && vitri != x){
        p = p->next;
    }
    newnode = p->next;
    p->next = newnode;
    if(p->next == newnode) printf("Them thanh cong");
}
void deleteNode(List &l, int id){
    Node *p, *q;
    p = l.pHead;
    while(p != NULL && p->id != id){
        q = p;
        p = p->next;
    }
    if(p == NULL){
        printf("Khong tim thay node can xoa!\n");
        return;
    }
    if(p == l.pHead){
        l.pHead = p->next;
        delete p;
        printf("Xoa thanh cong\n");
        return;
    }
    if(p->id == id){
        if(p == l.pTail){
        l.pTail = q;
        q->next = p->next;
        delete p;
        printf("Xoa thanh cong\n");
        return;
        } else {
            q->next = p->next;
            delete p;
            printf("Xoa thanh cong\n");
            return;
        }
    }
}
void searchId(List &l, int id){
    Node *p;
    p = l.pHead;
    while(p != NULL && p->id != id){
        p = p->next;
    }
    if(p->id == id){
        printf("Da tim thay node\n%d | %s | %f\n", p->id, p->name, p->point);
    } else printf("Khong tim thay node\n");
}
void searchName(List &l, char name[]){
    Node *p;
    p = l.pHead;
    while(p != NULL && stricmp(p->name, name) != 0){
        p = p->next;
    }
    if(stricmp(p->name, name) == 0){
        printf("Da tim thay node\n%d | %s | %f\n", p->id, p->name, p->point);
    } else printf("Khong tim thay node\n");
}
void changeInfo(List &l, int id, char name[], float point){
    Node *p = l.pHead;
    while(p != NULL && p->id != id){
        p = p->next;
    }
    if(p->id == id){
        strcpy(p->name, name);
        p->point = point;
        printf("Chinh sua thanh cong\n%d | %s | %f\n", p->id, p->name, p->point);
        return;
    }
}
void countsv(List &l){
    int countt = 1;
    Node *p = l.pHead;
    while(p != NULL){
        p = p->next;
        countt++;
    }
    printf("So luong sinh vien: %d\n", countt);
}
void selectionsort(List &l){
    Node *p = l.pHead;
    Node *q;
    while(p != NULL){
        q = p;
        Node *nodemin = p;;
        while(q != NULL){
            if(q->id < nodemin->id){
                nodemin = q;
            }
            q = q->next;
        }
        Node temp;
                temp.id = p->id;
                strcpy(temp.name, p->name);
                temp.point = p->point;

                p->id = q->id;
                strcpy(p->name, q->name);
                p->point = q->point;

                q->id = temp.id;
                strcpy(q->name, temp.name);
                q->point = temp.point;
        p = p->next;
    }
}
void bublesort(List &l){
    Node *p = l.pHead;
    Node *x, *y;
    while(p != NULL){
        x = l.pHead;
        while(x->next != NULL){
            y = x->next;
            if(x->point < y->point){
                Node temp;
                temp.id = x->id;
                strcpy(temp.name, x->name);
                temp.point = x->point;

                x->id = y->id;
                strcpy(x->name, y->name);
                x->point = y->point;

                y->id = temp.id;
                strcpy(y->name, temp.name);
                y->point = temp.point;
            }
            x = x->next;
        }
        p = p->next;
    }
}
int main(){
    List l;
    createList(l);
    sinhvien sv[5] = {
        {1213, "Do Van Kha", 7.8},
        {6543, "Le Van C", 4.7},
        {5743, "Nguyen Van B", 4.9},
        {6433, "Chau Thi B", 9.0},
        {2344, "Tan Van D", 5.7}
    };
    for(int i = 0; i < sizeof(sv) / sizeof(sv[0]); i++){
        addNodeTail(l, createNode(sv[i]));
    }
    bublesort(l);
    Node *p;
    p = l.pHead;
    while(p != NULL){
        printf("%d %s %f\n",p->id, p->name, p->point);
        p = p->next;
    }
    countsv(l);
    searchId(l, 2344);
    searchName(l, "chau thi b");
    changeInfo(l, 5743, "kankadncv", 7.9);
}
