class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> currentCombination;
        sort(candidates.begin(), candidates.end());  // Step 1
        backtrack(candidates, target, 0, currentCombination, result);
        return result;
    }
    
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& currentCombination, vector<vector<int>>& result) {
        if (target == 0) {  // Step 4
            result.push_back(currentCombination);
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;  // Step 3
            
            if (candidates[i] > target) break;  // Step 5
            
            currentCombination.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, currentCombination, result);
            currentCombination.pop_back();  // Backtrack
        }
    }
};
