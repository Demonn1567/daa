#include <bits/stdc++.h>
using namespace std;

bool comp(const pair<int,int>& a, const pair<int,int>& b) {
    return a.second < b.second;
}

vector<pair<int,int>> ActSelect(const vector<pair<int,int>> & activities) {
    int n = (int)activities.size();
    vector<pair<int,int>> A;

    if(n==0) {
        return A;
    }
    A.push_back(activities[0]);

    int k = 0;
    for(int m =1;m<n;m++) {
        if(activities[m].first>=activities[k].second) {
            A.push_back(activities[m]);
            k=m;
        }
    }
    return A;
}

int main() {
    vector<pair<int,int>> activities = {
        {1, 4},
        {3, 5},
        {0, 6},
        {5, 7},
        {3, 9},
        {5, 9},
        {6, 10},
        {8, 11},
        {8, 12},
        {2, 14},
        {12, 16}
    };

    sort(activities.begin(), activities.end(), comp);

    vector<pair<int,int>> selected =ActSelect(activities);

    cout << "Selected activities (start, finish):\n";
    for (size_t i = 0; i < selected.size(); i++) {
        cout << "(" << selected[i].first << ", " << selected[i].second << ")\n";
    }

    cout << "Maximum number of non-overlapping activities = "
         << selected.size() << endl;


    




    return 0;
}