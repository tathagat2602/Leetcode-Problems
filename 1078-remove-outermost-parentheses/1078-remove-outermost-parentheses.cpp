class Solution {
public:
    string removeOuterParentheses(string s) {  // Opening of the function
        string result = "";  // Initialize an empty result string
        int depth = 0;  // Initialize depth to track parentheses nesting
        
        for (char c : s) {  // Loop through each character in the string
            if (c == '(') {  // If the character is an opening parenthesis
                if (depth > 0) {  // If depth is greater than 0, it's not outermost
                    result += c;  // Add the character to the result
                }
                depth++;  // Increase depth
            } else {  // If the character is a closing parenthesis
                depth--;  // Decrease depth
                if (depth > 0) {  // If depth is greater than 0, it's not outermost
                    result += c;  // Add the character to the result
                }
            }
        }  // End of the loop
        
        return result;  // Return the final result string
    }  // Closing of the function
};  // End of the class
