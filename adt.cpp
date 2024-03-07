#include<stdio.h>
#include<iostream>
using namespace std;
struct adt {
    int total_size;
    int used_size;
    int *ptr;
};
void  createArray(adt *a, int uSize, int tSize) {
    (*a).total_size = tSize;
    a->used_size = uSize;
    a->ptr = new int(tSize * sizeof(int));
}
void showArray(adt *a) {
    for(int i=0; i< a->used_size; i++) {
        cout << (a->ptr)[i] << "\t";
    }
    cout<< endl;
}
void setArray (adt* a) {
    cout << "inter element ";
    for(int i=0; i<a->used_size; i++) {
        int x;
        cin >> x;
        a->ptr[i] = x;
    }
}
int main() {
    struct adt array;
    createArray(&array, 3,10);  
    setArray(&array);
    showArray(&array);                                                  
    return 0;
}


/*
OUTPUT:-
inter element 2
3
4
2	3	4
*/