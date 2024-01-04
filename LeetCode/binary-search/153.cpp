#include "include.h"
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        while(l <= r){
            int mid = (l+r)/2;
            if(nums[l] <= nums[r]) return nums[l];
            if(nums[mid+1] > nums[mid] && nums[mid-1] > nums[mid]) return nums[mid];
            else if(nums[r] < nums[mid]) l = mid+1;
            else r = mid-1;
        }
        return nums[l];
    }
};