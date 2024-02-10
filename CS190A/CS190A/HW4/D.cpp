#include <iostream>
#include <iomanip>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ix, iy, n; // since v_y is always 1, i_y is the time to reach i_x
    cin >> ix >> iy >> n;    
    float c = 0; // sum of coefficients
    float p = 0; // percent covered y
    for(int i = 0; i < n; i++){
        int l, u; float f;
        cin >> l >> u >> f;
        p += float(u-l)/iy;
        c += f*(float(u-l)/iy);
    }
    c += (1-p);
    float vxavg = ix/float(iy); // average speed in x direction to reach at same time as y
    cout << fixed << setprecision(6) << vxavg/c << endl;

    return 0;
}