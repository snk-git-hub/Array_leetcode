#include<iostream>
#include<vector>

using namespace std;

int main() {
    // Input array
    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();  // Size of the array

    // Resultant array to store the final product values
    vector<int> ans(n);

    // Auxiliary arrays to store prefix and suffix products
    vector<int> prefix(n, 1);  // Initialize prefix array with 1
    vector<int> suffix(n, 1);  // Initialize suffix array with 1

    //////////////////////////////////////////////////////////
    // Calculate prefix products
    // prefix[i] will store the product of all elements to the left of index i
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] * arr[i - 1]; // Accumulate product from the left
    }

    // Calculate suffix products
    // suffix[i] will store the product of all elements to the right of index i
    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] * arr[i + 1]; // Accumulate product from the right
    }

    // Calculate the final result
    // ans[i] = prefix[i] * suffix[i], which is the product of all elements except arr[i]
    for (int i = 0; i < n; i++) {
        ans[i] = prefix[i] * suffix[i]; // Multiply prefix and suffix values
    }
    //////////////////////////////////////////////////////////

    // Print the resultant array
    cout << "Product array except self: ";
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl; // Newline for better readability

    return 0;
}
