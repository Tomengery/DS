#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
void showArray(int array[], int n)
{
    for(int i =0; i< n; i++) {
        cout << array[i] << "\t";
    }
    cout<< endl;
}
int insert(int arr[], int size, int mSize, int value, int index){
    if(index >= mSize) {
        return -1;
    }
    else {
        for(int i= size-1; i>=index; i--) {
            arr[i+1] = arr[i];
        }
        arr[index]=value;
        return 1;
    }
}
int deleteValue(int arr[], int mSize, int index, int size) {
    if(index >=mSize) {
        return -1;
    }
    else {
        for(int i= index; i< size-1; i++) {
            arr[i] = arr[i+1];
        }
        // free arr[size-1];
        return 1;
    }
}
int main() {
    int arr[100] ={1,2,3,4,5,6,7,8};
    showArray(arr,8);
    insert(arr,8,100,9,3);
    showArray(arr,9);
    deleteValue(arr,100,3,9);
    showArray(arr,8);
    return 0;
}


/*
OUTPUT:-
1	2	3	4	5	6	7	8	
1	2	3	9	4	5	6	7	8	
1	2	3	4	5	6	7	8
*/