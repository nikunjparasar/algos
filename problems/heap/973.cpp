#include "include.h"
using namespace std;

class Solution {
public:

    //O(Nlogk) time
    //O(k) space
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        size_t n = points.size();
        vector<vector<int>> max_heap;
        make_heap(max_heap.begin(), max_heap.end(), Comp{});
        for(int i = 0; i < n; i++){
            max_heap.push_back(points[i]);
            push_heap(max_heap.begin(), max_heap.end(), Comp{});
            if(max_heap.size() > k){
                pop_heap(max_heap.begin(), max_heap.end(), Comp{});
                max_heap.pop_back();
            } 
        }
        return max_heap;
    }

    class Comp {
    public:
        bool operator() (vector<int> a, vector<int> b){
            double dist_a = sqrt((a[0]*a[0]) + (a[1]*a[1]));
            double dist_b = sqrt((b[0]*b[0]) + (b[1]*b[1]));
            return dist_a < dist_b;
        }
    };
};