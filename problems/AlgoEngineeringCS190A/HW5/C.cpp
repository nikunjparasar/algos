#include <iostream>
#include <unordered_map>
#include <vector>   
#include <utility>
using namespace std;



// struct hash_pair {
//     template <class T1, class T2>
//     size_t operator()(const pair<T1, T2>& p) const {
//         auto hash1 = hash<T1>{}(p.first);
//         auto hash2 = hash<T2>{}(p.second);
//         return hash1 ^ hash2;
//     }
// };


// memoization table <p, turn> -> winner
// unordered_map<pair<unsigned int, bool>, bool, hash_pair> memo;
// unordered_map<unsigned int, bool> memo_ollie_turn;
// unordered_map<unsigned int, bool> memo_stan_turn;
unordered_map<unsigned long long, bool> memo; // whether the current player wins with the current value of p or not

// true for stan winning and false for ollie winning
// true for stan's turn and false for ollie's turn  
bool playGame(unsigned long long p, unsigned int n, bool turn){
    for(int m = 2; m <=9; m++){
        if(p*m >= n) return turn;

        if(memo.find(p*m) != memo.end()){
            if(memo[p*m]) return turn;
            continue;
        }

        bool winner = playGame(p*m, n, !turn);   
        if(p*m < n) memo[p*m] = (winner == turn);
        if(memo[p*m]) return turn;
    }
    return !turn;

}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned int n;
    while(cin >> n){
        // memo_ollie_turn.clear();
        // memo_stan_turn.clear();
        memo.clear();
        if(playGame(1, n, true)) cout << "Stan wins." << endl;
        else cout << "Ollie wins." << endl;
        cout << sizeof(memo) << endl;
    }
}