# Algorithm Collection

This repository contains implementations of various fundamental algorithms used in competitive programming and problem-solving. Each algorithm follows a specific pattern, making them useful for optimizing time complexity and improving efficiency.

## 1. Kadane's Algorithm (Maximum Subarray Sum)
### Problem Statement:
Find the contiguous subarray (containing at least one number) that has the largest sum.

### Pseudocode:
```
Initialize max_sum = INT_MIN, current_sum = 0
For each element in the array:
    Add element to current_sum
    Update max_sum if current_sum > max_sum
    If current_sum < 0, reset it to 0
Return max_sum
```

### C++ Implementation:
```cpp
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int kadane(vector<int>& nums) {
    int max_sum = INT_MIN, current_sum = 0;
    for (int num : nums) {
        current_sum += num;
        max_sum = max(max_sum, current_sum);
        if (current_sum < 0) current_sum = 0;
    }
    return max_sum;
}
```

---
## 2. Prefix Sum Algorithm
### Problem Statement:
Precompute prefix sums to quickly answer sum queries for any subarray.

### Pseudocode:
```
Initialize prefix[0] = 0
For i from 1 to n:
    prefix[i] = prefix[i-1] + arr[i]
To get sum of range [L, R]:
    sum = prefix[R] - prefix[L-1]
```

### C++ Implementation:
```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> prefixSum(vector<int>& arr) {
    int n = arr.size();
    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }
    return prefix;
}
```

---
## 3. Fixed-Size Sliding Window
### Problem Statement:
Find the maximum sum of a subarray with a fixed size `k`.

### Pseudocode:
```
Initialize window_sum = sum of first k elements
For i from k to n:
    Update window_sum by adding arr[i] and removing arr[i-k]
    Update max_sum if needed
Return max_sum
```

### C++ Implementation:
```cpp
#include <iostream>
#include <vector>
using namespace std;

int fixedSlidingWindow(vector<int>& nums, int k) {
    int max_sum = 0, window_sum = 0;
    for (int i = 0; i < k; i++) window_sum += nums[i];
    max_sum = window_sum;
    
    for (int i = k; i < nums.size(); i++) {
        window_sum += nums[i] - nums[i - k];
        max_sum = max(max_sum, window_sum);
    }
    return max_sum;
}
```

---
## 4. Variable-Size Sliding Window
### Problem Statement:
Find the shortest subarray with a sum ≥ target.

### Pseudocode:
```
Initialize L = 0, sum = 0, min_length = INT_MAX
For R from 0 to n:
    Add arr[R] to sum
    While sum >= target:
        Update min_length
        Subtract arr[L] and move L forward
Return min_length
```

### C++ Implementation:
```cpp
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int variableSlidingWindow(vector<int>& nums, int target) {
    int L = 0, sum = 0, min_length = INT_MAX;
    for (int R = 0; R < nums.size(); R++) {
        sum += nums[R];
        while (sum >= target) {
            min_length = min(min_length, R - L + 1);
            sum -= nums[L++];
        }
    }
    return min_length == INT_MAX ? 0 : min_length;
}
```

---
## 5. Two Pointers Technique
### Problem Statement:
Find pairs that satisfy a given condition (e.g., two numbers that sum to a target).

### Pseudocode:
```
Sort the array
Initialize two pointers: L = 0, R = n-1
While L < R:
    Compute current_sum = arr[L] + arr[R]
    If current_sum == target, return indices
    If current_sum < target, move L forward
    Else move R backward
Return -1 (not found)
```

### C++ Implementation:
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> twoPointerSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int L = 0, R = nums.size() - 1;
    while (L < R) {
        int sum = nums[L] + nums[R];
        if (sum == target) return {L, R};
        else if (sum < target) L++;
        else R--;
    }
    return {-1, -1};
}
```

## Usage:
Each algorithm is implemented in C++ and can be executed independently. The implementations are optimized for competitive programming scenarios where efficiency is crucial.

