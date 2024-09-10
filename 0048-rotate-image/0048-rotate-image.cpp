class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows= matrix.size();
        int cols= matrix[0].size();

        //transpose of a matrix
        for(int i=0; i<rows; i++){
            for(int j=0; j<=i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //reverse each row to obtain the rotated (90 degree) image
        for(int i=0; i<rows; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
        
    }
};