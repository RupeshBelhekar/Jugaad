#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Partition function to divide the array
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Choosing the last element as pivot
    int i = (low - 1);      // Index of the smaller element

    for (int j = low; j < high; j++) {
        // If the current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);  // Swap the smaller element to the left
        }
    }
    swap(arr[i + 1], arr[high]);  // Place the pivot in the correct position
    return (i + 1);
}

// Quick Sort function using Divide and Conquer
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partitioning index
        int pi = partition(arr, low, high);

        // Separately sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to generate random input data
vector<int> generateRandomArray(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % n;  // Generating random numbers in range [0, n-1]
    }
    return arr;
}

// Function to display the array (only first 10-15 elements)
void displayArray(const vector<int>& arr) {
    int n = arr.size();
    
    // Display the first 10 to 15 elements
    for (int i = 0; i < 15 && i < n; i++) {
        cout << arr[i] << " ";
    }

    // If the array has more than 15 elements, show ellipses and the last element
    if (n > 15) {
        cout << "... " << arr[n - 1];
    }
    cout << endl;
}

// Function to analyze quick sort performance
void analyzeQuickSort(int n) {
    // Generate random array of size n
    vector<int> arr = generateRandomArray(n);

    // Display the unsorted array
    cout << "\nUNSORTED ARRAY (Size " << n << "): ";
    displayArray(arr);

    // Measure execution time of quick sort
    auto start = high_resolution_clock::now();  // Start timer
    quickSort(arr, 0, n - 1);                   // Quick Sort call
    auto stop = high_resolution_clock::now();   // Stop timer

    // Display the sorted array
    cout << "SORTED ARRAY (Size " << n << "): ";
    displayArray(arr);

    // Calculate duration
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken to sort array of size " << n << ": " 
         << duration.count() << " ms" << endl;

     cout << "--------------+---------------------+---------------------+------------------+------------------+-----------------+---------------+"<<endl;
}

int main() {
    srand(time(0));  // Seed the random number generator

    // Analyze for different input sizes
    vector<int> inputSizes = {1000, 5000, 10000, 50000, 100000};
    
    cout << "Quick Sort Performance Analysis:" << endl;
    for (int n : inputSizes) {
        analyzeQuickSort(n);  // Call function to analyze for each input size
    }

    return 0;
}
