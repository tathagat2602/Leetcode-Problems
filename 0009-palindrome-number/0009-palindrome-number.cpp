class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes
        if (x < 0) return false;
        
        // Store the original number
        int original = x;
        int reversed = 0;
        
        // Reverse the number
        while (x != 0) {
            int digit = x % 10;
            // Check for overflow/underflow
            if (reversed > (INT_MAX - digit) / 10) return false;
            reversed = reversed * 10 + digit;
            x /= 10;
        }
        
        // Check if the original number is the same as the reversed number
        return original == reversed;
    }
};
