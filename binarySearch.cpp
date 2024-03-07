#include<stdio.h>
#include<iostream>
using namespace std;
void binarySearch(int arr[], int size, int value) {
    int mid, high= size-1, low=0;
    while(low <= high) {
        mid = (high+low)/2;
        cout<<mid<<endl;
        if(arr[mid] == value) {
            cout<<"Found"<<endl;
            return;
        }
        else if(arr[mid] > value) {
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    // mid = (high+low)/2;
    }
    cout<<"Data not found"<<endl;
}
int main() {
    int arr[] = {1,2,3,4,5,6,7};
    binarySearch(arr,7,1);
    return 0;
}



/*
OUTPUT:-
3
1
0
Found
*/