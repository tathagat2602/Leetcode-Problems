struct cell{
    int row, col;
};

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size()-1, pr, pc, r, c;
        if(grid[0][0] == 1 || grid[n][n] == 1) return -1;
        if(grid.size() == 1) return 1;

        queue<cell> q(deque<cell> {{0,0}});
        vector<vector<int>> diff = {{0,-1}, {-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}};

        for(int level=2, size=1; !q.empty(); level++, size=q.size())
        {
            while(size--)
            {
                pr = q.front().row, pc = q.front().col; q.pop();
                for(auto &d: diff)
                {
                    r = pr+d[0], c = pc+d[1];
                    if(r<0 || r>n || c<0 || c>n || grid[r][c]!=0)
                        continue;
                    if(r==n && c==n) return level;
                    grid[r][c] = 2;
                    q.push({r,c});
                }
            }
        }

        return -1;
    }
};