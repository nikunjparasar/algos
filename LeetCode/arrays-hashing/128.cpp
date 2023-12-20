#include "include.h"
using namespace std;

class Solution {
    public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int i = 0; i < nums.size(); i++){
            set.insert(nums[i]);
        }
        int longest = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(set.find(nums[i]-1) == set.end()){
                int length = 1;
                while(set.find(nums[i]+length) != set.end()){
                    length++;
                }
                longest = max(length, longest);
            }
        }


        return longest;

    }
};