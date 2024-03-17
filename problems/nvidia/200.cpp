#include "include.h"
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    dfs(grid, visited, i, j);
                    count++;
                }
            }
        }
        return count;
    }
private:
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j){
        grid[i][j] = '0';
        for(int z = 0; z < 4; z++){
            int new_i = i + dx[z];
            int new_j = j + dy[z];
            if(new_i >= 0 && new_i < grid.size() && 
                new_j >= 0 && new_j < grid[0].size() && 
                grid[new_i][new_j] == '1' && !visited[new_i][new_j]){
                    visited[i][j] = true;
                    dfs(grid, visited, new_i, new_j);
            }
        }
    }
};