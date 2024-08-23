#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Sets to keep track of seen numbers in rows, columns, and sub-boxes
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                char num = board[r][c];
                if (num == '.') {
                    continue; // Skip empty cells
                }
                
                // Check for rows
                if (rows[r].find(num) != rows[r].end()) {
                    return false; // Number already seen in the row
                }
                rows[r].insert(num);

                // Check for columns
                if (cols[c].find(num) != cols[c].end()) {
                    return false; // Number already seen in the column
                }
                cols[c].insert(num);

                // Check for 3x3 sub-boxes
                int boxIndex = (r / 3) * 3 + (c / 3);
                if (boxes[boxIndex].find(num) != boxes[boxIndex].end()) {
                    return false; // Number already seen in the 3x3 box
                }
                boxes[boxIndex].insert(num);
            }
        }
        return true; // All checks passed
    }
};
