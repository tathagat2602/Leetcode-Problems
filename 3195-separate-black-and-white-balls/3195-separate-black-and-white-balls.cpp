class Solution {
public:
    long long minimumSteps(std::string s) {
        long long ans = 0;  // Change to long long
        int zero_cnt = 0;

        // Traverse the string in reverse
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '0') {
                zero_cnt++;  // Count zeros
            } else if (s[i] == '1') {
                ans += zero_cnt;  // Add to ans the count of zeros encountered
            }
        }

        return ans;  // Return the final count
    }
};