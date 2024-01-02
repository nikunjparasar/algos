#include "include.h"
using namespace std;

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        size_t n = points.size();
        unordered_map<int, set<int>> coord;
        for(int i = 0; i < n; i++){
            coord[points[i][0]].insert(points[i][1]);
        }
        bool found = false;
        int minArea = INT_MAX;

        for(auto it = coord.begin(); it != coord.end(); it++){
            for(auto nx = next(it); nx!= coord.end(); nx++){
                int x1 = it->first;
                int x2 = nx->first;
                set<int>& y1s = it->second;
                set<int>& y2s = nx->second;

                //find matching y
                int sx = -1;
                for (int y1 : y1s) {
                    if (y2s.find(y1) != y2s.end()) {
                        if (sx != -1) {
                            int area = abs(x1 - x2) * abs(y1 - sx);
                            minArea = min(minArea, area);
                            found = true;
                        }
                        sx = y1;
                    }
                }
            }
        }

        return found ? minArea : 0;

    }
};