class Solution {
public:
    string convert(string s, int numRows) {
        // If the number of rows is 1 or greater than the length of the string, no zigzag is needed
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        // Create a vector of strings to represent each row
        vector<string> rows(min(numRows, int(s.length())));
        
        int currRow = 0; // Keep track of the current row
        bool goingDown = false; // Track whether we're going down or up the zigzag

        // Iterate over the characters in the string
        for (char c : s) {
            rows[currRow] += c; // Append character to the current row
            // If we are at the top or bottom, reverse the direction
            if (currRow == 0 || currRow == numRows - 1) {
                goingDown = !goingDown;
            }
            // Move up or down depending on the direction
            currRow += goingDown ? 1 : -1;
        }

        // Combine all rows into one string
        string result;
        for (string row : rows) {
            result += row;
        }

        return result;
    }
};
