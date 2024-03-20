class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int rowIndex = 0;
        int colindex = col - 1;
        while (rowIndex < row && colindex >=0){
            int element = matrix[rowIndex][colindex];
            if(target == element){
                return true;
            }else if(target > element){
                rowIndex++;
            }else{
                colindex--;
            }
        }
        return false;
    }
};