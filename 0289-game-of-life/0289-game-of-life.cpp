

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty() || board[0].empty()) return;
        
        int rows = board.size();
        int cols = board[0].size();
        
        // Directions array for the 8 possible neighbors
        vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        
        // Copy of the original board
        vector<vector<int>> copyBoard = board;
        
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // Count live neighbors
                int liveNeighbors = 0;
                for (auto direction : directions) {
                    int nr = r + direction.first;
                    int nc = c + direction.second;
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && copyBoard[nr][nc] == 1) {
                        liveNeighbors++;
                    }
                }
                
                // Apply the rules
                if (copyBoard[r][c] == 1) {  // Cell is currently live
                    if (liveNeighbors < 2 || liveNeighbors > 3) {
                        board[r][c] = 0;  // Cell dies
                    }
                } else {  // Cell is currently dead
                    if (liveNeighbors == 3) {
                        board[r][c] = 1;  // Cell becomes live
                    }
                }
            }
        }
    }
};
