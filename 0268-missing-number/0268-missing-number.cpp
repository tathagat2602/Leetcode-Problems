class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size();
        int expectedSum = n*(n+1)/2;
        int actualsum=0;

        for(int i=0; i<n; i++){
            actualsum= actualsum+ nums[i];
            
        }
        return expectedSum - actualsum;
        
    }
};