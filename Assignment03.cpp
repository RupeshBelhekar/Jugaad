//Knapsack problem 0/1:
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an item
struct Item {
    int weight;
    int profit;
    
    // Constructor
    Item(int w, int p) : weight(w), profit(p) {}
};

// Function to calculate the profit-to-weight ratio and sort items
bool compare(const Item &a, const Item &b) {
    double r1 = (double)a.profit / a.weight;
    double r2 = (double)b.profit / b.weight;
    return r1 > r2;  // Sort in descending order of profit-to-weight ratio
}

// Function to calculate maximum profit using the fractional knapsack approach
double fractionalKnapsack(int W, vector<Item> &items) {
    // Sort items by profit-to-weight ratio
    sort(items.begin(), items.end(), compare);
    
    int currentWeight = 0; // Current weight in knapsack
    double totalProfit = 0.0; // Total profit

    for (auto &item : items) {
        if (currentWeight + item.weight <= W) {
            // If adding the whole item doesn't exceed capacity, take it
            currentWeight += item.weight;
            totalProfit += item.profit;
        } else {
            // If adding the whole item exceeds capacity, take a fraction of it
            int remainingWeight = W - currentWeight;
            totalProfit += (item.profit * ((double)remainingWeight / item.weight));
            break; // The knapsack is full
        }
    }

    return totalProfit;
}

int main() {
    // Knapsack capacity
    int W = 20;

    // List of items: {weight, profit}
    vector<Item> items = {
        Item(3, 10),
        Item(5, 20),
        Item(5, 21),
        Item(8, 30),
        Item(4, 16)
    };

    // Calculate maximum profit
    double maxProfit = fractionalKnapsack(W, items);

    // Print the result
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}
