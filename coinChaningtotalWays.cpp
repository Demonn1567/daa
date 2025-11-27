#include <iostream>
using namespace std;

int main() {
    int total = 15;
    int coins[] = {2,3,5,10};
    
    int row = sizeof(coins)/sizeof(coins[0]);
    long long arr[row][total+1];
    
    for(int i =0;i<row;i++) {
        arr[i][0] =1;
    }
    
    for(int j =1;j<=total;j++) {
        if(j%coins[0]==0) {
            arr[0][j] = 1;
        }
        else {
            arr[0][j] = 0;
        }
    }
    
    for(int i =1;i<row;i++)
 {
     for(int j = 1;j<=total;j++) {
         if(coins[i]>j) {
             arr[i][j] = arr[i-1][j];
         }
         else {
             arr[i][j] = arr[i-1][j] + arr[i][j-coins[i]];
         }
     }
 }    
 
 
 cout<<"DP Table(number of ways) : "<<endl;
 for(int i =0;i<row;i++) {
     for(int j=0;j<=total;j++) {
         cout<<arr[i][j]<<" ";
     }
     cout<<endl;
 }
 
 cout<<"Total number of ways  : "<<arr[row-1][total]<<endl;
 
 return 0;
    
}