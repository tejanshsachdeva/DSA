#include <iostream>
#include <vector>
#include <queue>

using namespace std; // Include the 'using namespace std;' directive

// Function to perform a k-way merge
vector<int> kWayMerge(vector<vector<int>>& inputArrays) {
    int k = inputArrays.size();
    vector<int> result;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    // Initialize the heap with the first element from each input array
    for (int i = 0; i < k; ++i) {
        if (!inputArrays[i].empty()) {
            minHeap.push({inputArrays[i][0], i});
            inputArrays[i].erase(inputArrays[i].begin());
        }
    }

    while (!minHeap.empty()) {
        pair<int, int> minElement = minHeap.top();
        minHeap.pop();
        result.push_back(minElement.first);
        int arrayIndex = minElement.second;

        // If there are more elements in the same input array, push the next element onto the heap
        if (!inputArrays[arrayIndex].empty()) {
            minHeap.push({inputArrays[arrayIndex][0], arrayIndex});
            inputArrays[arrayIndex].erase(inputArrays[arrayIndex].begin());
        }
    }

    return result;
}


// Function to perform k-way merge sort
vector<int> kWayMergeSort(vector<int>& input, int k) {
    int n = input.size();
    if (n <= 1) {
        return input;
    }

    // Divide the input into k parts
    vector<vector<int>> dividedArrays(k);
    int partSize = n / k;
    int remainder = n % k;

    int startIndex = 0;
    for (int i = 0; i < k; ++i) {
        int partLength = partSize + (i < remainder ? 1 : 0);
        dividedArrays[i].insert(dividedArrays[i].begin(), input.begin() + startIndex, input.begin() + startIndex + partLength);
        startIndex += partLength;
    }

    // Recursively sort each part
    for (int i = 0; i < k; ++i) {
        dividedArrays[i] = kWayMergeSort(dividedArrays[i], k);
    }

    // Merge the sorted parts using k-way merge
    return kWayMerge(dividedArrays);
}

int main() {
    vector<int> input = {12, 11, 13, 5, 6, 7, 10, 8};
    int k = 4;

    vector<int> sortedArray = kWayMergeSort(input, k);

    cout << "Sorted Array: ";
    for (int num : sortedArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
