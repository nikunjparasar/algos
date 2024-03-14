#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
using namespace std;


struct person{
    string name, f2;
    int i;
    person(string name, string f2, int i): name(name), f2(f2), i(i){}
};
struct comp {
    bool operator()(const person& a, const person& b){
        if(a.f2 == b.f2) return a.i > b.i;
        return a.f2 > b.f2;
    }
};



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    stringstream ss;
    while(n != 0){
        priority_queue<person, vector<person>, comp> pq;
        for(int i = 0; i < n; i++){
            string s; cin >> s;
            string f2 = s.substr(0, 2);
            pq.push(person(s, f2, i));
        }
        for(int i = 0; i < n; i++){
            ss << pq.top().name << endl;
            pq.pop();
        }
        ss << endl;
        cin >> n;
    }
    cout << ss.str();   
    return 0;
}