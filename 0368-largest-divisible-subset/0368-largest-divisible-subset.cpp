class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // Step 1: Sort the input array
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        // Step 2: Create a DP array where dp[i] holds the size of the largest subset ending at index i
        vector<int> dp(n, 1);
        // Step 3: Create an array to track the previous index for reconstruction of the subset
        vector<int> prev(n, -1);
        
        // Variable to track the index of the largest subset
        int maxIdx = 0;
        int maxSize = 1;

        // Step 4: Fill the dp array
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // If nums[i] is divisible by nums[j], we can extend the subset ending at j
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            // Keep track of the maximum size and the index where it occurs
            if (dp[i] > maxSize) {
                maxSize = dp[i];
                maxIdx = i;
            }
        }

        // Step 5: Reconstruct the largest divisible subset
        vector<int> result;
        for (int i = maxIdx; i >= 0; i = prev[i]) {
            result.push_back(nums[i]);
            if (prev[i] == -1) break;
        }
        
        // The result is constructed in reverse order, so we reverse it back
        reverse(result.begin(), result.end());
        
        return result;
    }
};
