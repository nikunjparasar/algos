#include "include.h"
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            counter[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, ComparatorSpecial> max_heap;
        for(auto e : counter){
            max_heap.push({e.first, e.second});
        }
        for(int i = 0; i < k ; i++){
            ans.push_back(max_heap.top().first);
            max_heap.pop();
        }
        return ans;
    }

    struct ComparatorSpecial{
        bool operator()(pair<int, int>& lhs, pair<int, int>& rhs){
            return lhs.second < rhs.second;
        }   
    };
};