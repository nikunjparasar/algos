#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;

// kattis faulty robot

void dfs(vector<vector<int>>& graph, unordered_map<int, int>& forced, vector<bool>& visited, set<int>& resting_pos, int curr, bool faulty_path){
    if(visited[curr]) return;
    visited[curr] = true;

    if(forced.find(curr) != forced.end()) dfs(graph, forced, visited, resting_pos, forced[curr], faulty_path);
    else resting_pos.insert(curr);
    if(!faulty_path) for(int neighbor : graph[curr]) dfs(graph, forced, visited, resting_pos, neighbor, true);
    visited[curr] = false;
}


int main(){
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1);
    unordered_map<int, int> forced; // max size of 900
    vector<bool> visited(n+1, false);
    set<int> resting_pos;

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        if(u < 0) forced[-u] = v; 
        else graph[u].push_back(v);
        
    }
    
    dfs(graph, forced, visited, resting_pos, 1, false);
    // for(auto e : resting_pos) cout << e << " ";
    cout << resting_pos.size() << endl;

    return 0;
}