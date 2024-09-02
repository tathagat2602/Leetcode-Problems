class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int max_sum=nums[0];
        int curr_sum=nums[0];
        for(int i=1;i<n; i++){
            curr_sum=max(nums[i],(nums[i]+curr_sum));
            max_sum=max(curr_sum, max_sum);
        }

        return max_sum;
        
    }
};