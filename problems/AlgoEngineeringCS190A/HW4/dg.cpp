#include <iostream>
#include <iomanip>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    int x, y, n; 
    cin >> x >> y >> n;    
    float c, p = 0; 
    for(int i = 0; i < n; i++){
        int l, u; float f;
        cin >> l >> u >> f;
        p += float(u-l)/y;
        c += f*(float(u-l)/y);
    }
    c += (1-p);
    float vxavg = x/float(y); 
    cout << fixed << setprecision(6) << vxavg/c << endl;

    return 0;
}