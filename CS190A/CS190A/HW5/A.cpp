#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;


struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};


int n, c;

vector<pair<int, int>> words;
unordered_map<pair<int, int>, int, hash_pair> memo;

int minHeight(int i, int remainingWidth, int currentHeight, int totalHeight) {
    int minHeight1 = INT_MAX;
    int minHeight2 = INT_MAX;
    int nextWordWidth = words[i].first; 
    int nextWordHeight = words[i].second;   

    if (i == words.size()) return totalHeight + currentHeight;

    // check if the memoized state exists
    if (memo.find(make_pair(i, remainingWidth)) != memo.end()) return memo[make_pair(i, remainingWidth)] + totalHeight + currentHeight;
    
   
    // Case 1: Start a new line
    minHeight1 = minHeight(i + 1, c - nextWordWidth, nextWordHeight, totalHeight + currentHeight);

    // Case 2: Place in current line if it fits
    if (words[i].first <= remainingWidth) {
        minHeight2 = minHeight(i + 1, remainingWidth - words[i].first, max(currentHeight, words[i].second), totalHeight);
    }
    // chcek the best case and memoize the added height (subtract the accumulted one)
    memo[make_pair(i, remainingWidth)] = min(minHeight1, minHeight2) - (totalHeight + currentHeight);
    return memo[make_pair(i, remainingWidth)] + totalHeight + currentHeight;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> c;
    for(int i = 0; i < n; i++){
        int w, h;
        cin >> w >> h;
        words.push_back(make_pair(w, h));
    }
    cout << minHeight(0, c, 0, 0) << endl;

    return 0;
}