class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int  col = matrix[0].size();
        int startingRow = 0 , startingCol = 0 ;
        int endRow = row - 1 , endCol = col-1;
        int count = 0 ;
        int total = row * col ;
        vector<int> temp;
    while(count < total){
        //starting row
        for(int i = startingCol ; count < total && i <= endCol ; i ++ ){
                temp.push_back(matrix[startingRow][i]);
                count ++;
        }
        startingRow++;
        
        //endingcol
        for(int i = startingRow ; count < total && i <= endRow ; i++){
            temp.push_back(matrix[i][endCol]);
            count++;
        }
        endCol--;

        //endrow
        for(int i = endCol ;  count < total && i >= startingCol ; i--){
            temp.push_back(matrix[endRow][i]);
            count ++;
        }
        endRow--;
         //firstcol

         for(int i = endRow;  count < total && i >= startingRow; i--){
            temp.push_back(matrix[i][startingCol]);
            count++;
         }
         startingCol++;
    }


    return temp;
    }
};