#include<sttdio.h>

const unsiged int n = 10;

typedef struct tagStack{
    int array[n];
    int top;
} Stack;

void init(Stack s){
    s->top = -1;
}

int checkStackNull(Stack s){
    if(s->top == -1) return 1;
    return 0;
}

int checkStackFull(Stack s){
    if(s->top == max - 1) return 1;
    return 0;
}

int push(Stack s, int value){
    if(checkStackFull(s) == 0){
        s->array[]
    }
}
