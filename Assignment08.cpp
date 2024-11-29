#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

// Function to calculate distance between two points
double calculateDistance(pair<int, int> a, pair<int, int> b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

// Brute Force Approach
double tspBruteForce(const vector<pair<int, int>> &points, vector<int> &bestRoute) {
    int n = points.size();
    vector<int> route(n);
    for (int i = 0; i < n; ++i) route[i] = i; // Initialize the route as {0, 1, ..., n-1}

    double minDistance = INT_MAX;

    // Sort the route to ensure we start with the first permutation
    sort(route.begin(), route.end());

    // Generate all permutations
    while (next_permutation(route.begin(), route.end())) {
        double currentDistance = 0;
        for (int i = 0; i < n - 1; ++i) {
            currentDistance += calculateDistance(points[route[i]], points[route[i + 1]]);
        }
        currentDistance += calculateDistance(points[route[n - 1]], points[route[0]]); // Return to start

        if (currentDistance < minDistance) {
            minDistance = currentDistance;
            bestRoute = route;
        }
    }

    return minDistance;
}


// Greedy Approach
double tspGreedy(const vector<pair<int, int>> &points, vector<int> &route) {
    int n = points.size();
    vector<bool> visited(n, false);
    route.push_back(0); // Start from the first point
    visited[0] = true;

    double totalDistance = 0;

    for (int i = 0; i < n - 1; ++i) {
        int current = route.back();
        double minDist = INT_MAX;
        int next = -1;

        for (int j = 0; j < n; ++j) {
            if (!visited[j] && calculateDistance(points[current], points[j]) < minDist) {
                minDist = calculateDistance(points[current], points[j]);
                next = j;
            }
        }

        route.push_back(next);
        visited[next] = true;
        totalDistance += minDist;
    }

    // Return to the starting point
    totalDistance += calculateDistance(points[route.back()], points[0]);
    route.push_back(0);

    return totalDistance;
}

int main() {
    // Points for TSP (x, y)
    vector<pair<int, int>> points = {{0, 0}, {2, 4}, {5, 0}, {6, 3}, {8, 1}};
    vector<int> bestRoute, greedyRoute;

    cout << "Solving TSP with Brute Force:\n";
    double bruteForceDistance = tspBruteForce(points, bestRoute);
    cout << "Optimal Distance: " << bruteForceDistance << "\nRoute: ";
    for (int i : bestRoute) cout << i << " ";
    cout << "0\n"; // Returning to the starting point

    cout << "\nSolving TSP with Greedy Algorithm:\n";
    double greedyDistance = tspGreedy(points, greedyRoute);
    cout << "Approximate Distance: " << greedyDistance << "\nRoute: ";
    for (int i : greedyRoute) cout << i << " ";
    cout << "\n";

    return 0;
}
