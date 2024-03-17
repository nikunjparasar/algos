#include <iostream>

using namespace std;

unordered_map<int, vector<int>> G;
vector<int> explored, cycle, topo, n_routes;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }
    // find number of routes from city 1 to 2


    return 0;
}