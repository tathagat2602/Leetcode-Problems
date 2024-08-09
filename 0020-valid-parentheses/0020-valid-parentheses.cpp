class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                // Push open brackets onto the stack
                stack.push(c);
            } else {
                // If the stack is empty or the top of the stack doesn't match the closing bracket
                if (stack.empty() || 
                    (c == ')' && stack.top() != '(') ||
                    (c == '}' && stack.top() != '{') ||
                    (c == ']' && stack.top() != '[')) {
                    return false;
                }
                // Pop the matched open bracket from the stack
                stack.pop();
            }
        }
        
        // If the stack is empty, all brackets were properly matched
        return stack.empty();
    }
};
