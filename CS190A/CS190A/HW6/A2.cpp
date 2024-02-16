#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>
#include <set>
using namespace std;



// struct hash_pair {
//     template <class T1, class T2>
//     size_t operator()(const pair<T1, T2>& p) const {
//         auto hash1 = hash<T1>{}(p.first);
//         auto hash2 = hash<T2>{}(p.second);
//         return hash1 ^ hash2;
//     }
// };  


// struct edge {
//     int from, to;
//     long long cap, flow;
//     bool forward;
//     edge(int from, int to, long long cap, long long flow, bool forward) : from(from), to(to), cap(cap), flow(flow), forward(forward){}
//     edge() {}
//     edge(const edge& other) : from(other.from), to(other.to), cap(other.cap), flow(other.flow), forward(other.forward) {}

// };
// unordered_map<pair<int, int>, edge*, hash_pair> edge_map;

// pseudocode/brainstoriming 

// make a residual graph
// given G, c, s, t, f
// edges of R: 
// uv if f(u, v) < c(u, v) OR vu if f(u, v) > 0 


// ford fulkerson (G, c, s, t)
// f = 0 for all edges
// while(exists and augmenting path P (path from s to t in Residual graph R)):  
//      push max flow through P to f (f = f + f(P))
// return f

// can find the augmenting path using BFS on R from s to t

// tips from lecture notes
// represent G, c, f as adjacency lists <vector<vector<edge>>>
// rather than building R again and again, merge the representation of R and G



bool find_path(vector<vector<int>>& G, vector<vector<int>>& cap, vector<vector<int>>& flow, int s, int t, vector<int>& prev){
    vector<bool> visited(G.size(), false);

    queue<int> q;
    q.push(s);

    prev[s] = -1;
    visited[s] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : G[u]){
            if(!visited[v] && cap[u][v] > 0){
                q.push(v);
                prev[v] = u;
                visited[v] = true;
                if (v == t) return true;
            }
        }
    }
	return false;
}


int max_flow(vector<vector<int>>& G, vector<vector<int>>& cap, vector<vector<int>>& flow, int s, int t){
    vector<int> prev(G.size(), -1);
    int max_f = 0;
    while(find_path(G, cap, flow, s, t, prev)){
        int path_f = INT_MAX;
        for(int v = t; v != s; v = prev[v]){
            int u = prev[v];
            path_f = min(path_f, cap[u][v]);
        }
        for(int v = t; v != s; v = prev[v]){
            int u = prev[v];
                // pushing the flow
            // decrease flow along reverse edge
            // decrease cap of forward edge
            // increase flow along forward edge
            // increase cap of backward edge
            cap[u][v] -= path_f;
            cap[v][u] += path_f;
            flow[u][v] += path_f;
            flow[v][u] -= path_f;

            // for (int curr = t; curr != s; curr = prev[curr]) {
            //     int p = prev[curr];
            //     int c = curr;
            //     // cout << "prev[" << curr << "] = " << p << endl; 
            //     if(edge_map.find(make_pair(c, p)) != edge_map.end() && !edge_map[make_pair(c, p)]->forward){
            //         edge* e = edge_map[make_pair(c, p)];
            //         e->flow -= pf;
            //     }
            //     if(edge_map.find(make_pair(p, c)) != edge_map.end() && edge_map[make_pair(p, c)]->forward){
            //         edge* e = edge_map[make_pair(p, c)];
            //         e->flow += pf;
            //     }
            // }
        }
        max_f += path_f;
    }
    return max_f;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    // vector<vector<edge>> G(n);
    // edge_map.reserve(200000);  


    vector<vector<int>> G(n);
    vector<vector<int>> cap(n, vector<int>(n, 0));
    vector<vector<int>> flow(n, vector<int>(n, 0));
    
    for(int i = 0; i < m; i++){
        int u, v;
        int c;
        cin >> u >> v >> c;
        G[u].push_back(v);
        G[v].push_back(u);
        cap[u][v] = c;

    }

    set<pair<int, int>> flows;
    int max_f = max_flow(G, cap, flow, s, t);  
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(flow[i][j] > 0){
                flows.insert(make_pair(i, j));
            }   
        }
    }


   
    cout << n << " " << max_f << " " << flows.size() <<  endl;
    for(auto e : flows){
        cout << e.first << " " << e.second << " " << flow[e.first][e.second] << endl;
    }

    
    return 0;
}