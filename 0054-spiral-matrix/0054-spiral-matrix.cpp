class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      vector<int>ans;
      int rows=matrix.size();
      int cols=matrix[0].size();
      int top=0 , left=0, right=cols-1, bottom=rows-1;

      while(top<=bottom && left<=right){

        for(int i=left; i<=right; i++){         //left to right
            ans.push_back(matrix[top][i]);
            

        }
        top++;

        for(int i=top; i<=bottom; i++){
            ans.push_back(matrix[i][right]);  //top to bottom
            
        }
        right--;
        if(top<=bottom){
        for(int i=right; i>=left; i--){
            ans.push_back(matrix[bottom][i]);   //right to left
            
        }
        bottom--;
        }

        if(left<=right){
        for(int i=bottom; i>=top; i--){      //bottom to top
            ans.push_back(matrix[i][left]);
            
        }
        left++;
        }

      }

      return ans;

        
    }
};