#include <iostream>
#include <vector>
#include <algorithm>    
using namespace std;
// Kattis Ants
int main(){
    ios_base::sync_with_stdio(false);
    int cases;
    int l, n;
    cin >> cases;
    for(int i = 0; i < cases; i++){
        cin >> l >> n;
        vector<int> pos(n);
        for(int j = 0; j < n; j++){
            cin >> pos[j];  
        }
        sort(pos.begin(), pos.end()); 
        int minT = 0;
        int maxT = 0;
        for(int a = 0; a < n; a++){
            // choose the shorter side of the stick
            minT = max(minT, min(pos[a], l-pos[a]));
            // if two ants collide --><-- they switch directions to <-- --> 
            // but if u ignore which ant it was, the positions and speeds 
            // are like they passed each other. So just choose the longer side            
            maxT = max(maxT, max(pos[a], l-pos[a]));
        }
        cout << minT << " " << maxT << endl;   
    }
    return 0;
}