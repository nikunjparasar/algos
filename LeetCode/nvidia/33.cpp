#include "include.h"
using namespace std;    

class Solution {
public:
    int search(vector<int>& nums, int target) { 
        int l = 0;
        int r = nums.size()-1;
        while(l <= r){
            int mid = (l+r)/2;
            if(nums[mid] == target) return mid;
            // left side acsending
            else if(nums[l] <= nums[mid]){
                if(nums[l] <= target && nums[mid] >= target){
                    r= mid-1;
                    continue;
                }
                else {
                    l = mid+1;
                    continue;
                }
            }
            // right side ascending
            else{
                if(nums[mid] <= target && nums[r] >= target){
                    l = mid+1;
                    continue;
                }
                else {
                    r = mid-1;
                    continue;
                }
            }
        }
        return -1;
    }
};