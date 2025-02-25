class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //    int st = 0, end = matrix.size() * matrix[0].size() -1;

    //    while(st <= end){
    //     int mid = st + (end-st) /2;
    //     int ele = matrix[mid/matrix[0].size()][mid%matrix[0].size()];

    //     if(ele == target){
    //         return true;
    //     }else if(ele > target){
    //         end = mid -1;
    //     }else{
    //         st = mid+1;
    //     }
    //    }
    //     return false;

    int i = 0, j = matrix[0].size() -1;
    while(i < matrix.size() && j >=0){
       
        if(matrix[i][j] == target){
            return true;
        }else if(matrix[i][j] > target){
            j--;
        }else{
            i++;
        }
    }
    return false;
    }
};