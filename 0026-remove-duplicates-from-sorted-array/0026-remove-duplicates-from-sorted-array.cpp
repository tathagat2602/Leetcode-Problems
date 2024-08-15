class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;  // Handle empty array case
        
        int i = 0;  // Initialize the first pointer
        
        for (int j = 1; j < nums.size(); j++) {
            // Check if the current element is different from the last unique element
            if (nums[j] != nums[i]) {
                i++;  // Increment the first pointer
                nums[i] = nums[j];  // Place the new unique element in the correct position
            }
        }
        
        return i + 1;  // The number of unique elements
    }
};
