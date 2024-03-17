#include <iostream>
#include <cmath>
using namespace std;

long long fast_exp(long long base, long long exp, long long mod){
    long long res = 1;
    base = base % mod;
    while(exp > 0){
        if(exp % 2 == 1) res = (res * base) % mod;
        exp = exp / 2;
        base = (base * base) % mod;
    }
    return res;
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        long long x; cin >> x;    
        cout << (8* fast_exp(9, x-1, 1000000007))% 1000000007 << endl; 
    }
}