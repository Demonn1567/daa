#include <iostream>
using namespace std;

// sort intervals by end time (second column)
void sortByEnd(int arr[][2], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i][1] > arr[j][1])
            {
                // swap both start and end to keep the pair together
                int s = arr[i][0];
                int e = arr[i][1];

                arr[i][0] = arr[j][0];
                arr[i][1] = arr[j][1];

                arr[j][0] = s;
                arr[j][1] = e;
            }
        }
    }
}

int main()
{
    int arr[][2] = {
        {1, 4},
        {3, 5},
        {0, 6},
        {5, 7},
        {8, 9},
        {2, 14}};

    int n = sizeof(arr) / sizeof(arr[0]);

    sortByEnd(arr, n);

    // greedy activity selection
    // always take the first (earliest finishing) interval
    int lastEnd = arr[0][1];
    cout << "start: " << arr[0][0] << " end: " << arr[0][1] << '\n';

    for (int i = 1; i < n; i++)
    {
        if (arr[i][0] >= lastEnd)
        {
            cout << "start: " << arr[i][0] << " end: " << arr[i][1] << '\n';
            lastEnd = arr[i][1];
        }
    }

    return 0;
}