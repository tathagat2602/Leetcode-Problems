class Solution {
public:
    int uniquePaths(int m, int n) {
        // Initialize a 2D vector dp with m rows and n columns, all set to 1
        vector<vector<int>> dp(m, vector<int>(n, 1));
 //dp problem 2nd
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];

                // dp[1][1]=1+1 
                //dp[2][1]=dp[1][1]+dp[2][1]
            }
        }

        // The bottom-right corner will have the number of unique paths
        return dp[m-1][n-1];
    }
};