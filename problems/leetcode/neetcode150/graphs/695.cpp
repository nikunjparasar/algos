#include "include.h"
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    ans = max(ans, area(grid, visited, i, j));
                }
            }
        }
        return ans;
    }


    int area(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j){
        int area = 0;
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;
        while(!q.empty()){
            pair<int, int> thing = q.front();
            q.pop();
            int x = thing.first;
            int y = thing.second;
            area++;
            if(isValid(x+1, y, grid) && grid[x+1][y] == 1 && !visited[x+1][y]) {
                visited[x+1][y] = true; 
                q.push({x+1, y});
            }
            if(isValid(x, y+1, grid) && grid[x][y+1] == 1 && !visited[x][y+1]) {
                visited[x][y+1] = true; 
                q.push({x, y+1});
            }
            if(isValid(x-1, y, grid) && grid[x-1][y] == 1 && !visited[x-1][y]){
                visited[x-1][y] = true; 
                q.push({x-1, y});
            } 
            if(isValid(x, y-1, grid) && grid[x][y-1] == 1 && !visited[x][y-1]){
                visited[x][y-1] = true; 
                q.push({x, y-1});
            } 
        }
        return area;
    }

    bool isValid(int x, int y, vector<vector<int>>& grid){ 
        return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size();
    }
};