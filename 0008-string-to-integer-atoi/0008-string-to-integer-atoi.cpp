
class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        
        // Step 1: Ignore leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // Step 2: Handle optional sign
        int sign = 1;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }
        
        // Step 3: Convert characters to integer
        long long result = 0; // Use long long to avoid overflow issues
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            i++;
            
            // Step 4: Clamp result to 32-bit signed integer range
            if (sign == 1 && result > INT_MAX) {
                return INT_MAX;
            } else if (sign == -1 && -result < INT_MIN) {
                return INT_MIN;
            }
        }
        
        return sign * result;
    }
};
