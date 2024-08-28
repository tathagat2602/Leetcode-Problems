class Solution {
public:
    int reverse(int x) {
        int revN = 0;
        
        while(x != 0){
            int ld = x % 10;
            // Check for overflow
            if (revN > INT_MAX/10 || (revN == INT_MAX / 10 && ld > 7)) return 0;
            if (revN < INT_MIN/10 || (revN == INT_MIN / 10 && ld < -8)) return 0;
            revN = revN * 10 + ld;
            x = x / 10;
        }
        
        return revN;
    }
};
