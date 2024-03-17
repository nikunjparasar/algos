#include "iostream"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    int n;
    cin >> n;
    cout << ((n>= 5550000 && n <= 5559999 )? 1 : 0);
    return 0;
}