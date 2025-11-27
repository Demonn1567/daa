#include <iostream>
using namespace std;

int main() {
    int n;
    int capacity;
    cin>>n;
    cin>>capacity;
        
    float* profit = new float[n];
    float* weight = new float[n];
    float* ratio = new float[n];
    
    for(int i =0;i<n;i++) cin>>profit[i];
    for(int i =0;i<n;i++) cin>>weight[i];
    
    for(int i =0;i<n;i++) {
        ratio[i] = profit[i]/weight[i];
    }
    
    for(int i =0;i<n;i++) {
        for(int j =i+1;j<n;j++) {
            if(ratio[i]<ratio[j]) {
                float t = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = t;
                
                t = profit[i];
                profit[i] = profit[j];
                profit[j] = t;
                
                t = weight[i];
                weight[i] = weight[j];
                weight[j] = t;

            }
        }
    }
    
    float totalProfit = 0;
    for(int i =0;i<n;i++) {
        if(weight[i]<=capacity) {
            totalProfit+=profit[i];
            capacity-=weight[i];
        }
        else {
            float fraction = capacity/weight[i];
            totalProfit+=profit[i]*fraction;
            capacity = 0;
            break;
        }
    }
    cout<<"Maximum Profit = "<<totalProfit<<endl;
    
    delete[] profit;
    delete[] weight;
    delete[] ratio;
    
    
    return 0;
    
    
    
}