class Solution {
public:
    bool canJump(vector<int>& nums) {
         int n = nums.size();
    if (n == 0 ) return false;  
    if ( n == 1 && nums[0] == 0 ) return true;  
    int jumps = 0;
    int current_end = 0;
    int farthest = 0;
    for (int i = 0; i < n - 1; ++i) {
        farthest = max(farthest, i + nums[i]);
        if (i == current_end) {
            jumps++;
            current_end = farthest;
            if (current_end >= n - 1) break;  
        }
    }  
    return (current_end >= n - 1) ? true  : false;
    }
};