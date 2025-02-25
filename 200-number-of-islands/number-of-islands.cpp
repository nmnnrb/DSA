class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int isIsLand = 0;
        vector<vector<int>> direct = {{-1,0} , {1,0}, {0,-1} , {0,1}};
        queue<pair<int,int>> q;
        int row = grid.size();
        int col = grid[0].size();
        for(int i = 0; i< row; i++){
            for(int j = 0; j< col;j++){
                if(grid[i][j] == '1'){
                    isIsLand++;
                    q.push({i,j});

                    while(!q.empty()){
                        auto [r,c] = q.front();
                        q.pop();
                        grid[i][j] = '0';

                        for(auto &dd:direct ){
                            int newRow = r + dd[0] , newCol = c + dd[1];
                            if(newRow >=0 && newRow < row && newCol >=0 && newCol < col && grid[newRow][newCol] == '1'){
                                grid[newRow][newCol] = '0';
                                q.push({newRow, newCol});
                            }
                        }
                    }
                }
            }
        }
        return isIsLand;
    }
};