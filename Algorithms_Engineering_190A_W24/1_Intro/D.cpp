#include <iostream>
using namespace std;
// Kattis Triangle Area
int main(){
    ios_base::sync_with_stdio(false);
    int h, b;
    cin >> h >> b;
    cout << double(h*b)/2.0 << endl;
    return 0;
}