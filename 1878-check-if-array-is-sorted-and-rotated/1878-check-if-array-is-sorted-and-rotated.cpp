class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(); // Initialize n with the size of the array
        int count = 0; // To count the number of breaks in the sorted order

        for(int i = 1; i < n; i++) {
            if(nums[i] < nums[i-1]) {
                count++; // Increment count if the current element is smaller than the previous one
            }
        }

        // We also need to check if the last element is greater than the first element
        // because it can be a rotated array where the last part is smaller than the first
        if(nums[n-1] > nums[0]) {
            count++;
        }

        return count <= 1; // If there is more than one break, it cannot be a rotated sorted array
    }
};
