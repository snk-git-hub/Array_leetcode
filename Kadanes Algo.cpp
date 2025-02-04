#include <vector>
#include <algorithm>

using std::vector;
using std::max;

// Brute Force Approach: O(n^2)
// This method checks every possible subarray and calculates its sum.
int bruteForce(vector<int>& nums) {
    int maxSum = nums[0];  // Initialize maxSum with the first element

    // Outer loop: Start from each element in the array
    for (int i = 0; i < nums.size(); i++) {
        int curSum = 0;  // Initialize current sum for the subarray starting at index i

        // Inner loop: Extend the subarray from index i to the end
        for (int j = i; j < nums.size(); j++) {
            curSum += nums[j];  // Add the current element to the current sum
            maxSum = max(maxSum, curSum);  // Update maxSum if the current sum is greater
        }
    }
    return maxSum;  // Return the maximum sum found
}

// Kadane's Algorithm: O(n)
// This method efficiently finds the maximum subarray sum in linear time.
int kadanes(vector<int>& nums) {
    int maxSum = nums[0];  // Initialize maxSum with the first element
    int curSum = 0;  // Initialize current sum

    // Iterate through each element in the array
    for (int n : nums) {
        curSum = max(curSum, 0);  // Reset current sum to 0 if it becomes negative
        curSum += n;  // Add the current element to the current sum
        maxSum = max(maxSum, curSum);  // Update maxSum if the current sum is greater
    }
    return maxSum;  // Return the maximum sum found
}

// Sliding Window Variation of Kadane's Algorithm: O(n)
// This method not only finds the maximum subarray sum but also the indices of the subarray.
vector<int> slidingWindow(vector<int> nums) {
    int maxSum = nums[0];  // Initialize maxSum with the first element
    int curSum = 0;  // Initialize current sum
    int maxL = 0, maxR = 0;  // Initialize indices for the maximum subarray
    int L = 0;  // Initialize the left pointer for the sliding window

    // Iterate through each element in the array
    for (int R = 0; R < nums.size(); R++) {
        // If current sum is negative, reset it and move the left pointer to the current index
        if (curSum < 0) {
            curSum = 0;
            L = R;
        }
        curSum += nums[R];  // Add the current element to the current sum

        // If the current sum is greater than maxSum, update maxSum and the indices
        if (curSum > maxSum) {
            maxSum = curSum;
            maxL = L;  // Update the left index of the maximum subarray
            maxR = R;  // Update the right index of the maximum subarray
        }    
    }    
    return vector<int>{maxL, maxR};  // Return the indices of the maximum subarray
}
