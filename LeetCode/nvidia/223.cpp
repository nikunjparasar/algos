#include "include.h"
using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area_a = (ax2-ax1)*(ay2-ay1);
        int area_b = (bx2-bx1)*(by2-by1);
        if(bx2 <= ax1 || bx1 >= ax2 || by2 <= ay1 || by1 >= ay2){
            return area_a + area_b;
        }
        else{
            int ox = min(ax2, bx2) - max(ax1, bx1);
            int oy = min(ay2, by2) - max(ay1, by1);
            int overlap = oy*ox;
            return area_a + area_b - overlap;
        }
    }
};

