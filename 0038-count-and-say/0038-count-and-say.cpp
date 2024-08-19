class Solution {
public:
    string countAndSay(int n) {
        // Base case
        if (n == 1) return "1";
        
        // Start with the first element
        string result = "1";
        
        // Iterate from 2 to n to build the sequence
        for (int i = 2; i <= n; ++i) {
            string current = "";
            int count = 1;
            
            // Process the previous result string (result)
            for (int j = 1; j < result.size(); ++j) {
                // If the current character is the same as the previous one, increase the count
                if (result[j] == result[j - 1]) {
                    count++;
                } else {
                    // Append the count and the character to the current string
                    current += to_string(count) + result[j - 1];
                    // Reset count for the new character
                    count = 1;
                }
            }
            // Append the last group
            current += to_string(count) + result.back();
            // Update result for the next iteration
            result = current;
        }
        
        return result;
    }
};
