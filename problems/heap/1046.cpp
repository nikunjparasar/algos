#include "include.h"
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i = 0; i < stones.size(); i++){
            pq.push(stones[i]);
        }
        while(pq.size() >= 2){
            int stone1 = pq.top();
            pq.pop();
            int stone2 = pq.top();
            pq.pop();
            if(stone1 == stone2) continue;
            int bigguy = max(stone1, stone2);
            int smallguy = min(stone1, stone2);
            pq.push(bigguy - smallguy);
        }
        return pq.empty() ? 0 : pq.top();
    }
};
