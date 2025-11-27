#include <iostream>
using namespace std;

int main() {
    // jobs[i][0] = profit
    // jobs[i][1] = deadline
    int jobs[7][2] = {
        {35, 3},
        {30, 4},
        {25, 4},
        {20, 2},
        {15, 3},
        {12, 1},
        {5,  2}
    };

    int n = 7;

    // -------------------------------
    // Step 1: Bubble sort by profit (descending)
    // -------------------------------
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (jobs[j][0] < jobs[j + 1][0]) {
                // swap both profit and deadline
                int tempProfit = jobs[j][0];
                int tempDeadline = jobs[j][1];

                jobs[j][0] = jobs[j + 1][0];
                jobs[j][1] = jobs[j + 1][1];

                jobs[j + 1][0] = tempProfit;
                jobs[j + 1][1] = tempDeadline;
            }
        }
    }

    // -------------------------------
    // Step 2: Find the max deadline
    // -------------------------------
    int last = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i][1] > last) {
            last = jobs[i][1];
        }
    }

    // slots array of size = last + 1
    // slot[t] = 1 means occupied
    int slots[100] = {0}; // enough size

    int totalProfit = 0;

    // -------------------------------
    // Step 3: Job Sequencing Logic
    // -------------------------------
    for (int i = 0; i < n; i++) {
        int profit = jobs[i][0];
        int deadline = jobs[i][1];

        // try placing this job at the latest slot <= deadline
        for (int t = deadline; t >= 1; t--) {
            if (slots[t] == 0) {
                slots[t] = 1;
                totalProfit += profit;
                break;
            }
        }
    }

    cout << "Total Profit = " << totalProfit << endl;

    return 0;
}
