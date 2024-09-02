class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive;
        vector<int> negative;
        int n = nums.size();
        vector<int> result(n);
        
        // Separate the numbers into positive and negative vectors
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (num > 0) {
                positive.push_back(num);
            } else {
                negative.push_back(num);
            }
        }

        // Initialize indices for the positive and negative arrays
        int posIndex = 0;
        int negIndex = 0;

        // Fill the result array with alternating positive and negative numbers
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                result[i] = positive[posIndex++];
            } else {
                result[i] = negative[negIndex++];
            }
        }

        return result;
    }
};
