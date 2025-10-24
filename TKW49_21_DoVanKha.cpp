/* Họ tên: Đỗ Văn Kha
MSSV: 24C39025
Lớp: TKW49
Tên đề tài: Quản lý xe máy trong gara */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Struct quan ly xe may
struct qlxemay{
    char biensoxe[15];
    char hangxe[20];
    char tenchuxe[50];
    char ngayguixe[15];
    char tinhtrang[50];
};

// Struct node quan ly xe may
typedef struct tagNode{
    char biensoxe[15];
    char hangxe[20];
    char tenchuxe[50];
    char ngayguixe[15];
    char tinhtrang[50];
    tagNode *next;
} Node;

// Cau truc stack
typedef struct tagStack{
    struct qlxemay *array;
    int top;
} Stack;

// Cau truc queue
typedef struct tagQueue{
    struct qlxemay *array;
    int f;
    int r;
} Queue;

// Struct list node
typedef struct tagList{
    Node *pHead;
    Node *pTail;
} List;

// Bien toan cuc
struct qlxemay *a; // Cau truc quan ly xe may
int n; // So luong xe may
List l; // Danh sach node
Stack stack; // Stack
Queue queue; // Queue

/*-------- Khai bao prototype---------*/

void menu(); //Menu chinh

// Prototype phan cau truc
void menucautruc();
void phancautruc();
void inthongtin(struct qlxemay *a, int n);
void in1tt(struct qlxemay b);
void menutimkiem();
void themmoixe();
int timvitrixe(int loai, char *giatri);
void xoaxe();
void suathongtinxe();
void timthongtinxe();
void sapxepxe();
void quicksort(struct qlxemay *a, int left, int right);

// Prototype phan danh sach
void menudanhsach();
void phanDanhSach();
Node *createNode(struct qlxemay &a);
void createNullList();
void addHead(Node *newnode);
void addTail(Node *newnode);
void addNodeSauX(int x, Node *newnode);
void inDanhSach();
void timKiemNode();
void deleteNodeHead();
void createNewNode();
void xoanodexe();
void chinhsuaxe();
void selectionNode();
void selectionNode2();
void sapxepnodexe();

//Prototype phan stack
void phanStack();
void menuStack();
int checkNullStack();
int checkFullStack();
void inStack();
void push();
void pop();

// Prototype phan queue
void phanQueue();
void menuQueue();
int checkNullQueue();
int checkFullQueue();
void pushQueue();
void popQueue();
void inQueue();

// Main
int main(){
phancautruc();
phanDanhSach();
phanStack();
phanQueue();
menu();
}

// Phan cau truc
void phancautruc(){
n = 20;
a = (struct qlxemay*) malloc(n * sizeof(struct qlxemay));
struct qlxemay ds[] = {
{"83XL02349","Honda","Do Van Kha","01/08/2025","Dang sua chua"},
{"84XL06742","Honda","Nguyen Van An","02/08/2025","Da sua chua"},
{"05XL43543","Yamaha","Tran Thi Bao","03/08/2025","Dang sua chua"},
{"46XL52452","Honda","Le Van Chi","04/08/2025","Chua sua chua"},
{"27XL37472","Yamaha","Pham Thi Dung","04/08/2025","Da sua chua"},
{"58XL62474","Honda","Nguyen Van Em","02/08/2025","Dang sua chua"},
{"88XL73442","Suzuki","Hoang Thi Hoa","01/08/2025","Da sua chua"},
{"39XL79744","Honda","Vu Van Giang","05/08/2025","Chua sua chua"},
{"80XL43447","Honda","Nguyen Thi Hung","06/08/2025","Dang sua chua"},
{"11XL68742","Yamaha","Do Van Kha","06/08/2025","Da sua chua"},
{"22XL42143","Honda","Nguyen Van Dung","01/08/2025","Dang sua chua"},
{"93XL43422","Honda","Pham Thi Khanh","07/08/2025","Da sua chua"},
{"83XL98231","Suzuki","Le Van Lam","08/08/2025","Chua sua chua"},
{"73XL11223","Honda","Tran Thi Manh","08/08/2025","Dang sua chua"},
{"83XL44556","Honda","Nguyen Van Nam","01/08/2025","Da sua chua"},
{"83XL77889","Honda","Do Van Kha","09/08/2025","Chua sua chua"},
{"93XL99001","Yamaha","Nguyen Van Phong","01/08/2025","Dang sua chua"},
{"843XL5567","Honda","Le Thi Quy","10/08/2025","Da sua chua"},
{"63XL33445","Suzuki","Pham Van Vuong","01/08/2025","Dang sua chua"},
{"83XL36545","Honda","Pham Van Ong","09/08/2025","Chua sua chua"}

};
memcpy(a, ds, n * sizeof(struct qlxemay));
}

// In 1 thong tin xe
void in1tt(struct qlxemay a){
    printf("%-12s | %-10s | %-20s | %-12s | %-15s\n",a.biensoxe,a.hangxe,a.tenchuxe,a.ngayguixe,a.tinhtrang);

}

// In tat ca thong tin xe
void inthongtin(struct qlxemay *a, int n){
printf("%-12s | %-10s | %-20s | %-12s | %-15s\n",
       "BIEN SO XE", "HANG XE", "TEN CHU XE", "NGAY GUI XE", "TINH TRANG");
for(int i = 0; i < n; i++) {
        in1tt(a[i]);
    }
}

// Ham menu chinh cua chuong trinh
void menu(){
int stt;
printf("-----DANH SACH DE TAI CTDL & GT-----\n");
printf("1. Phan cau truc\n");
printf("2. Phan danh sach\n");
printf("3. Phan ngan xep\n");
printf("4. Phan hang doi\n");
printf("5. Thoat chuong trinh\n");
printf("-------------------------------------\n");
do{
    printf("Nhap lua chon trong danh sach: ");
    scanf("%d",&stt);
    getchar();
    if(stt == 0 || stt > 5){
        printf("Nhap sai, vui long nhap tu 1 den 5\n");
    }
} while (stt == 0 || stt > 5);
switch(stt){
    case 1:
    menucautruc();
    break;
    case 2:
    menudanhsach();
    break;
    case 3:
    menuStack();
    break;
    case 4:
    menuQueue();
    break;
    }
}

//Ham menu phan cau truc
void menucautruc(){
int stt;
printf("-----PHAN CAU TRUC-----\n");
printf("1. In danh sach\n");
printf("2. Them moi xe\n");
printf("3. Sua thong tin xe\n");
printf("4. Xoa thong tin xe\n");
printf("5. Tim kiem thong tin xe\n");
printf("6. Sap xep thong tin xe\n");
printf("7. Thoat\n");
printf("-------------------------------------\n");
do{
    printf("Nhap lua chon trong danh sach: ");
    scanf("%d",&stt);
    getchar();
    if(stt == 0 || stt > 7){
        printf("Nhap sai, vui long nhap tu 1 den 7\n");
    }
} while (stt == 0 || stt > 7);
switch(stt){
    case 1:
    printf("In danh sach\n");
    inthongtin(a, n);
    menucautruc();
    break;
    case 2:
    themmoixe();
    menucautruc();
    break;
    case 3:
    suathongtinxe();
    menucautruc();
    break;
    case 4:
    xoaxe();
    menucautruc();
    break;
    case 5:
    timthongtinxe();
    menucautruc();
    break;
    case 6:
    sapxepxe();
    menucautruc();
    break;
    case 7:
    break;
}
}

// Ham them moi xe
void themmoixe() {
    int sl;
    printf("Nhap so luong xe muon them (Nhap 0 de quay lai): ");
    scanf("%d", &sl);
    if(sl == 0) menucautruc();
    getchar();
    a = (struct qlxemay*) realloc(a, (n + sl) * sizeof(struct qlxemay));
    for(int i = 0; i < sl; i++) {
        printf("\n--- Nhap thong tin xe thu %d ---\n", i+1);
        printf("Nhap bien so xe: ");
        gets(a[n].biensoxe);
        printf("Nhap hang xe: ");
        gets(a[n].hangxe);
        printf("Nhap ten chu xe: ");
        gets(a[n].tenchuxe);
        printf("Nhap ngay gui xe (dd/mm/yyyy): ");
        gets(a[n].ngayguixe);
        printf("Nhap tinh trang (Dang sua chua / Da sua chua): ");
        gets(a[n].tinhtrang);
        n++;
    }
    printf("\nDa them %d xe moi thanh cong!\n", sl);
    inthongtin(a, n);
}

// Ham tim vi tri
int timvitrixe(int loai, char *giatri) {
    for (int i = 0; i < n; i++) {
        if (loai == 1 && stricmp(a[i].biensoxe, giatri) == 0) return i;
        if (loai == 2 && stricmp(a[i].tenchuxe, giatri) == 0) return i;
        if (loai == 3 && stricmp(a[i].hangxe, giatri) == 0) return i;
        if (loai == 4 && stricmp(a[i].ngayguixe, giatri) == 0) return i;
        if (loai == 5 && stricmp(a[i].tinhtrang, giatri) == 0) return i;
    }
    return -1;
}

// Ham xoa xe
void xoaxe(){
    int loai;
    char giatri[50];
    printf("Chon thong tin xe can xoa:\n");
    printf("1. Bien so xe\n");
    printf("2. Ten chu xe\n");
    printf("3. Hang xe\n");
    printf("4. Ngay gui xe\n");
    printf("5. Tinh trang\n");
    printf("6. Quay lai\n");
    printf("Nhap lua chon: ");
    scanf("%d", &loai);
    if(loai == 6){
        menucautruc();
    } else if(loai < 1 || loai > 6){
        printf("Chon sai, vui long chon lai!\n");
        xoaxe();
    }
    getchar();
    printf("Nhap thong tin xe can xoa theo lua chon (Nhap 0 de quay lai): ");
    gets(giatri);
    printf("Thong tin xe se bi xoa:\n");
    int check = 0;
    for(int i = 0; i <= n - 1; i++) {
            int vitri = timvitrixe(loai, giatri);
            if(vitri != -1){
                in1tt(a[vitri]);
                for(int j = vitri; j <= n - 1; j++){
                    a[j] = a[j + 1];
                }
                check++;
            }
        }
        n = n - check;
        if(check){
            printf("Xoa thanh cong!\n");
        } else printf("Khong tim thay xe de xoa!\n");
    }

// Ham sua thong tin xe
void suathongtinxe(){
char giatri[50];
    printf("Nhap bien so xe cua xe can sua thong tin (Nhap 0 de quay lai): ");
    gets(giatri);
    if(stricmp(giatri, "0") == 0){
        menucautruc();
    }
    int vitri = timvitrixe(1, giatri);
    if (vitri != -1){
        printf("Da tim thay xe!\n");
        in1tt(a[vitri]);
        printf("Chon thong tin can chinh sua\n"
               "1. Bien so xe\n"
               "2. Ten chu xe\n"
               "3. Hang xe\n"
               "4. Ngay gui xe\n"
               "5. Tinh trang\n"
               "6. Quay lai\n"
               "Nhap lua chon: ");
        int option;
        scanf("%d",&option);
        int check = 0;
        switch(option){
            case 1:
                printf("Nhap bien so xe: ");
                getchar();
                gets(a[vitri].biensoxe);
                check = 1;
                break;
            case 2:
                printf("Nhap hang xe: ");
                getchar();
                gets(a[vitri].hangxe);
                check = 1;
                break;
            case 3:
                printf("Nhap ten chu xe: ");
                getchar();
                gets(a[vitri].tenchuxe);
                check = 1;
                break;
            case 4:
                printf("Nhap ngay gui xe (dd/mm/yyyy): ");
                getchar();
                gets(a[vitri].ngayguixe);
                check = 1;
                break;
            case 5:
                printf("Nhap tinh trang: ");
                getchar();
                gets(a[vitri].tinhtrang);
                check = 1;
                break;
        }
        if(check == 1) printf("Chinh sua thanh cong!\n");
        else printf("Chinh sua that bai!\n");
    } else {
        printf("Khong tim thay xe voi thong tin nay!\n");
    }
}

// Ham tim thong tin xe
void timthongtinxe(){
int loai;
char giatri[50];
    printf("Chon tieu chi de tim xe:\n");
    printf("1. Bien so xe\n");
    printf("2. Ten chu xe\n");
    printf("3. Hang xe\n");
    printf("4. Ngay gui xe\n");
    printf("5. Tinh trang\n");
    printf("6. Quay lai\n");
    printf("Nhap lua chon: ");
    scanf("%d", &loai);
    if(loai == 6) menucautruc();
    if(loai < 1 || loai > 6){
        printf("Nhap sai, vui long nhap lai!\n");
        timthongtinxe();
    }
    getchar();
    printf("Nhap thong tin xe can tim theo lua chon (Nhap 0 de quay lai): ");
    gets(giatri);
    int vitri;
    for(int i = 0; i < n; i++){
    vitri = timvitrixe(loai, giatri);
    if(vitri != -1){
        in1tt(a[vitri]);
    }
    }
    if(vitri != -1) printf("Da tim thay tat ca xe!\n");
    else printf("Khong tim thay xe!\n");
}

// Ham sap xep xe
void sapxepxe(){
    int loai;
    printf("Chon tieu chi sap xep:\n");
    printf("1. Bien so xe\n");
    printf("2. Ten chu xe\n");
    printf("3. Ngay gui xe\n");
    printf("4. Hang xe\n");
    printf("5. Quay lai\n");
    printf("Nhap lua chon: ");
    scanf("%d", &loai);
    if(loai > 5 || loai < 1){
        printf("Vui long nhap tu 1 den 5!\n");
        sapxepxe();
    }
    getchar();
    if(loai == 1){
        for(int i = 0; i < n - 1; i++){
            int max = i;
            for(int j = i + 1; j < n; j++){
            if(stricmp(a[j].biensoxe, a[max].biensoxe) < 0){
                max = j;
            }
        }
         struct qlxemay tmp = a[max];
            a[max] = a[i];
            a[i] = tmp;
    }
    }
    else if(loai == 2){
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {;
            if(strcmp(a[i].tenchuxe, a[j].tenchuxe) > 0) {
                struct qlxemay tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
    }
    else if(loai == 3){
    for(int i = 1; i < n; i++){
        struct qlxemay key = a[i];
        int j = i - 1;
        while(j >= 0 && stricmp(a[j].ngayguixe, key.ngayguixe) > 0){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
    else if(loai == 4){
        quicksort(a, 0, n);
    }
    else  if(loai == 5) menucautruc();
    printf("\nDa sap xep xong!\n");
    inthongtin(a, n);
}

// Quicksort
void quicksort(struct qlxemay *a, int left, int right) {
    int i = left, j = right;
    char chot[20];
    strcpy(chot, a[(left + right) / 2].hangxe);

    do {
        while (strcmp(a[i].hangxe, chot) < 0) i++;
        while (strcmp(a[j].hangxe, chot) > 0) j--;
        if (i <= j) {
            struct qlxemay temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);

    if (left < j) quicksort(a, left, j);
    if (i < right) quicksort(a, i, right);
}

// Menu danh sach
void menudanhsach(){
int stt;
printf("-----PHAN DANH SACH-----\n");
printf("1. In danh sach node\n");
printf("2. Them moi xe\n");
printf("3. Sua thong tin xe\n");
printf("4. Xoa thong tin xe\n");
printf("5. Tim kiem thong tin xe\n");
printf("6. Sap xep thong tin xe\n");
printf("7. Thoat\n");
printf("-------------------------------------\n");
printf("Nhap lua chon trong danh sach: ");
scanf("%d", &stt);
if(stt < 1 || stt > 7){
    printf("Nhap sai, vui long nhap tu 1 den 7\n");
    menudanhsach();
}
switch(stt){
    case 1:
    inDanhSach();
    menudanhsach();
    break;
    case 2:
    createNewNode();
    menudanhsach();
    break;
    case 3:
    chinhsuaxe();
    menudanhsach();
    break;
    case 4:
    xoanodexe();
    menudanhsach();
    break;
    case 5:
    timKiemNode();
    menudanhsach();
    break;
    case 6:
    sapxepnodexe();
    menudanhsach();
    break;
}
}
// Ham tao danh sach null
void createNullList(){
    l.pHead = NULL;
    l.pTail = NULL;
}

// Ham tao node
Node *createNode(struct qlxemay &a){
    Node *p;
    p = new Node;
    strcpy(p->biensoxe, a.biensoxe);
    strcpy(p->hangxe, a.hangxe);
    strcpy(p->ngayguixe, a.ngayguixe);
    strcpy(p->tenchuxe, a.tenchuxe);
    strcpy(p->tinhtrang, a.tinhtrang);
    p->next = NULL;
    return p;
}

// Them node vao dau danh sach
void addHead(Node *newnode){
    if(l.pHead == NULL){
        l.pHead = newnode;
        l.pTail = newnode;
    } else {
        newnode->next = l.pHead;
        l.pHead = newnode;
    }
}

// Them node vao cuoi danh sach
void addTail(Node *newnode){
    if(l.pTail == NULL){
        l.pHead = newnode;
        l.pTail = newnode;
    } else {
        l.pTail->next = newnode;
        l.pTail = newnode;
    }
}

// Them node vao sau vi tri sau x trong danh sach
void addNodeSauX(char x[], Node *newnode){
    Node *p;
    p = l.pHead;
    while(p != NULL && stricmp(p->biensoxe, x) != 0){
        p = p->next;
    }
    if(p != NULL){
        newnode->next = p->next;
        p->next = newnode;
        if(p == l.pTail){
            l.pTail = newnode;
        }
        printf("Them thanh cong\n");
    } else printf("Khong tim thay!\n");
}

// Them node vao vi tri k trong danh sach
void addNodeK(int k, Node *newnode){
    Node *p = l.pHead;
    Node *q = NULL;
    int vitri = 1;
    if(k == vitri){
        addHead(newnode);
        printf("Them thanh cong!\n");
    } else {
        while(p != NULL && vitri != k){
            q = p;
            p = p->next;
            vitri++;
        }
        if(p != NULL){
            newnode->next = p;
            q->next = newnode;
            printf("Them thanh cong!\n");
        }
    }
}

// In danh sach node
void inDanhSach(){
    Node *p = l.pHead;
    printf("%-12s | %-10s | %-20s | %-12s | %-15s\n",
       "BIEN SO XE", "HANG XE", "TEN CHU XE", "NGAY GUI XE", "TINH TRANG");
    while(p != NULL){
        printf("%-12s | %-10s | %-20s | %-12s | %-15s\n",p->biensoxe, p->hangxe, p->tenchuxe, p->ngayguixe, p->tinhtrang);
        p = p->next;
    }
}

// Phan danh sach
void phanDanhSach(){
    createNullList();
    for(int i = 0; i < n; i++){
        addTail(createNode(a[i])); // Them node vao sau list
    }
}

// Ham tim kiem node
void timKiemNode(){
    int option;
    printf("Chon tieu chi de tim kiem:\n");
    printf("1. Tim theo bien so xe\n");
    printf("2. Tim theo ten chu xe\n");
    printf("3. Tim theo ngay gui xe\n");
    printf("4. Tim theo hang xe\n");
    printf("5. Tim theo tinh trang\n");
    printf("6. Quay lai\n");
    printf("Nhap vao lua chon cua ban: ");
    scanf("%d",&option);
    if(option < 1 || option > 6){
        printf("Nhap sai! Vui long nhap tu 1 den 6\n");
        timKiemNode();
    }
    getchar();
    switch(option){
    case 1:{
        printf("Nhap bien so xe can tim (Nhap 0 de quay lai): ");
        char bsx[10];
        gets(bsx);
        Node *a;
        int found = 0;
        a = l.pHead;
        while(a != NULL){
            if(stricmp(a->biensoxe, bsx) == 0){
                printf("%-12s | %-10s | %-20s | %-12s | %-15s\n", a->biensoxe, a->tenchuxe, a->hangxe, a->ngayguixe, a->tinhtrang);
                found = 1;
            }
            a = a->next;
        }
        if(!found){
        printf("Khong tim thay xe");
        }
        break;
        }
    case 2:{
        printf("Nhap ten chu xe can tim (Nhap 0 de quay lai): ");
        char ten[10];
        gets(ten);
        Node *b;
        int found = 0;
        b = l.pHead;
        while(b != NULL){
            if(stricmp(b->tenchuxe, ten) == 0){
                printf("%-12s | %-10s | %-20s | %-12s | %-15s\n", b->biensoxe, b->tenchuxe, b->hangxe, b->ngayguixe, b->tinhtrang);
                found = 1;
            }
            b = b->next;
        }
        if(!found){
            printf("Khong tim thay xe");
        }
        break;
        }
    case 3:{
        printf("Nhap ngay gui xe can tim (Nhap 0 de quay lai): ");
        char ngay[10];
        gets(ngay);
        Node *c;
        int found = 0;
        c = l.pHead;
        while(c != NULL){
            if(stricmp(c->ngayguixe, ngay) == 0){
                printf("%-12s | %-10s | %-20s | %-12s | %-15s\n", c->biensoxe, c->tenchuxe, c->hangxe, c->ngayguixe, c->tinhtrang);
                found = 1;
            }
            c = c->next;
        }
        if(!found){
            printf("Khong tim thay xe");
        }
        break;
        }
    case 4:{
        printf("Nhap hang xe can tim (Nhap 0 de quay lai): ");
        char hang[10];
        gets(hang);
        Node *d;
        d = l.pHead;
        int found = 0;
        while(d != NULL){
            if(stricmp(d->hangxe, hang) == 0){
            printf("%-12s | %-10s | %-20s | %-12s | %-15s\n", d->biensoxe, d->tenchuxe, d->hangxe, d->ngayguixe, d->tinhtrang);
            found = 1;
            }
            d = d->next;
        }
        if(!found){
            printf("Khong tim thay xe");
        }
        break;
        }
    case 5:{
        printf("Nhap tinh trang xe can tim (Nhap 0 de quay lai): ");
        char tinhtrang[10];
        gets(tinhtrang);
        Node *e;
        e = l.pHead;
        int found = 0;
        while(e != NULL){
            if(stricmp(e->tinhtrang, tinhtrang) == 0){
                printf("%-12s | %-10s | %-20s | %-12s | %-15s\n", e->biensoxe, e->tenchuxe, e->hangxe, e->ngayguixe, e->tinhtrang);
                found = 1;
            }
                e = e->next;
        }
        if(!found){
            printf("Khong tim thay xe");
        }
        break;
    }
    case 6:
        menudanhsach();
        break;
    }
}

// Delete node dau tien
void deleteNodeHead(){
    Node *p = l.pHead;
    if(p != NULL){
        l.pHead = p->next;
        if(l.pHead == NULL){
            l.pTail = NULL;
        }
        delete p;
        printf("\nXoa xe dau danh sach thanh cong!\n");
    }
}

// Them node moi
void createNewNode(){
    struct qlxemay b;
    int vitri;
    printf("Chon vi tri muon them\n"
           "1. Dau danh sach\n"
           "2. Cuoi danh sach\n"
           "3. Them vao vi tri k chi dinh\n"
           "4. Them vao sau vi tri cua xe x\n"
           "5. Quay lai\n"
           "Nhap lua chon: ");
    scanf("%d", &vitri);
    if(vitri < 1 || vitri > 5){
        printf("Nhap  sai! Vui long nhap tu 1 den 5\n");
        createNewNode();
    }
    if(vitri == 5) menudanhsach();
    getchar();
    printf("Nhap bien so xe: ");
    gets(b.biensoxe);
    printf("Nhap ten chu xe: ");
    gets(b.tenchuxe);
    printf("Nhap ten hang xe: ");
    gets(b.hangxe);
    printf("Nhap ngay gui xe (dd/mm/yyyy): ");
    gets(b.ngayguixe);
    printf("Nhap tinh trang: ");
    gets(b.tinhtrang);
    switch(vitri){
        case 1:
            addHead(createNode(b));
            printf("Da them xe thanh cong!\n");
            break;
        case 2:
            addTail(createNode(b));
            printf("Da them xe thanh cong!\n");
            break;
        case 3:
            printf("Nhap vi tri x can them: ");
            int x;
            scanf("%d",&x);
            addNodeK(x, createNode(b));
            break;
        case 4:
            printf("Nhap bien so xe cua xe can them sau: ");
            char bsx[10];
            gets(bsx);
            addNodeSauX(bsx, createNode(b));
            break;
    }
    }


// Xoa node theo dieu kien
void xoanodexe(){
printf("Chon vi tri xoa node\n"
       "1. Xoa xe dau danh sach\n"
       "2. Xoa xe theo thong tin trong danh sach\n"
       "3. Xoa xe o vi tri q trong danh sach\n"
       "4. Quay lai\n");
printf("Nhap lua chon: ");
int option;
scanf("%d", &option);
if(option < 1 || option > 4){
    printf("Nhap sai! Vui long nhap tu 1 den 4\n");
    xoanodexe();
}
switch(option){
    case 1:
        deleteNodeHead();
        break;
    case 2:
        int option2;
        printf("1. Xoa theo bien so xe\n");
        printf("2. Xoa theo ten chu xe\n");
        printf("3. Xoa theo hang xe\n");
        printf("4. Xoa theo ngay gui xe\n");
        printf("5. Xoa theo tinh trang\n");
        printf("6. Quay lai\n");
        printf("Chon tieu chi de xoa: ");
        scanf("%d", &option2);
        getchar();
        switch(option2){
        case 1:{
            printf("Nhap bien so xe: ");
            char bsx[10];
            gets(bsx);
            Node *p = l.pHead;
            Node *q = NULL;
            int check = 0;
            while(p != NULL){
                if(stricmp(p->biensoxe, bsx) == 0){
                    if(q == NULL){
                        printf("Thong tin xe se bi xoa: \n %-12s | %-10s | %-20s | %-12s | %-15s\n", p->biensoxe, p->tenchuxe, p->hangxe, p->ngayguixe, p->tinhtrang);
                        l.pHead = p->next;
                        delete p;
                        p = l.pHead;
                        check = 1;
                    } else {
                    printf("Thong tin xe se bi xoa: \n %-12s | %-10s | %-20s | %-12s | %-15s\n", p->biensoxe, p->tenchuxe, p->hangxe, p->ngayguixe, p->tinhtrang);
                    q->next = p->next;
                    delete p;
                    p = q->next;
                    check = 1;
                    }
                } else {
                q = p;
                p = p->next;
                }
            }
            if(check){
                printf("Xoa thanh cong!\n");
            } else printf("Xoa that bai!\n");
            break;
        }
        case 2:{
            printf("Nhap ten chu xe: ");
            char ten[10];
            gets(ten);
            Node *p = l.pHead;
            Node *q = NULL;
            int check = 0;
            while(p != NULL){
                if(stricmp(p->tenchuxe, ten) == 0){
                    if(q == NULL){
                        printf("Thong tin xe se bi xoa: \n %-12s | %-10s | %-20s | %-12s | %-15s\n", p->biensoxe, p->tenchuxe, p->hangxe, p->ngayguixe, p->tinhtrang);
                        l.pHead = p->next;
                        delete p;
                        p = l.pHead;
                        check = 1;
                    } else {
                    printf("Thong tin xe se bi xoa: \n %-12s | %-10s | %-20s | %-12s | %-15s\n", p->biensoxe, p->tenchuxe, p->hangxe, p->ngayguixe, p->tinhtrang);
                    q->next = p->next;
                    delete p;
                    p = q->next;
                    check = 1;
                    }
                } else {
                q = p;
                p = p->next;
                }
            }
            if(check){
                printf("Xoa thanh cong!\n");
            } else printf("Xoa that bai!\n");
            break;
        }
            case 3:{
            printf("Nhap hang xe: ");
            char hang[10];
            gets(hang);
            Node *p = l.pHead;
            Node *q = NULL;
            int check = 0;
            while(p != NULL){
                if(stricmp(p->hangxe, hang) == 0){
                    if(q == NULL){
                        printf("Thong tin xe se bi xoa: \n %-12s | %-10s | %-20s | %-12s | %-15s\n", p->biensoxe, p->tenchuxe, p->hangxe, p->ngayguixe, p->tinhtrang);
                        l.pHead = p->next;
                        delete p;
                        p = l.pHead;
                        check = 1;
                    } else {
                    printf("Thong tin xe se bi xoa: \n %-12s | %-10s | %-20s | %-12s | %-15s\n", p->biensoxe, p->tenchuxe, p->hangxe, p->ngayguixe, p->tinhtrang);
                    q->next = p->next;
                    delete p;
                    p = q->next;
                    check = 1;
                    }
                } else {
                q = p;
                p = p->next;
                }
            }
            if(check){
                printf("Xoa thanh cong!\n");
            } else printf("Xoa that bai!\n");
            break;
            }
            case 4:{
            printf("Nhap ngay gui xe: ");
            char ngay[10];
            gets(ngay);
            Node *p = l.pHead;
            Node *q = NULL;
            int check = 0;
            while(p != NULL){
                if(stricmp(p->ngayguixe, ngay) == 0){
                    if(q == NULL){
                        printf("Thong tin xe se bi xoa: \n %-12s | %-10s | %-20s | %-12s | %-15s\n", p->biensoxe, p->tenchuxe, p->hangxe, p->ngayguixe, p->tinhtrang);
                        l.pHead = p->next;
                        delete p;
                        p = l.pHead;
                        check = 1;
                    } else {
                    printf("Thong tin xe se bi xoa: \n %-12s | %-10s | %-20s | %-12s | %-15s\n", p->biensoxe, p->tenchuxe, p->hangxe, p->ngayguixe, p->tinhtrang);
                    q->next = p->next;
                    delete p;
                    p = q->next;
                    check = 1;
                    }
                } else {
                q = p;
                p = p->next;
                }
            }
            if(check){
                printf("Xoa thanh cong!\n");
            } else printf("Xoa that bai!\n");
            break;
            }
            case 5:{
            printf("Nhap tinh trang xe: ");
            char tt[10];
            gets(tt);
            Node *p = l.pHead;
            Node *q = NULL;
            int check = 0;
            while(p != NULL){
                if(stricmp(p->tinhtrang, tt) == 0){
                    if(q == NULL){
                        printf("Thong tin xe se bi xoa: \n %-12s | %-10s | %-20s | %-12s | %-15s\n", p->biensoxe, p->tenchuxe, p->hangxe, p->ngayguixe, p->tinhtrang);
                        l.pHead = p->next;
                        delete p;
                        p = l.pHead;
                        check = 1;
                    } else {
                    printf("Thong tin xe se bi xoa: \n %-12s | %-10s | %-20s | %-12s | %-15s\n", p->biensoxe, p->tenchuxe, p->hangxe, p->ngayguixe, p->tinhtrang);
                    q->next = p->next;
                    delete p;
                    p = q->next;
                    check = 1;
                    }
                } else {
                q = p;
                p = p->next;
                }
            }
            if(check){
                printf("Xoa thanh cong!\n");
            } else printf("Xoa that bai!\n");
            break;
            }
            case 6:
                menudanhsach();
                break;
        }
        break;
    case 3:{
        printf("Nhap vi tri cua xe can xoa trong danh sach (Nhap 0 de quay lai): ");
        int q;
        scanf("%d", &q);
        int vitri = 1;
        Node *p = l.pHead;
        Node *x = NULL;
        if(q == vitri){
            printf("Thong tin xe se bi xoa: \n %-12s | %-10s | %-20s | %-12s | %-15s\n", p->biensoxe, p->tenchuxe, p->hangxe, p->ngayguixe, p->tinhtrang);
            l.pHead = p->next;
            delete p;
            printf("Xoa thanh cong!\n");
        } else {
            while(p != NULL && vitri != q){
                vitri++;
                x = p;
                p = p->next;
            }
            if(p != NULL){
                printf("Thong tin xe se bi xoa: \n %-12s | %-10s | %-20s | %-12s | %-15s\n", p->biensoxe, p->tenchuxe, p->hangxe, p->ngayguixe, p->tinhtrang);
                x->next = p->next;
                delete p;
                printf("Xoa thanh cong!\n");
            } else printf("Khong tim thay vi tri can xoa trong danh sach!\n");
        }
        break;
    }
    case 4:
        menudanhsach();
        break;
}
}

// Ham chinh sua xe
void chinhsuaxe(){
        printf("Nhap bien so xe cua xe can chinh sua (Nhap 0 de quay lai): ");
        char bsx[10];
        getchar();
        gets(bsx);
        Node *a;
        a = l.pHead;
        while(a != NULL && stricmp(a->biensoxe, bsx) != 0){
            a = a->next;
        }
        if(a != NULL){
            printf("%-12s | %-10s | %-20s | %-12s | %-15s\n", a->biensoxe, a->tenchuxe, a->hangxe, a->ngayguixe, a->tinhtrang);
            printf("Chon thong tin can chinh sua\n"
                   "1. Sua bien so xe\n"
                   "2. Sua ten chu xe\n"
                   "3. Sua ten hang xe\n"
                   "4. Sua ngay gui xe\n"
                   "5. Sua tinh trang xe\n"
                   "6. Sua tat ca thong tin\n"
                   "7. Quay lai\n"
                   "Nhap lua chon: ");
            int option;
            scanf("%d",&option);
            if(option < 1 || option > 7){
                printf("Nhap sai! Vui long nhap tu 1 den 7\n");
                chinhsuaxe();
            }
            getchar();
            switch(option){
                case 1:
                    printf("Nhap bien so xe: ");
                    gets(a->biensoxe);
                    printf("Chinh sua thanh cong!\n");
                    break;
                case 2:
                    printf("Nhap ten chu xe: ");
                    gets(a->tenchuxe);
                    printf("Chinh sua thanh cong!\n");
                    break;
                case 3:
                    printf("Nhap ten hang xe: ");
                    gets(a->hangxe);
                    printf("Chinh sua thanh cong!\n");
                    break;
                case 4:
                    printf("Nhap ngay gui xe: ");
                    gets(a->ngayguixe);
                    printf("Chinh sua thanh cong!\n");
                    break;
                case 5:
                    printf("Nhap tinh trang xe: ");
                    gets(a->tinhtrang);
                    printf("Chinh sua thanh cong!\n");
                    break;
                case 6:
                    printf("Nhap bien so xe: ");
                    gets(a->biensoxe);
                    printf("Nhap ten chu xe: ");
                    gets(a->tenchuxe);
                    printf("Nhap ten hang xe: ");
                    gets(a->hangxe);
                    printf("Nhap ngay gui xe: ");
                    gets(a->ngayguixe);
                    printf("Nhap tinh trang xe: ");
                    gets(a->tinhtrang);
                    printf("Chinh sua thanh cong!\n");
                    break;
            }
        }
}
// Sap xep xe
void sapxepnodexe(){
    printf("Chon tieu chi de sap xep xe\n"
           "1. Sap xep theo bien so xe, doi du lieu\n"
           "2. Sap xep theo ten chu xe, doi truong next\n"
           "3. Quay lai\n"
           "Nhap lua chon cua ban: ");
    int option;
    scanf("%d", &option);
    if(option < 1 || option > 3){
        printf("Nhap sai! Vui long nhap tu 1 den 4\n");
        sapxepnodexe();
    }
    switch(option){
    case 1:
        selectionNode();
        printf("Sap xep thanh cong!\n");
        break;
    case 2:
        selectionNode2();
        printf("Sap xep thanh cong!\n");
        break;
    case 3:
        menudanhsach();
        break;
    }
}

// Selection sort node
void selectionNode(){
    Node *p = l.pHead;
    while(p != NULL){
        Node *min = p;
        Node *q = p->next;
        while(q != NULL){
            if(stricmp(q->biensoxe, min->biensoxe) > 0){
                min = q;
            }
            q = q->next;
        }
        if(min != p){
            struct qlxemay tmp;
            strcpy(tmp.biensoxe, p->biensoxe);
            strcpy(tmp.hangxe, p->hangxe);
            strcpy(tmp.tenchuxe, p->tenchuxe);
            strcpy(tmp.ngayguixe, p->ngayguixe);
            strcpy(tmp.tinhtrang, p->tinhtrang);

            strcpy(p->biensoxe, min->biensoxe);
            strcpy(p->hangxe, min->hangxe);
            strcpy(p->tenchuxe, min->tenchuxe);
            strcpy(p->ngayguixe, min->ngayguixe);
            strcpy(p->tinhtrang, min->tinhtrang);

            strcpy(min->biensoxe, tmp.biensoxe);
            strcpy(min->hangxe, tmp.hangxe);
            strcpy(min->tenchuxe, tmp.tenchuxe);
            strcpy(min->ngayguixe, tmp.ngayguixe);
            strcpy(min->tinhtrang, tmp.tinhtrang);
        }
        p = p->next;
    }
}

void selectionNode2() {
    if (l.pHead == NULL || l.pHead->next == NULL) return;

    Node *prev_p = NULL;
    Node *p = l.pHead;

    while (p != NULL) {
        Node *prev_min = p;
        Node *min = p;

        Node *prev_q = p;
        Node *q = p->next;
        while (q != NULL) {
            if (stricmp(q->tenchuxe, min->tenchuxe) < 0) {
                prev_min = prev_q;
                min = q;
            }
            prev_q = q;
            q = q->next;
        }
        if (min != p) {
            if (prev_min == p) {
                p->next = min->next;
                min->next = p;
                if (prev_p != NULL)
                    prev_p->next = min;
                else
                    l.pHead = min;
            }
            else {
                Node *temp = min->next;
                prev_min->next = p;
                min->next = p->next;
                p->next = temp;

                if (prev_p != NULL)
                    prev_p->next = min;
                else
                    l.pHead = min;
            }
            prev_p = min;
            p = min->next;
        } else {
            prev_p = p;
            p = p->next;
        }
    }
}

void phanStack(){

n = 30;
int m = 20;

stack.array = new struct qlxemay[n];

struct qlxemay ds[m] = {

{"83XL02349","Honda","Do Van Kha","01/08/2025","Dang sua chua"},
{"84XL06742","Honda","Nguyen Van An","02/08/2025","Da sua chua"},
{"05XL43543","Yamaha","Tran Thi Bao","03/08/2025","Dang sua chua"},
{"46XL52452","Honda","Le Van Chi","04/08/2025","Chua sua chua"},
{"27XL37472","Yamaha","Pham Thi Dung","04/08/2025","Da sua chua"},
{"58XL62474","Honda","Nguyen Van Em","02/08/2025","Dang sua chua"},
{"88XL73442","Suzuki","Hoang Thi Hoa","01/08/2025","Da sua chua"},
{"39XL79744","Honda","Vu Van Giang","05/08/2025","Chua sua chua"},
{"80XL43447","Honda","Nguyen Thi Hung","06/08/2025","Dang sua chua"},
{"11XL68742","Yamaha","Do Van Kha","06/08/2025","Da sua chua"},
{"22XL42143","Honda","Nguyen Van Dung","01/08/2025","Dang sua chua"},
{"93XL43422","Honda","Pham Thi Khanh","07/08/2025","Da sua chua"},
{"83XL98231","Suzuki","Le Van Lam","08/08/2025","Chua sua chua"},
{"73XL11223","Honda","Tran Thi Manh","08/08/2025","Dang sua chua"},
{"83XL44556","Honda","Nguyen Van Nam","01/08/2025","Da sua chua"},
{"83XL77889","Honda","Do Van Kha","09/08/2025","Chua sua chua"},
{"93XL99001","Yamaha","Nguyen Van Phong","01/08/2025","Dang sua chua"},
{"843XL5567","Honda","Le Thi Quy","10/08/2025","Da sua chua"},
{"63XL33445","Suzuki","Pham Van Vuong","01/08/2025","Dang sua chua"},
{"83XL36545","Honda","Pham Van Ong","09/08/2025","Chua sua chua"}

};
memcpy(stack.array, ds, m * sizeof(qlxemay));
stack.top = m - 1;
}

void menuStack(){
int stt;

printf("-----PHAN NGAN XEP-----\n");
printf("1. In danh sach stack xe\n");
printf("2. Them moi stack xe\n");
printf("3. Lay phan tu ra khoi stack va in ra phan tu\n");
printf("4. Quay lai\n");
printf("-------------------------------------\n");
printf("Nhap lua chon trong danh sach: ");
scanf("%d", &stt);

if(stt < 1 || stt > 4){
    printf("Nhap sai, vui long nhap tu 1 den 4\n");
    menuStack();
}
switch(stt){
    case 1:
        inStack();
        menuStack();
        break;
    case 2:
        push();
        menuStack();
        break;
    case 3:
        pop();
        menuStack();
    case 4:
        menu();
}
}

int checkNullStack(){
    if(stack.top == -1) return 1;
    return 0;
}

int checkFullStack(){
    if(stack.top == n - 1) return 1;
    return 0;
}

void inStack(){
    if(checkNullStack() == 0){
        printf("%-12s | %-10s | %-20s | %-12s | %-15s\n",
           "Bien so", "Hang xe", "Ten chu xe", "Ngay gui", "Tinh trang");
    printf("---------------------------------------------------------------\n");
    for (int i = stack.top; i >= 0; i--) {
        in1tt(stack.array[i]);
    }
}
}

void push(){
    if(checkFullStack() == 0){
        stack.top++;
        printf("Nhap bien so xe: ");
        getchar();
        gets(stack.array[stack.top].biensoxe);
        printf("Nhap ten chu xe: ");
        gets(stack.array[stack.top].tenchuxe);
        printf("Nhap ten hang xe: ");
        gets(stack.array[stack.top].hangxe);
        printf("Nhap ngay gui xe: ");
        gets(stack.array[stack.top].ngayguixe);
        printf("Nhap tinh trang xe: ");
        gets(stack.array[stack.top].tinhtrang);
        printf("Them thanh cong!\n");
    } else printf("Stack da day!\n");
}

void pop(){
    if(checkNullStack() == 0){
        in1tt(stack.array[stack.top]);
        stack.top--;
        printf("Xoa thanh cong!\n");
    } else printf("Xoa that bai!\n");
}

void phanQueue(){
n = 30;
int m = 20;

queue.array = new struct qlxemay[n];

struct qlxemay ds[m] = {

{"83XL02349","Honda","Do Van Kha","01/08/2025","Dang sua chua"},
{"84XL06742","Honda","Nguyen Van An","02/08/2025","Da sua chua"},
{"05XL43543","Yamaha","Tran Thi Bao","03/08/2025","Dang sua chua"},
{"46XL52452","Honda","Le Van Chi","04/08/2025","Chua sua chua"},
{"27XL37472","Yamaha","Pham Thi Dung","04/08/2025","Da sua chua"},
{"58XL62474","Honda","Nguyen Van Em","02/08/2025","Dang sua chua"},
{"88XL73442","Suzuki","Hoang Thi Hoa","01/08/2025","Da sua chua"},
{"39XL79744","Honda","Vu Van Giang","05/08/2025","Chua sua chua"},
{"80XL43447","Honda","Nguyen Thi Hung","06/08/2025","Dang sua chua"},
{"11XL68742","Yamaha","Do Van Kha","06/08/2025","Da sua chua"},
{"22XL42143","Honda","Nguyen Van Dung","01/08/2025","Dang sua chua"},
{"93XL43422","Honda","Pham Thi Khanh","07/08/2025","Da sua chua"},
{"83XL98231","Suzuki","Le Van Lam","08/08/2025","Chua sua chua"},
{"73XL11223","Honda","Tran Thi Manh","08/08/2025","Dang sua chua"},
{"83XL44556","Honda","Nguyen Van Nam","01/08/2025","Da sua chua"},
{"83XL77889","Honda","Do Van Kha","09/08/2025","Chua sua chua"},
{"93XL99001","Yamaha","Nguyen Van Phong","01/08/2025","Dang sua chua"},
{"843XL5567","Honda","Le Thi Quy","10/08/2025","Da sua chua"},
{"63XL33445","Suzuki","Pham Van Vuong","01/08/2025","Dang sua chua"},
{"83XL36545","Honda","Pham Van Ong","09/08/2025","Chua sua chua"}

};
memcpy(queue.array, ds, m * sizeof(qlxemay));
queue.f = 0;
queue.r = m - 1;
}

void menuQueue(){
int stt;

printf("-----PHAN HANG DOI-----\n");
printf("1. In danh sach queue xe\n");
printf("2. Them moi queue xe\n");
printf("3. Lay phan tu ra khoi queue va in ra phan tu\n");
printf("4. Quay lai\n");
printf("-------------------------------------\n");
printf("Nhap lua chon trong danh sach: ");
scanf("%d", &stt);

if(stt < 1 || stt > 4){
    printf("Nhap sai, vui long nhap tu 1 den 4\n");
    menuStack();
}
switch(stt){
    case 1:
        inQueue();
        menuQueue();
        break;
    case 2:
        pushQueue();
        menuQueue();
        break;
    case 3:
        popQueue();
        menuQueue();
        break;
    case 4:
        menu();
        break;
}
}

int checkNullQueue(){
    if(queue.f == -1) return 1;
    return 0;
}

int checkFullQueue(){
    if(queue.r == n - 1) return 1;
    return 0;
}

void pushQueue(){
    if(checkFullQueue() == 0){
        queue.r++;
        printf("Nhap bien so xe: ");
        getchar();
        gets(queue.array[queue.r].biensoxe);
        printf("Nhap ten chu xe: ");
        gets(queue.array[queue.r].tenchuxe);
        printf("Nhap ten hang xe: ");
        gets(queue.array[queue.r].hangxe);
        printf("Nhap ngay gui xe: ");
        gets(queue.array[queue.r].ngayguixe);
        printf("Nhap tinh trang xe: ");
        gets(queue.array[queue.r].tinhtrang);
        printf("Them thanh cong!\n");
    } else printf("Queue da day!\n");
}

void popQueue(){
    if(checkNullQueue() == 0){
        in1tt(queue.array[queue.f]);
        queue.f++;
        printf("Xoa thanh cong!\n");
    } else printf("Xoa that bai!\n");
}

void inQueue(){
    if(checkNullQueue() == 0){
        printf("%-12s | %-10s | %-20s | %-12s | %-15s\n",
           "Bien so", "Hang xe", "Ten chu xe", "Ngay gui", "Tinh trang");
    for (int i = queue.f; i <= queue.r; i++) {
        in1tt(queue.array[i]);
    }
}
}


