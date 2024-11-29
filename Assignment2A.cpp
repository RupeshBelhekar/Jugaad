#include <iostream>
#include <vector>
#include <cstdlib>   // For rand() function
#include <ctime>     // For time function
#include <set>       // For set to ensure unique elements
#include <chrono>    // For time measurements
#include<algorithm>  // random_shuffle

using namespace std;
using namespace std::chrono;

// Function to merge two halves of the array
void Merge(vector<int>& arr, int s, int e, int mid) {
    int n1 = mid - s + 1;
    int n2 = e - mid;
    
    // Temporary arrays to hold the divided elements
    vector<int> arrL(n1), arrR(n2);

    for (int i = 0; i < n1; i++)
        arrL[i] = arr[s + i];

    for (int i = 0; i < n2; i++)
        arrR[i] = arr[mid + 1 + i];

    // Merge the temporary arrays back into the main array
    int i = 0, j = 0, k = s;
    while (i < n1 && j < n2) {
        if (arrL[i] <= arrR[j])
            arr[k++] = arrL[i++];
        else
            arr[k++] = arrR[j++];
    }

    // Copy the remaining elements of left and right subarrays (if any)
    while (i < n1)
        arr[k++] = arrL[i++];

    while (j < n2)
        arr[k++] = arrR[j++];
}

// Function to perform Merge Sort
void MergeSort(vector<int>& arr, int s, int e) {
    if (s < e) {
        int mid = s + (e - s) / 2;
        MergeSort(arr, s, mid);        // Sort the first half
        MergeSort(arr, mid + 1, e);    // Sort the second half
        Merge(arr, s, e, mid);         // Merge the sorted halves
    }
}

// Function to display array
void DisplayArray(const vector<int>& arr) {
    int n = arr.size();
    // Display first 10-15 elements
    for (int i = 0; i < 15 && i < n; i++) {
        cout << arr[i] << " ";
    }

    // Display ellipses and last element if array has more than 15 elements
    if (n > 15) {
        cout << "..................... " << arr[n - 1];
    }
    cout << endl;
}

// Function to generate random array with unique elements
vector<int> generateUniqueArray(int n) {
    set<int> uniqueSet;
    while (uniqueSet.size() < n) {
        uniqueSet.insert(rand() % n); // Generate numbers in range [0, n-1]
    }
    vector<int> arr(uniqueSet.begin(), uniqueSet.end());
    random_shuffle(arr.begin(), arr.end()); // Shuffle to make it unsorted
    return arr;
}

// Function to analyze Merge Sort performance for different input sizes
void analyzeMergeSort(const vector<int>& inputSizes) {
    cout << "Merge Sort Performance Analysis:" << endl;
    for (int n : inputSizes) {
        vector<int> arr = generateUniqueArray(n);  // Generate unique random array
        
        // Display unsorted array (limited to first 15 elements)
        cout << "\nUNSORTED ARRAY (Size " << n << "): ";
        DisplayArray(arr);

        // Start timer
        auto start = high_resolution_clock::now();
        // Sort the array using Merge Sort
        MergeSort(arr, 0, arr.size() - 1);

        // Stop timer
        auto stop = high_resolution_clock::now();

        // Display sorted array (limited to first 15 elements)
        cout << "\nSORTED ARRAY (Size " << n << "): ";
        DisplayArray(arr);

        // Calculate and display execution time
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time taken to sort array of size " << n << ": "
             << duration.count() << " microseconds" << endl;
            
        cout << "--------------+---------------------+---------------------+--------------------+--------------------+-------------------+-----------------+"<<endl;
    }
}

int main() {
    srand(time(0));  // Seed random number generator

    // Define different input sizes for analysis
    vector<int> inputSizes = {1000, 5000, 10000, 50000, 100000};

    // Analyze Merge Sort for different input sizes
    analyzeMergeSort(inputSizes);

    return 0;
}
