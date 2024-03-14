#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
void dfs(vector<vector<char> >& grid, vector<vector<bool> >& visited, int i, int j){
    if(!inBounds(i, j, grid) || visited[i][j] || grid[i][j] == 'W') return;
    visited[i][j] = true;
    dfs(grid, visited, i+1, j);
    dfs(grid, visited, i-1, j);
    dfs(grid, visited, i, j+1);
    dfs(grid, visited, i, j-1);
}

bool inBounds(int i, int j, vector<vector<char> >& grid){
    return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
}

public:
void solve(){
    int m, n;
    cin >> m >> n;
    vector<vector<char> > satellite_grid(m, vector<char>(n));
    vector<vector<bool> > visited(m, vector<bool>(n, false));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> satellite_grid[i][j];
        }
    }
    int min_islands = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j] && (satellite_grid[i][j] == 'L')){
                dfs(satellite_grid, visited, i, j);
                min_islands++;
            }
        }
    }

    cout << min_islands << endl;
}

};

int main(){
    ios_base::sync_with_stdio(false);
    Solution s;
    s.solve();
    return 0;
}