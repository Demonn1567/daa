#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 1000000000;

int main() {
    int total = 10;
    int coins[] = {1,5,6,9};
    int row = sizeof(coins)/sizeof(coins[0]);
    
    int arr[row][total+1];
    
    for(int i =0;i<row;i++) {
        arr[i][0] = 0;
    }
    
    for(int j =1;j<=total;j++) {
        if(j%coins[0]==0) {
            arr[0][j] = j/coins[0];
        }
        else {
            arr[0][j] = INF;
        }
    }
    
    for(int i=1;i<row;i++) {
        for(int j =0;j<=total;j++) {
            if(coins[i]>j) {
                arr[i][j] = arr[i-1][j];
            }
            else {
                arr[i][j] = min(arr[i-1][j], 1+arr[i][j-coins[i]]);
            }
        }
    }
    
    
    cout<<"DP Table(min coins) : "<<endl;
    for(int i =0;i<row;i++) {
        for(int j =0;j<=total;j++) {
            if(arr[i][j]==INF) {
                cout<<"X";
            }
            else {
                cout<<arr[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    if(arr[row-1][total]==INF) {
        cout<<"No possible solution"<<endl;
    }
    
    cout<<"minimum number of coins : "<<arr[row-1][total]<<endl;
    
    
    int i =row-1;
    int j =total;
    while(i>0 && j>0) {
        if(arr[i][j]==arr[i-1][j]) {
            i--;
        }
        else {
            cout<<coins[i]<<" ";
            j-=coins[i];
        }
    }
    return 0;
}