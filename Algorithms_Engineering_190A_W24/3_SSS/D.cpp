// #include <iostream>
// #include <vector>
// #include <set>
// #include <queue>
// #include <algorithm>
// #include <unordered_map>
// #include <iomanip>
// #include <climits>
// using namespace std;
//kattis speedy escape

// // dijkstra algorithm
// vector<vector<int>> dijkstra(const vector<vector<pair<int, int>>>& graph, int source) {
//     int n = graph.size();
//     vector<int> dist(n, INT_MAX);
//     vector<int> prev(n, -1);
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

//     dist[source] = 0;
//     pq.push({0, source});

//     while (!pq.empty()) {
//         int u = pq.top().second;
//         pq.pop();

//         for (const auto& edge : graph[u]) {
//             int v = edge.first;
//             int weight = edge.second;

//             if (dist[u] + weight < dist[v]) {
//                 dist[v] = dist[u] + weight;
//                 prev[v] = u;
//                 pq.push({dist[v], v});
//             }
//         }
//     }
//     return {dist, prev};

// }


// int main(){
//     ios_base::sync_with_stdio(false);
    
//     int n, m, e;
//     cin >> n >> m >> e;
    
//     vector<vector<pair<int, int>>> graph(n+1);

//     for(int i = 0; i < m; i++){
//         int a, b, l;
//         cin >> a >> b >> l;
//         graph[a].push_back({b, l});
//         graph[b].push_back({a, l});
//     }
    
//     unordered_map<int, int> exits_b;
//     unordered_map<int, int> exits_p; // exits, length to exit
    
//     for(int i = 0; i < e; i++){
//         int z;
//         cin >> z;
//         exits_p[z] = 0;
//         exits_b[z] = 0;
//     }
    
//     int b, p;
//     cin >> b >> p;
    
//     vector<vector<int>> paths_b = dijkstra(graph, b);
//     vector<vector<int>> paths_p = dijkstra(graph, p);

//     int min_path_p = INT_MAX;
//     int min_path_b = INT_MAX;

//     for(auto e = exits_b.begin(); e != exits_b.end(); e++){
//         exits_b[e->first] = paths_b[0][e->first];
//         min_path_b = min(min_path_b, paths_b[0][e->first]);
//         exits_p[e->first] = paths_p[0][e->first];        
//         min_path_p = min(min_path_p, paths_p[0][e->first]);
//     }

//     double dist_p = min_path_p; 
//     double dist_b = min_path_b;
//     double time_p = dist_p*100 / 160000.0;
//     double speed_b = dist_b*0.1 / time_p;

//     // cout << p << " " << dist_p << endl;    
//     // if(dist_b > dist_p) cout << "IMPOSSIBLE" << endl;
//     cout << fixed << setprecision(10) << speed_b << endl;

//     return 0;
// }