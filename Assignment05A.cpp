#include <iostream>
#include <vector>
using namespace std;

const int N = 1e3 + 2; // Reduced size for practical use
int val[N], wt[N];
int dp[N][N];

int knapsack(int n, int w) {
    if (n <= 0 || w <= 0) {
        return 0; // Base case
    }

    if (dp[n][w] != -1) { // Fix: Check for already computed state
        return dp[n][w];
    }

    if (wt[n - 1] > w) {
        dp[n][w] = knapsack(n - 1, w); // Skip current item
    } else {
        dp[n][w] = max(
            knapsack(n - 1, w),                 // Skip current item
            knapsack(n - 1, w - wt[n - 1]) + val[n - 1] // Include current item
        );
    }

    return dp[n][w];
}

int main() {
    // Initialize dp array with -1
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = -1;
        }
    }

    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    int w;
    cout << "Enter the maximum weight capacity: ";
    cin >> w;

    cout << "Maximum value in knapsack: " << knapsack(n, w) << endl;

    return 0;
}
