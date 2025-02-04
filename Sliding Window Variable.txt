#include <vector>
#include <climits>
#include <algorithm>

using std::vector;
using std::max;
using std::min;

// Find the length of the longest contiguous subarray where all elements are the same.
// Time Complexity: O(n)
int longestSubarray(vector<int>& nums) {
    int length = 0;
    int L = 0;

    for (int R = 0; R < nums.size(); R++) {
        if (nums[L] != nums[R]) { // If current element is different, reset left boundary
            L = R;
        }
        length = max(length, R - L + 1); // Update the maximum length found
    }
    return length;
}

// Find the length of the smallest contiguous subarray where the sum is 
// greater than or equal to the target value.
// Time Complexity: O(n)
int shortestSubarray(vector<int>& nums, int target) {
    int L = 0, total = 0;
    int length = INT_MAX; // Initialize with a large value

    for (int R = 0; R < nums.size(); R++) {
        total += nums[R]; // Expand the window by adding the current element
        while (total >= target) { // Shrink the window while condition is met
            length = min(R - L + 1, length); // Update the shortest subarray length
            total -= nums[L]; // Remove the leftmost element from the sum
            L++; // Move left boundary forward
        }
    }
    return (length == INT_MAX) ? 0 : length; // If no valid subarray found, return 0
}
