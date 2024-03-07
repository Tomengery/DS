#include<stdio.h>
#include<iostream>
using namespace std;
struct node {
    int data;
    struct node* next;
};
void traverse(struct node* pointr) {
    while(pointr != NULL) {
        cout<<pointr->data<<"\t";
        pointr = pointr->next;
    }
    cout<<endl;
}
struct node* insertBegin(struct node* head, int value) {
    struct node* mhead= (struct node*)malloc(sizeof (struct node));
    mhead->data = value;
    mhead->next = head;
    return mhead;
}
struct node* insertEnd(struct node* head, int value) {
    struct node* last = (struct node*)malloc(sizeof (struct node));
    struct node* dhead = head;
    while(dhead != NULL) {
        if(dhead->next == NULL)
            break;
        dhead = dhead->next;
    }
    last->data = value;
    last->next = NULL;
    dhead->next = last;
    return head;
}
struct node* insertBet(struct node* head, int value,int x){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    struct node* mhead = head;
    while(mhead->data != value) {
        if(mhead->next == NULL)
            break;
        mhead = mhead->next;
    }
    struct node* temp = mhead->next;
    mhead->next = newNode;
    newNode->next = temp;
    return head;
}
struct node* firstDel(struct node* head){
    if(head != NULL)
        head = head->next;
    return head;
}
struct node* lastDel(struct node* head){
    struct node* mhead= head;
    struct node* shead;
    if(head != NULL)
        shead = head->next;
    while(shead != NULL) {
        if(shead->next == NULL)
             break;
        mhead = mhead->next;
        shead = shead->next;
    }
    free(shead);
    mhead->next = NULL;
    return head;
}
struct node* delbet(struct node* head, int val) {
    struct node* mhead=head;
    struct node* shead;
    if(mhead != NULL)
        shead= mhead->next;
    while(shead != NULL) {
        if(shead->data == val)
            break;
        mhead = mhead->next;
        shead = shead->next;
    }
    mhead->next = shead->next;
    free(shead);
    return head;
}
int main() {
    struct node *head;
    struct node *sec;
    struct node *third;
    struct node *zero;
    struct node *last;
    struct node *last1;
    struct node *last2;
    struct node *last3;
    struct node *last4;
    head= (struct node*)malloc(sizeof (struct node));
    sec= (struct node*)malloc(sizeof (struct node));
    third= (struct node*)malloc(sizeof (struct node));
    head->data =1;
    head->next=sec;
    sec->data=2;
    sec->next = third;
    third->data =3;
    third->next = NULL;
    traverse(head);
    zero = insertBegin(head,0);
    traverse(zero);
    // last = insertEnd(zero,4);
    // traverse(last);
    last1 = insertEnd(zero,4);
    traverse(last1);
    last2 = insertBet(last1,0,5);
    traverse(last2);
    last3 = firstDel(last2);
    traverse(last3);
    last4 = lastDel(last3);
    traverse(last4);
    last = delbet(last4,1);
    traverse(last);
    return 0;
}

/*
OUTPUT:-
1	2	3	
0	1	2	3	
0	1	2	3	4	
0	5	1	2	3	4	
5	1	2	3	4	
5	1	2	3	
5	2	3
*/
