#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int temp = 50;

int n;
int m;
int x[temp] = {0};
int w[temp] = {0};

void bubbleSortWeights() {
    for(int i =1;i<=n-1;i++) {
        for(int j =i+1;j<=n;j++) {
            if(w[i]>w[j]) {
                int temp = w[i];
                w[i] =w[j];
                w[j] = temp;
            }
        }
    }
}

void SumOfSub(int s, int k, int r) {
    if(k>n) return;
    x[k] = 1;
    if(s+w[k]==m) {
        cout<<"{";
        for(int i = 1;i<=k;i++) {
            if(x[i]==1) {
                cout<<w[i]<<" ";
            }
        }
        cout<<"}";
    }
    else if(k<n && s+w[k]+w[k+1]<=m) {
        SumOfSub(s+w[k], k+1, r-w[k]);
    }
    
    if(k<n && (s+r-w[k]>=m) && (s+w[k+1]<=m)) {
        x[k] = 0;
        SumOfSub(s, k+1, r-w[k]);
    }
}

int main() {
    cout<<"enter number of element : ";
    cin>>n;
    
    cout<<endl<<"enter weights : "<<endl;
    for(int i =1;i<=n;i++) {
        cin>>w[i];
    }
    cout<<"enter target sum : ";
    cin>>m;
    
    bubbleSortWeights();
    
    int r = 0;
    for(int i =1;i<=n;i++) {
        r+=w[i];
    }
    cout<<"weights after sorting : ";
    
    for(int i =1;i<=n;i++) {
        cout<<w[i]<<" ";
        cout<<endl;
    }
    
    cout<<"subsets : ";
    SumOfSub(0,1,r);
    
    return 0;
    
    
    
    
    
    
    return 0;
}






