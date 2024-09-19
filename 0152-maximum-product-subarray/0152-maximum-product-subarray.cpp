class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int curr_max =nums[0];
        int curr_min=nums[0];
        int ans=nums[0];

        for(int i=1; i<n; i++){
             int temp_max = curr_max;
            curr_max =max(nums[i], max(curr_max * nums[i], curr_min * nums[i]));
             curr_min =min(nums[i], min(curr_min * nums[i], temp_max * nums[i]));
             ans=max(curr_max , ans);
        }

        return ans;

        
    }
};