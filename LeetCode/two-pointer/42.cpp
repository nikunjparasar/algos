#include "include.h"
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lmax(n);
        vector<int> rmax(n);
        int water = 0;
        int l_max = 0;
        int r_max = 0;
        for(int i = 0; i < n; i++){
            lmax[i] = l_max;
            rmax[n-1-i] = r_max;
            l_max = max(l_max, height[i]);
            r_max = max(r_max, height[n-1-i]);
        }
        for(int i = 0; i < n; i++){
            water += max(0, (min(lmax[i], rmax[i]) - height[i]));
        }
        return water;

    }
};