/*
    Problem: Sort an Array of 0s, 1s, and 2s

    Description:
    You are given an array arr consisting only of 0s, 1s, and 2s.
    The task is to sort the array in increasing order in linear time (O(n))
    without using any extra space (in-place).

    Input:
    An integer array arr of size n where each element is either 0, 1, or 2.
    Example : arr = [0, 1, 2, 1, 0, 2, 1, 0]

    Output:
    The sorted array, arranged in increasing order of 0s, 1s, and 2s.
    Example: [0, 0, 0, 1, 1, 1, 2, 2]

    Constraints:
    - The input array may have up to 10^5 elements.
    - The values in the array are limited to 0, 1, and 2.
    - Must operate in O(n) time and in-place.

    Approach:
    This can be solved using the Dutch National Flag Algorithm by Edsger Dijkstra.
    Use three pointers: low (for next 0), mid (current index), high (for next 2).

    Test Cases:
    Input:  [0, 1, 2, 1, 0, 2, 1, 0]  → Output: [0, 0, 0, 1, 1, 1, 2, 2]
    Input:  [2, 2, 2, 2]              → Output: [2, 2, 2, 2]
    Input:  [0, 0, 0, 0]              → Output: [0, 0, 0, 0]
    Input:  [1, 1, 1, 1]              → Output: [1, 1, 1, 1]
    Input:  [2, 0, 1]                 → Output: [0, 1, 2]
    Input:  []                        → Output: []

    Edge Cases:
    - Empty array
    - Array with all elements the same
    - Already sorted array
*/

#include <iostream>
#include <vector>
using namespace std;

void sort012(vector<int>& arr) {
    int low = 0;                 // Position for next 0
    int mid = 0;                 // Current element
    int high = arr.size() - 1;   // Position for next 2

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else { // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    vector<vector<int>> testCases = {
        {0, 1, 2, 1, 0, 2, 1, 0},  // Example 1
        {2, 2, 2, 2},              // Example 2
        {0, 0, 0, 0},              // Example 3
        {1, 1, 1, 1},              // Example 4
        {2, 0, 1},                 // Example 5
        {}                         // Example 6
    };

    for (auto &arr : testCases) {
        sort012(arr);
        cout << "[";
        for (size_t i = 0; i < arr.size(); i++) {
            cout << arr[i];
            if (i < arr.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
