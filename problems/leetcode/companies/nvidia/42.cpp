#include "include.h"
using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        // preprocess the max height to the left and right of every section
        vector<int> maxLeft(n, 0);
        vector<int> maxRight(n, 0);
        int ans = 0;
        int maxL = 0;
        for(int i = 1; i < n; i++){
            maxL = max(maxL, height[i-1]);
            maxLeft[i] = maxL;
        }
        int maxR = 0;
        for(int i = n-2; i >= 0; i--){
            maxR = max(maxR, height[i+1]);
            maxRight[i] = maxR;
        }

        for(int i = 0; i< n; i++){
            int h = min(maxLeft[i], maxRight[i]);
            ans += h > height[i] ? h-height[i] : 0;
        }
        return ans;
    }
};