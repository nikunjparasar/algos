#include <iostream>
using namespace std;
//kattis Digit Swap
int main() {
    ios_base::sync_with_stdio(false); 
    int n;
    cin >> n;
    cout << n%10 << n/10;
}