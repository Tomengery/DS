#include<stdio.h>
#include<iostream>
using namespace std;
struct stack {
    int size;
    int top;
    int *arr;
};
bool checkFull(struct stack* s) {
    if(s->top == s->size-1) {
        cout<< "Full stack"<<endl;
        return false;
    }
    return true;
}
bool checkEmpty(struct stack* s) {
    if(s->top == -1) {
        cout<<"Empty stack"<< endl;
        return false;
    }
    return true;
}
void stackTraverse(struct stack* s) {
    for(int i=0;i<s->size;i++) {
        cout<<s->arr[i]<<"\t";
    }
    cout<<endl;
}
void popStack(struct stack* s) {
    if(checkEmpty(s)) {
        s->top--;
    }
}
void pushStack(struct stack* s, int data) {
    if(checkFull(s)) {
        s->arr = (int*)malloc(sizeof(int));
        s->top++;
        s->arr[s->top] = data;
    }
}
int main() {
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->size=5;
    s->top=-1;
    s->arr = (int*)malloc(s->size*sizeof(int));
   pushStack(s,4);
    cout<<s->arr[0]<<endl;
    pushStack(s,5);
    cout<<s->arr[0]<<endl;
    pushStack(s,3);
    pushStack(s,2);
    pushStack(s,2);
    pushStack(s,2);
    pushStack(s,1);
    popStack(s);
    popStack(s);
    popStack(s);
    popStack(s);
    popStack(s);
    popStack(s);
    popStack(s);
    // stackTraverse(s);
}

/*
Output:-
4
0
Full stack
Full stack
Empty stack
Empty stack
*/