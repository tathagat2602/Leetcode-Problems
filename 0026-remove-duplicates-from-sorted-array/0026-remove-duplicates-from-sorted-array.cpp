class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0;//initialises the pointer to track the position of uniq element
        for(int j=1; j<n; j++){   // Step 3: Start a loop from the second element to the end
            if(nums[i]!=nums[j]){ // Check if the current element is different 
                                  //from the last unique element
                nums[i+1]=nums[j];
                i++;
            }
            
        }
        return i+1;
    }
};