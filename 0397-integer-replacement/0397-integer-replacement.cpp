class Solution {
private:
    unordered_map<long, long> memo;
    int solve(long n){
        if(memo.find(n) != memo.end())
            return memo[n];

        if(n == 1)
            return 0;

        if(!(n%2))
            return memo[n] = 1 + solve(n/2);
        
        return memo[n] = min(1 + solve(n-1), 1+solve(n+1));
    }
public:
    int integerReplacement(int n) {
        return solve(n);
    }
};