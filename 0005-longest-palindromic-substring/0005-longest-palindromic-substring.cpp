class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        string longest = "";
        for (int i = 0; i < s.size(); ++i) {
            // Check for the longest odd-length palindrome
            string odd = expandAroundCenter(s, i, i);
            if (odd.size() > longest.size()) {
                longest = odd;
            }

            // Check for the longest even-length palindrome
            string even = expandAroundCenter(s, i, i + 1);
            if (even.size() > longest.size()) {
                longest = even;
            }
        }
        
        return longest;
    }

private:
    string expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return s.substr(left + 1, right - left - 1);
    }
};
