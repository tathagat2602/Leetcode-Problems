class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> remainderCount(k, 0);  // Array to store remainders

        // Count the remainders of all elements when divided by k
        for (int i = 0; i < n; i++) {
            int remainder = (arr[i] % k + k) % k;  // Handle negative numbers
            remainderCount[remainder]++;
        }

        // Now check the pairing of remainders
        for (int i = 1; i < k; i++) {
            // Check if there are equal numbers of remainder `i` and `k-i`
            if (remainderCount[i] != remainderCount[k - i]) {
                return false;
            }
        }

        // Special case for remainder 0 (must be even, as it can only pair with itself)
        if (remainderCount[0] % 2 != 0) {
            return false;
        }

        return true;
    }
};
