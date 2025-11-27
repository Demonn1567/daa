#include <iostream>
using namespace std;

int main() {
    int arr[][2] = {
        {35,3},
        {30,4},
        {25,4},
        {20,2},
        {15,3},
        {12,1},
        {5,2}
    };
    int n =7;
    
    for(int i =0;i<n-1;i++) {
        for(int j =i+1;j<n;j++) {
            if(arr[i][0]<arr[j][0]) {
                int profit = arr[i][0];
                int deadline = arr[i][1];
                
                arr[i][0] = arr[j][0];
                arr[i][1] = arr[j][1];
                
                arr[j][0] = profit;
                arr[j][1] = deadline;
            }
        }    
    }
    int last = 0;
    for(int i =0;i<n;i++) {
        if(arr[i][1]>last) {
            last = arr[i][1];
        }
    }
    
    int slots[last+1] = {0};
    int totalProfit = 0;
    for(int i=0;i<n;i++) {
        int p = arr[i][0];
        int d = arr[i][1];
        
        for(int t = d;t>=1;t--) {
            if(slots[t]==0) {
                slots[t] =1;
                totalProfit+=p;
                break;
            }
        }
        
    }
    cout<<"Total Profit="<<totalProfit<<endl;
    
    return 0;
    
    
    
}