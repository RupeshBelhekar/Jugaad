#include <iostream>
#include <vector>

using namespace std;

// Function to find subsets that sum to a given target
void findSubsets(vector<int>& set, vector<int>& current, int index, int target, vector<vector<int>>& results) {
    // Base case: target is met
    if (target == 0) {
        results.push_back(current);
        return;
    }

    // Base case: target can't be met or all elements processed
    if (target < 0 || index == set.size()) return;

    // Include the current element
    current.push_back(set[index]);
    findSubsets(set, current, index + 1, target - set[index], results);
    current.pop_back(); // Backtrack

    // Exclude the current element
    findSubsets(set, current, index + 1, target, results);
}

int main() {
    int n;
    cout << "Enter the number of elements in the set: ";
    cin >> n;

    vector<int> set(n);
    cout << "Enter the elements of the set: ";
    for (int i = 0; i < n; ++i) {
        cin >> set[i];
    }

    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    vector<vector<int>> results;
    vector<int> current;

    findSubsets(set, current, 0, target, results);

    if (!results.empty()) {
        cout << "Subsets that sum to " << target << ":\n";
        for (const auto& subset : results) {
            cout << "{ ";
            for (int elem : subset) {
                cout << elem << " ";
            }
            cout << "}\n";
        }
    } else {
        cout << "No subset found that sums to " << target << ".\n";
    }

    return 0;
}

