class Solution {
    int dp[1001][1001];
public:
    Solution (){
        memset(dp, -1, sizeof(dp));
    }
    int longestCommonSubsequence(string &A, string &B, int i = 0, int j = 0) {
        /*
        if(i == A.size() || j == B.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int val = 0;
        if(A[i] == B[j]){
            val = 1 + longestCommonSubsequence(A, B, i+1, j+1);
        }else{
            val = max(longestCommonSubsequence(A, B, i+1, j), longestCommonSubsequence(A, B, i, j+1));
        }
        return dp[i][j] = val;
        */

        int n = A.size(), m = B.size();

        /*
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        for(int i = 0; i <= m; i++) dp[0][i] = 0;
        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int val = 0;
                if(A[i-1] == B[j-1]){
                    val = 1 + dp[i-1][j-1];
                }else{
                    val = max(dp[i-1][j], dp[i][j-1]);
                }
                dp[i][j] = val;
            }
        }
        return dp[n][m];
        */

        vector<int> dp(m+1, 0);
        for(int i = 1; i <= n; i++){
            vector<int> curr(m+1, 0);
            for(int j = 1; j <= m; j++){
                int val = 0;
                if(A[i-1] == B[j-1]){
                    val = 1+dp[j-1];
                }else{
                    val = max(dp[j], curr[j-1]);
                }
                curr[j] = val;
            }
            dp = curr;
        }
        return dp[m];
    }
};