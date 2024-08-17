class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;
        
        // Iterate through the array
        for (int i = 0; i < n; i++) {
            // If the current index is greater than the furthest reachable position, return false
            if (i > farthest) return false;
            
            // Update the furthest position we can reach
            farthest = max(farthest, i + nums[i]);
            
            // If the furthest position we can reach is beyond or at the last index, return true
            if (farthest >= n - 1) return true;
        }
        
        return false;
    }
};
