#include <iostream>
#include <vector>
#include <algorithm> // For sort function
#include <cstdlib>   // For rand() function
#include <ctime>     // For time function
#include <set>       // For set to ensure unique elements
#include <chrono>

using namespace std;
using namespace std::chrono;

void Merge(vector<int>& arr, int s, int e, int mid)
{
    int n1 = mid - s + 1;
    int n2 = e - mid;
    int arrL[n1]; // left side array.
    int arrR[n2]; // Right side array.

    int MainArrIndex = s;
    for (int i = 0; i < n1; i++)
    {
        arrL[i] = arr[MainArrIndex++];
    }

    MainArrIndex = mid + 1;
    for (int j = 0; j < n2; j++)
    {
        arrR[j] = arr[MainArrIndex++];
    }

    int i = 0, j = 0;
    MainArrIndex = s;
    while (i < n1 && j < n2)
    {
        if (arrL[i] < arrR[j])
        {
            arr[MainArrIndex++] = arrL[i++];
        }
        else
        {
            arr[MainArrIndex++] = arrR[j++];
        }
    }

    while (i < n1)
    { // extra element in left array
        arr[MainArrIndex++] = arrL[i++];
    }

    while (j < n2)
    { // extra element in right array
        arr[MainArrIndex++] = arrR[j++];
    }
}

void MergeSort(vector<int>& arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int mid = s + (e - s) / 2;
    MergeSort(arr, s, mid);     // left divide
    MergeSort(arr, mid + 1, e); // right divide
    Merge(arr, s, e, mid);      // merge left and right.
}

int BinarySearch(vector<int>& arr, int s, int e, int key)
{
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            return BinarySearch(arr, mid + 1, e, key);
        }
        else
        {
            return BinarySearch(arr, s, mid - 1, key);
        }
    }

    return -1;
}

void DisplayArray(const vector<int>& arr)
{
    int n = arr.size();

    // Display the first 10 to 15 elements
    for (int i = 0; i < 15 && i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // If there are more elements, add ellipses and show the last element
    if (n > 15)
    {
        cout << "..................... " << arr[n - 1];
    }
    cout << endl;
}

int main()
{
    set<int> uniqueSet;
    vector<int> arr;

    // Seed random number generator
    srand(time(0));

    // Generate 5000 unique random elements
    while (uniqueSet.size() < 5000)
    {
        uniqueSet.insert(rand());
    }

    // Copy unique elements into vector
    arr.assign(uniqueSet.begin(), uniqueSet.end());
    random_shuffle(arr.begin(), arr.end());

    // Display unsorted array
    cout << "UNSORTED ARRAY" << endl;
    DisplayArray(arr);

    auto start = high_resolution_clock::now();
    // Sort the array using merge sort
    MergeSort(arr, 0, arr.size() - 1);

    // Get ending timepoint
 
    // Get duration. Substart timepoints to 
    // get duration. To cast it to proper unit
    // use duration cast method

    cout << "\n-------------------------------------------------------------------------------------------------------------------\n";
    cout << "\nSORTED ARRAY" << endl;
    DisplayArray(arr);
    cout<<endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}
