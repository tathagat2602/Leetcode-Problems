class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0; // If the height array is empty, no water can be trapped
        
        int left = 0;                   // Left pointer
        int right = height.size() - 1;  // Right pointer
        int leftMax = 0;                // Maximum height from the left
        int rightMax = 0;               // Maximum height from the right
        int waterTrapped = 0;           // Total water trapped
        
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];  // Update leftMax if current height is greater
                } else {
                    waterTrapped += leftMax - height[left];  // Water trapped at current position
                }
                left++;  // Move the left pointer to the right
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];  // Update rightMax if current height is greater
                } else {
                    waterTrapped += rightMax - height[right];  // Water trapped at current position
                }
                right--;  // Move the right pointer to the left
            }
        }
        
        return waterTrapped;  // Return the total water trapped
    }
};
