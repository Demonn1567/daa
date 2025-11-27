#include <bits/stdc++.h>
using namespace std;

// Global variables to match the algorithm notation
int n;              // number of elements
int m;              // target sum
vector<int> w;      // weights: w[1..n], will keep index 0 unused
vector<int> x;      // solution vector: x[1..n]

// This function is exactly the algorithm from the slide:
//
// Algorithm SumofSub(s, k, r)
// // The initial call is SumofSub(0, 1, sum_{i=1}^n w_i)
//
// It finds all subsets of w[1..n] that sum to m.
// w[j]'s are assumed to be in nondecreasing order.
void SumofSub(int s, int k, int r)
{
    // Safety: if k > n, nothing more to do
    if (k > n) return;

    x[k] = 1;  // choose w[k]

    // if (s + w[k] = m) then write (x[1:k]);  // Subset Found
    if (s + w[k] == m)
    {
        // Print subset corresponding to x[1..k]
        cout << "{ ";
        for (int i = 1; i <= k; ++i)
        {
            if (x[i] == 1)
                cout << w[i] << " ";
        }
        cout << "}" << endl;
    }
    // else if (s + w[k] + w[k+1] <= m)
    //          then SumofSub(s + w[k], k+1, r - w[k]);
    else if (k < n && s + w[k] + w[k + 1] <= m)
    {
        SumofSub(s + w[k], k + 1, r - w[k]);
    }

    // if (s + r - w[k] >= m) and (s + w[k+1] <= m) then
    // {
    //     x[k] = 0;
    //     SumofSub(s, k+1, r - w[k]);
    // }
    if (k < n && (s + r - w[k] >= m) && (s + w[k + 1] <= m))
    {
        x[k] = 0;  // do NOT choose w[k]
        SumofSub(s, k + 1, r - w[k]);
    }
}

int main()
{
    cout << "Enter number of elements (n): ";
    cin >> n;

    w.assign(n + 1, 0);  // 1-based indexing
    x.assign(n + 1, 0);

    cout << "Enter the elements (weights) in nondecreasing order:\n";
    for (int i = 1; i <= n; ++i)
        cin >> w[i];

    cout << "Enter target sum m: ";
    cin >> m;

    // If you’re not sure input is sorted, uncomment this:
    // sort(w.begin() + 1, w.end());

    int r = 0;               // r = sum_{i=1}^n w_i
    for (int i = 1; i <= n; ++i)
        r += w[i];

    cout << "Subsets that sum to " << m << ":\n";
    SumofSub(0, 1, r);       // initial call exactly as in the algorithm

    return 0;
}
