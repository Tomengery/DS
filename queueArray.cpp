#include<stdio.h>
#include<iostream>
using namespace std;
struct queue {
    int size;
    int front; // moving ahead to push
    int rear; // to pop
    int *arr;
};
bool isFull(struct queue*q){
    // cout<<"-====2  "<<sizeof(q->arr)<<endl;
    // cout<<"-====1  "<< q->size<<endl;
    if((q->front - q->rear) == (q->size)) {
        cout<<"Full queue "<<endl;
        return true;
    }
    return false;
}
void enqueue(struct queue* q,int data){
    if(isFull(q)) {
        cout<<"Full queue no enqueue "<<endl;
    }
    else {
        q->front++;
        q->arr[q->front]  = data;
    }
}
void dequeue(struct queue* q){
    if(q->front == q->rear){
        cout<<"Empty queue"<<endl;
    }
    q->rear++;
    cout<<"dequeued element "<<q->arr[q->rear]<<endl;
}
void traverse(struct queue* q){
    for(int i=(q->rear+1); i<(q->front+1);i++){
        cout<<q->arr[i]<<"\t";
    }
        cout<<endl;
}
int main(){
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->size = 5;
    q->front = q->rear = -1;
    q->arr = (int*)malloc(q->size*sizeof(int));
    enqueue(q,2);
    enqueue(q,21);
    enqueue(q,22);
    enqueue(q,23);
    dequeue(q);
    enqueue(q,24);
    enqueue(q,26);
    enqueue(q,27);
    dequeue(q);
    dequeue(q);
    enqueue(q,25);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    traverse(q);
}

/*
Output:-
dequeued element 2
Full queue 
Full queue no enqueue 
dequeued element 21
dequeued element 22
dequeued element 23
dequeued element 24
dequeued element 26
25
*/