#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    int b = 0;
    int k = 0;
    char c;
    while(cin >> c){
        if(c == 'b') b++;
        if(c == 'k') k++;
    }
    if(b > k) cout << "boba" ;
    else if(k > b) cout << "kiki";
    else cout << (!b ? "none" : "boki");
    return 0;
}


