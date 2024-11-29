#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the maximum value using backtracking
void knapsackBacktrack(int index, int currentWeight, int currentValue, int& maxValue,
                       const vector<int>& weights, const vector<int>& values, int capacity) {
    // Base case: if we've considered all items
    if (index == weights.size()) {
        maxValue = max(maxValue, currentValue);
        return;
    }

    // Skip the current item
    knapsackBacktrack(index + 1, currentWeight, currentValue, maxValue, weights, values, capacity);

    // Include the current item (if it doesn't exceed capacity)
    if (currentWeight + weights[index] <= capacity) {
        knapsackBacktrack(index + 1, currentWeight + weights[index], currentValue + values[index],
                          maxValue, weights, values, capacity);
    }
}

int main() {
    int n, capacity;

    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    vector<int> weights(n), values(n);

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; ++i) {
        cin >> weights[i]; 
    }

    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    int maxValue = 0;
    knapsackBacktrack(0, 0, 0, maxValue, weights, values, capacity);

    cout << "The maximum value that can be obtained is: " << maxValue << endl;

    return 0;
}
