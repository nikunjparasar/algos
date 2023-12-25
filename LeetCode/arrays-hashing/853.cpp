#include "include.h"
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int, double>> cars;
        for(int i = 0; i < n; i++){
            double t = (double)(target-position[i])/(speed[i]);
            cars.push_back({position[i], t});
        }
        sort(cars.begin(), cars.end());

        double maxTime = 0.0;
        int fleets = 0;

        // revers because want farthest cars first
        for(int i = n-1; i >= 0; i--){
            if(cars[i].second > maxTime) {
                maxTime = cars[i].second;
                fleets++;
            }
        }
        
        return fleets;
    }
};
