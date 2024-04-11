#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>
#include <set>
using namespace std;
//kattis Maximum Flow


long long INF = 1e18;

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};  

struct edge {
    int from, to;
    long long cap, flow;
    bool forward;
    edge(int from, int to, long long cap, long long flow, bool forward) : from(from), to(to), cap(cap), flow(flow), forward(forward){}
    edge() {}
    edge(const edge& other) : from(other.from), to(other.to), cap(other.cap), flow(other.flow), forward(other.forward) {}

};

unordered_map<pair<int, int>, edge*, hash_pair> edge_map;


long long find_path(vector<vector<edge>>& G, int s, int t, vector<int>& prev){
    queue<int> q;
    q.push(s);
    vector<bool> visited(G.size(), false);
    visited[s] = true;
    vector<long long> push_flow(G.size(), INF);

    while(!q.empty()){
        // cout << "q.size() = " << q.size() << endl;
        int v = q.front();
        q.pop();
        
        for(auto& e : G[v]){
            if(!visited[e.to] && e.flow < e.cap) {
                visited[e.to] = true;       
                prev[e.to] = v;
                push_flow[e.to] = min(push_flow[v], e.cap - e.flow);
                if(v == t) return push_flow[t];

                q.push(e.to);

            }
        }
    }
    
    // cout << visited[t] << endl;
    // cout << "push_flow[t] = " << push_flow[t] << endl;  
    return visited[t] ? push_flow[t] : -1;
}




// ford fulkerson with bfs -> edmonds karp
int max_flow(vector<vector<edge>>& G, int s, int t){
    
    int max_flow = 0;
    vector<int> prev(G.size(), -1);

    long long pf = find_path(G, s, t, prev);
    while(pf != -1){
        // std::cout << pf << endl;
        // push the flow


        for (int curr = t; curr != s; curr = prev[curr]) {
            int p = prev[curr];
            int c = curr;
            // cout << "prev[" << curr << "] = " << p << endl; 
            if(edge_map.find(make_pair(c, p)) != edge_map.end() && !edge_map[make_pair(c, p)]->forward){
                edge* e = edge_map[make_pair(c, p)];
                e->flow -= pf;
            }
            if(edge_map.find(make_pair(p, c)) != edge_map.end() && edge_map[make_pair(p, c)]->forward){
                edge* e = edge_map[make_pair(p, c)];
                e->flow += pf;
            }
        }
        
        max_flow += pf;
        pf = find_path(G, s, t, prev);
    }
    // for(int i = 0; i < prev.size(); i++){
    //     std::cout << "prev[" << i << "] = " << prev[i] << endl; 
    // }
    return max_flow;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<edge>> G(n);
    edge_map.reserve(200000);  

    for(int i = 0; i < m; i++){
        int u, v;
        long long c;
        cin >> u >> v >> c;
        edge f(u, v, c, 0, true);
        G[u].push_back(f);


    }
    
    for(int i = 0; i < n; i++){
        for(auto& e : G[i]){
            if(edge_map.find(make_pair(e.from, e.to)) == edge_map.end()){
                edge_map.emplace(make_pair(make_pair(e.from, e.to), &e));
            }
        }
    }


    // for( auto& e : edge_map){
    //     if(edge_map.find(make_pair(e.first.second, e.first.first)) == edge_map.end()){
    //         edge b(e.first.second, e.first.second, 0, 0, false);
    //         G[e.first.second].push_back(b);
    //     }
    // }
    // for(int i = 0; i < n; i++){
    //     for(auto& e : G[i]){
    //         if(edge_map.find(make_pair(e.from, e.to)) == edge_map.end()){
    //             edge_map.emplace(make_pair(make_pair(e.from, e.to), &e));
    //         }
    //     }
    // }

    // for(auto& e : edge_map){
    //     cout << e.first.first << " " << e.first.second << " " << e.second->cap << " " << e.second->flow << " " << e.second->forward << endl;
    // }


    int max_f = max_flow(G, s, t);  


    set<int> incl_v; 
    unordered_map<pair<int, int>, long long, hash_pair> flows;
    for(int i = 0; i < n; i++){
        for(auto& e : G[i]){
            if(e.flow > 0){
                flows[make_pair(e.from, e.to)] = e.flow;    
            }
        }
    }      
   
    cout << n << " " << max_f << " " << flows.size() <<  endl;
    for(auto e : flows){
        cout << e.first.first << " " << e.first.second << " " << e.second << endl;
    }

    
    return 0;
}