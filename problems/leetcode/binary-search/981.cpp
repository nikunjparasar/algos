#include "include.h"
using namespace std;

class TimeMap {

private:

    unordered_map<string, vector<pair<int, string>>> m;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(m.find(key) == m.end()) return "";
        int l = 0;
        int r = m[key].size()-1;
        if(m[key][r].first <= timestamp) return m[key][r].second;
        if(m[key][l].first > timestamp) return "";
        // biggest <= timestamp
        string biggest = m[key][l].second;
        while(l <= r){
            int mid = (l+r)/2;
            if(m[key][mid].first == timestamp) return m[key][mid].second;
            else if(m[key][mid].first < timestamp) {
                biggest = m[key][mid].second;
                l = mid+1;
            }
            else r = mid-1;
            
        }
        return biggest;
    
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */