#include<stdio.h>
#include<iostream>
using namespace std;
struct node{
    int data;
    struct node* next;
};
void traverse(struct node* head){
    struct node* ptr = head;
    do{
        cout<<ptr->data<<"\t";
        ptr = ptr->next;
    }while(ptr!=head);
    cout<<endl;
}
struct node* insert(struct node* head, int val, int x){
    struct node* newNode = (struct node*)malloc(sizeof (struct node));
    newNode->data= val;
    struct node* mhead = head;
    while(mhead->data != x){
        mhead= mhead->next;
    }
    struct node* temp = mhead->next;
    mhead->next = newNode;
    newNode->next = temp;
    return head;
}
int main(){
    struct node *h1;
    struct node *h2;
    struct node *h3;
    struct node *h4;
    h1 = (struct node*)malloc(sizeof (struct node));
    h4 = (struct node*)malloc(sizeof (struct node));
    h3 = (struct node*)malloc(sizeof (struct node));
    h2 = (struct node*)malloc(sizeof (struct node));
    h1->data=1;
    h1->next = h2;
    h2->data=2;
    h2->next = h3;
    h3->data=3;
    h3->next = h1;
    traverse(h3);
    h4 = insert(h3,4,1);
    traverse(h4);
}

/*
Output:-
3	1	2	
3	1	4	2
*/