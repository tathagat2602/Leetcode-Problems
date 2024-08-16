class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Step 1: Initialize Tortoise and Hare
        int tortoise = nums[0];
        int hare = nums[0];

        // Step 2: Move tortoise one step and hare two steps until they meet
        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);

        // Step 3: Find the entrance to the cycle (duplicate number)
        tortoise = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }

        // Step 4: Return the duplicate number
        return hare;
    }
};
