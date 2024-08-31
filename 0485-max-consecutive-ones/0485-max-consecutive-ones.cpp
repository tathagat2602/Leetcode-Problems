class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int currCount=0;
        int maxCount=0;
        for(int i=0; i<n; i++){
            if(nums[i]==1){
                currCount++;
                maxCount= max(currCount, maxCount);
            }
            else{
                currCount=0;
            }
        }

        return maxCount;
        
    }
};