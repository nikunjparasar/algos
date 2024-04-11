#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;

//kattis texas summers
vector<int> dijkstra(const vector<vector<pair<int, int>>>& graph, int source) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    vector<int> prev(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    return prev;

}


struct point{
    int x, y;
    point(int x, int y) : x(x), y(y) {}
    point() : x(-1), y(-1) {}
}; 

int sweat(point a, point b) {return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y); }


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<point> shade(n+2);
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        shade[i] = point(x, y);
    }
    const int DORM_INDEX = n;
    const int SCHOOL_INDEX = n+1;
    point dorm(-1, -1);
    cin >> dorm.x >> dorm.y;
    point school(-1, -1);
    cin >> school.x >> school.y;
    shade[DORM_INDEX] = dorm;
    shade[SCHOOL_INDEX] = school;

    vector<vector<pair<int, int>>> graph(n+2);
    for (int i = 0; i < n+2; i++) {
        for (int j = i + 1; j < n+2; j++) {
            int sweatValue = sweat(shade[i], shade[j]);
            graph[i].push_back({j, sweatValue});
            graph[j].push_back({i, sweatValue});
        }
    }
    vector<int> ans = dijkstra(graph, DORM_INDEX);
    stack<int> directions;

    int next = ans[SCHOOL_INDEX];
    while (next != -1) {
        directions.push(next);
        next = ans[next];
    }
    if(directions.size() == 1){
        cout << "-" << endl;
        return 0;
    }
    while(!directions.empty()){
        cout << directions.top() << endl;
        directions.pop();
    }
    

    return 0;
}