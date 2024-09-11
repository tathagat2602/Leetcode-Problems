class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        // Add 0 and n as boundaries for the stick
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        int m = cuts.size();
        // dp[i][j] will store the minimum cost to cut between cuts[i] and cuts[j]
        vector<vector<int>> dp(m, vector<int>(m, 0));
        
        // Fill dp table by increasing size of the interval
        for (int length = 2; length < m; length++) { // length of the subproblem
            for (int i = 0; i < m - length; i++) {
                int j = i + length;
                dp[i][j] = INT_MAX;
                // Try making cuts at all positions between i and j
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);
                }
            }
        }
        
        // The answer is the minimum cost to cut between the full stick (from 0 to n)
        return dp[0][m-1];
    }
};
