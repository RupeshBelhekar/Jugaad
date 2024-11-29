#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node {
    int level, profit, bound, weight;
    vector<int> items; // Store selected items for each node
};

// Function to calculate bound (upper bound) for branch and bound
int bound(Node u, int n, int W, vector<int>& wt, vector<int>& val) {
    if (u.weight >= W) return 0;

    int profit_bound = u.profit;
    int j = u.level + 1;
    int totalWeight = u.weight;

    while (j < n && totalWeight + wt[j] <= W) {
        totalWeight += wt[j];
        profit_bound += val[j];
        j++;
    }

    if (j < n)
        profit_bound += (W - totalWeight) * val[j] / wt[j];

    return profit_bound;
}

// Function to solve 0/1 Knapsack using branch and bound and show selected weights
int knapsackBB(int W, vector<int>& wt, vector<int>& val, int n, vector<int>& selectedItems) {
    queue<Node> Q;
    Node u, v;

    v.level = -1;
    v.profit = v.weight = 0;
    Q.push(v);

    int maxProfit = 0;
    while (!Q.empty()) {
        v = Q.front();
        Q.pop();

        if (v.level == n - 1) continue;

        u.level = v.level + 1;

        // Take the current item
        u.weight = v.weight + wt[u.level];
        u.profit = v.profit + val[u.level];
        u.items = v.items;
        u.items.push_back(wt[u.level]);

        if (u.weight <= W && u.profit > maxProfit) {
            maxProfit = u.profit;
            selectedItems = u.items;
        }

        u.bound = bound(u, n, W, wt, val);

        if (u.bound > maxProfit)
            Q.push(u);

        // Don't take the current item
        u.weight = v.weight;
        u.profit = v.profit;
        u.items = v.items;
        u.bound = bound(u, n, W, wt, val);

        if (u.bound > maxProfit)
            Q.push(u);
    }
    return maxProfit;
}
int main() {
    int W = 15; // Maximum weight of knapsack
    vector<int> wt = {2,4,6,9}; // Weights of items
    vector<int> val = {10,10,12,18}; // Values of items
    int n = wt.size();
    vector<int> selectedItems;
    int result = knapsackBB(W, wt, val, n, selectedItems);
    cout << "Maximum value in Knapsack using Branch and Bound = " << result << endl;
    cout << "Selected Weights: ";
    for (int w : selectedItems) cout << w << " ";
    cout << endl;
}