#include<stdio.h>
#include<iostream>
using namespace std;
struct stack{
    int data;
    struct stack* next;
};
bool checkEmpty(struct stack *top) {
    if(top == NULL) {
        cout<<"stack is empty"<<endl;
        return true;
    }
    return false;
}
bool checkFull() {
    struct stack* top = (struct stack*)malloc(sizeof(struct stack));
    if(top == NULL) {
        cout<<"stack is full"<<endl;
        return true;
    }
    return false;
}
void traverse(struct stack* top) {
    while(top != NULL) {
        cout<<top->data<<"\t";
        top = top->next;
    }
    cout<<endl;
}
struct stack* push(struct stack* top, int data){
    struct stack* head = (struct stack*)malloc(sizeof(struct stack));
    if(checkFull()) {
        cout<< "overflow";
        return top;
    }
    head->data = data;
    head->next = top;
    top = head;
    return top;
}
struct stack* pop(struct stack* top) {
    if(checkEmpty(top)) {
        cout<<" under flow";
        return top;
    }
    struct stack* a = top;
    top = top->next;
    free(a);
    return top;
}
int main() {
    struct stack* top;
    top = push(top,1);
    traverse(top);
    top = push(top,3);
    top = push(top,2);
    top = push(top,4);
    traverse(top);
    top = pop(top);
    traverse(top);
}

/*
Output:-
1	
4	2	3	1	
2	3	1
*/