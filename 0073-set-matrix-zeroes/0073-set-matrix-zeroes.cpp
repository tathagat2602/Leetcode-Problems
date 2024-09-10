class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        bool firstrowZero=false, firstcolZero=false;

        //check if the first row has zero
         for (int j = 0; j < cols; j++) {
            if (matrix[0][j] == 0) {
                firstrowZero = true;
                break;
            }
        }
            //check if the first column has zero
         for (int i = 0; i < rows; i++) {
            if (matrix[i][0] == 0) {
                firstcolZero = true;
                break;
            }
        }

        // usimg first row and first column as marker
        for(int j=1; j<cols; j++){
            for(int i=1; i<rows; i++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                
                }
            }
        }

        //set other elements 0 based on te markers
        for(int i=1; i<rows; i++){
            for( int j=1; j<cols; j++){
                if(matrix[0][j]==0||matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }

        //set the first row zero if needed
        if(firstrowZero){
            for(int j=0; j<cols; j++){
                matrix[0][j]=0;
            }
        }

        //set the first column zero if needed
        if(firstcolZero){
            for(int i=0; i<rows; i++){
                matrix[i][0]=0;
            }
        }


        
    }
};