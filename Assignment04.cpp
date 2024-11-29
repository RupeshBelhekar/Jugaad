#include <iostream>
#include <vector>
#include <iomanip> // for setw() to align output
using namespace std;

const int INF = 1e9; // Representing infinity

// Function to print the current state of the distance matrix
void printMatrix(const vector<vector<int>>& dist, int step, int k = -1) {
    int n = dist.size();
    cout << "\nStep " << step;
    if (k != -1) cout << " (Considering vertex " << k << " as intermediate):";
    cout << "\n----------------------------------\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF)
                cout << setw(5) << "INF";
            else
                cout << setw(5) << dist[i][j];
        }
        cout << endl;
    }
    cout << "----------------------------------\n";
}

// Function to implement Floyd-Warshall Algorithm with step-by-step output
void floydWarshall(vector<vector<int>>& dist) {
    int n = dist.size();
    int step = 0;

    // Initial state of the distance matrix
    printMatrix(dist, ++step);

    // Iterating through all possible intermediate vertices
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // If the path through vertex 'k' is shorter, update it
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    int newDist = dist[i][k] + dist[k][j];
                    if (newDist < dist[i][j]) {
                        dist[i][j] = newDist;
                    }
                }
            }
        }
        // Print the matrix after considering each vertex 'k'
        printMatrix(dist, ++step, k);
    }
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));

    cout << "Enter the adjacency matrix (use " << INF << " for no direct edge):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout<<"\n[ "<<i<<" -> "<<j<<" ]: ";
            cin >> dist[i][j];
        }
    }

    // Apply Floyd-Warshall algorithm with step-by-step output
    floydWarshall(dist);

    cout << "\nFinal All-Pairs Shortest Paths Matrix:";
    printMatrix(dist, -1); // Final result

    return 0;
}
