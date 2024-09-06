class Solution {
public:
    bool rotateString(string s, string goal) {
        // Check if lengths are the same, otherwise return false
        if (s.length() != goal.length()) {
            return false;
        }
        
        // If the strings are already equal, return true
        if (s == goal) {
            return true;
        }

        int n = s.length();
        
        // Try all possible rotations using the three-reversal method
        for (int k = 1; k < n; ++k) {
            string temp=s;
            

            // Reverse the entire string
            reverse(temp.begin(), temp.end());

            // Reverse the first k elements
            reverse(temp.begin(), temp.begin() + k);

            // Reverse the remaining elements
            reverse(temp.begin() + k, temp.end());

            // If this matches the goal, return true
            if (temp == goal) {
                return true;
            }
        }

        // If no rotation matches, return false
        return false;
    }
};
