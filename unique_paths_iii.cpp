// https://leetcode.com/problems/unique-paths-iii/

class Solution {
public:
    bool isSafe(int x, int y, int row, int col) {
        if(x >= 0 && x < row && y >= 0 && y < col){
            return true;
        }
        return false;
    }
    
    bool isAllVisited(vector<vector<int>> grid, int row, int col) {
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(grid[i][j] == 0){
                    return false;
                }
            }
        }
        return true;
    }
    
    void printGraph(vector<vector<int>> grid, int row, int col) {
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    void dfs(vector<vector<int>> grid, int row, int col, int x, int y, int &count) {
        grid[x][y] = -1;
        int row_index[4] = {-1, 0, 1, 0};
        int col_index[4] = {0, -1, 0, 1};
        
        // printGraph(grid, row, col);
        
        for(int i=0;i<4;i++){
            int _x = x + row_index[i];
            int _y = y + col_index[i];
            if(isSafe(_x, _y, row, col)) {
                if(grid[_x][_y] == 0) {
                    dfs(grid, row, col, _x, _y, count);
                } else if(grid[_x][_y] == 2) {
                    // printGraph(grid, row, col);
                    // cout<<endl;
                    if(isAllVisited(grid, row, col)) {
                        // cout<<"Valid 2 Found"<<endl;
                        count++;
                    }
                }
            }
        }
    }
    
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        int i_start=0, j_start=0;
        for(i_start=0; i_start<row; i_start++) {
            bool found_1 = false;
            for(j_start=0;j_start<col ;j_start++) {
                if(grid[i_start][j_start] == 1) {
                    found_1 = true;
                    break;
                }
            }
            if(found_1) {
                break;
            }
        }
        int count = 0;
        dfs(grid, row, col, i_start, j_start, count);
        
        return count;
    }
};