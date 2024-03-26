#include "include.h"
class Solution {
private:

    bool isValid(vector<vector<char>>& grid, vector<vector<bool>>& visited,  int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return false;
        else return (grid[i][j] == '1') && !visited[i][j];
    }

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j){
        visited[i][j] = true;
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        for(int d = 0; d < 4; d++){
            if(isValid(grid, visited, i+dx[d], j+dy[d])){
                dfs(grid, visited, i+dx[d], j+dy[d]);
            }
        }
        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    dfs(grid, visited, i, j);
                    count++;
                }
            }
        }
        return count;
    }

};