#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

// ==========================================
// PROBLEM 1: MERGE SORT (Sorting)
// Complexity: O(n log n)
// ==========================================
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) { arr[k] = L[i]; i++; }
        else { arr[k] = R[j]; j++; }
        k++;
    }
    while (i < n1) { arr[k] = L[i]; i++; k++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// ==========================================
// PROBLEM 2: BINARY SEARCH (Searching)
// Complexity: O(log n)
// ==========================================
int binarySearch(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// ==========================================
// PROBLEM 3: FRACTIONAL KNAPSACK (Greedy)
// Complexity: O(n log n) due to sorting
// ==========================================
struct Item {
    int value, weight;
};

bool compareItems(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), compareItems);
    double finalValue = 0.0;
    for (const auto& item : items) {
        if (W >= item.weight) {
            W -= item.weight;
            finalValue += item.value;
        } else {
            finalValue += item.value * ((double)W / item.weight);
            break;
        }
    }
    return finalValue;
}

// ==========================================
// DRIVER & RUNTIME MEASUREMENT
// ==========================================
int main() {
    cout << "--- TASK 2: ALGORITHMS & RUNTIME ANALYSIS ---\n\n";

    // --- Testing Merge Sort with small vs large input sizes ---
    cout << "[1] Testing Merge Sort runtime:\n";
    vector<int> smallInput, largeInput;
    for(int i = 5000; i > 0; i--) smallInput.push_back(i);
    for(int i = 50000; i > 0; i--) largeInput.push_back(i);

    // Measure Small Input (5,000 elements)
    auto start = high_resolution_clock::now();
    mergeSort(smallInput, 0, smallInput.size() - 1);
    auto stop = high_resolution_clock::now();
    cout << "-> Time taken for 5,000 elements: " 
         << duration_cast<microseconds>(stop - start).count() << " microseconds\n";

    // Measure Large Input (50,000 elements)
    start = high_resolution_clock::now();
    mergeSort(largeInput, 0, largeInput.size() - 1);
    stop = high_resolution_clock::now();
    cout << "-> Time taken for 50,000 elements: " 
         << duration_cast<microseconds>(stop - start).count() << " microseconds\n\n";

    // --- Testing Binary Search ---
    cout << "[2] Testing Binary Search:\n";
    int target = 42000;
    start = high_resolution_clock::now();
    int searchResult = binarySearch(largeInput, target);
    stop = high_resolution_clock::now();
    cout << "-> Searching for " << target << " in 50,000 sorted elements...\n";
    cout << "-> Found at index: " << searchResult << "\n";
    cout << "-> Time taken: " << duration_cast<nanoseconds>(stop - start).count() << " nanoseconds\n\n";

    // --- Testing Greedy Fractional Knapsack ---
    cout << "[3] Testing Greedy Knapsack:\n";
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
    int W = 50;
    double maxVal = fractionalKnapsack(W, items);
    cout << "-> Maximum value we can carry in knapsack (Capacity 50): " << maxVal << "\n";

    return 0;
}