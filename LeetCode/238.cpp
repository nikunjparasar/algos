#include "include.h"
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix;
        vector<int> suffix(nums.size(), nums.back());
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(i == 0) prefix.push_back(nums[0]);
            else{
                prefix.push_back(nums[i]*prefix.back());
            }
        }
        for(int i = nums.size()-2; i >= 0; i--){
            suffix[i] = suffix[i+1]*nums[i];
        }
        for(int i = 0; i<nums.size(); i++){
            if(i == 0){
                ans.push_back(suffix[1]);
            }
            else if(i == nums.size()-1){
                ans.push_back(prefix[nums.size()-2]);
            }
            else{
                ans.push_back(prefix[i-1]*suffix[i+1]);
            }
        }
        return ans;
    }
};