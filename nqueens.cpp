#include <iostream>
using namespace std;

void printarray(int arr[], int n) {
    for(int i =0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int issafe(int result[], int x2, int y2) {
    for(int i =0;i<x2;i++) {
        if(result[i]==y2) {
            return 0;
        }
        if(abs(i-x2)==abs(result[i]-y2)) {
            return 0;
        }
    }
    return 1;
}

void placequeens(int result[], int x, int size) {
    if(x==size) {
        cout<<"Solution found : ";
        printarray(result, size);
        return;
    }
    for(int i =0;i<size;i++) {
        if(issafe(result, x,i)) {
            result[x] = i;
            placequeens(result, x+1, size);
        }
    }
}


int main() {
    int size = 4;
    int result[10];
    
    placequeens(result, 0, size);
    
    
    return 0;
}