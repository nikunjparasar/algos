#include "include.h"
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;
        for(int i = 0; i < nums.size(); i++){
            int comp = target-nums[i];
            if(index.find(comp) != index.end()){
                return {index[comp], i};
            }
            index[nums[i]] = i;
        }
        return {-1, -1};
    }
};