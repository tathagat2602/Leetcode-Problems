
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int left = 0;                // Start pointer at the beginning
        int right = height.size() - 1; // Start pointer at the end

        while (left < right) {
            // Calculate the width between the two pointers
            int width = right - left;

            // Calculate the area with the current pair of lines
            int current_area = min(height[left], height[right]) * width;

            // Update the maximum area found so far
            max_area = max(max_area, current_area);

            // Move the pointer that points to the shorter line inward
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_area;
    }
};
