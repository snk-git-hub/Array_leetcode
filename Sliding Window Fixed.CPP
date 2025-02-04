#include <vector>
#include <unordered_set>
#include <algorithm>

using std::vector;
using std::unordered_set;
using std::min;

// Brute force approach to check if the array contains a pair of duplicate values
// where the two duplicates are no farther than k positions apart.
// Time Complexity: O(n * k)
bool closeDuplicatesBruteForce(vector<int>& nums, int k) {
    int size = static_cast<int>(nums.size());
    for (int L = 0; L < size; L++) { // Iterate through each element
        for (int R = L + 1; R < min(size, L + k); R++) { // Check next k elements
            if (nums[L] == nums[R]) { // If a duplicate is found within k distance
                return true;
            }
        }
    }
    return false; // No duplicates found within k distance
}

// Optimized approach using a sliding window technique.
// Time Complexity: O(n)
bool closeDuplicates(vector<int>& nums, int k) {
    unordered_set<int> window; // Stores the elements in the current window of size <= k
    int L = 0; // Left boundary of the sliding window

    for (int R = 0; R < nums.size(); R++) { // Iterate through the array
        if (R - L + 1 > k) { // If window size exceeds k
            window.erase(nums[L]); // Remove the leftmost element from the set
            L++; // Move the left boundary forward
        }
        if (window.count(nums[R]) > 0) { // If the current element already exists in the set, duplicate found
            return true;
        }
        window.insert(nums[R]); // Insert current element into the set
    }
    return false; // No duplicates found within k distance
}
