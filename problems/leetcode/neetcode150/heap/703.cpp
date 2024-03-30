#include "include.h"
using namespace std;

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq; // min heap
    int size;

public:
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for(int i = 0; i < nums.size(); i++){
            if(pq.size() < size){
                pq.push(nums[i]);
            }
            else{
                pq.push(nums[i]);
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > size) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */