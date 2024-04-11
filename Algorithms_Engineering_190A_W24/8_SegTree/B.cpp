#include <iostream>
#include <vector>   
using namespace std;
// Kattis Bridging Signals
class SegTree {
private:
    vector<int> tree;
    int n;

    void update(int index, int value){
        index += n;
        tree[index] = value;    
        while(index > 1){
            index /= 2;
            tree[index] = max(tree[2*index], tree[2*index + 1]); // left and right childs
        }
        cout << "tree: ";
        for(int i = 0; i < tree.size(); i++){
            cout << tree[i] << " ";
        }
        cout << endl;
    }

    int query(int l, int r) { // # of increasing #s in [l, r) (LIS)
        int ans = 0;
        l += n;
        r += n;
        while(l < r){
            if(l % 2 == 1){
                ans = max(ans, tree[l++]);
            }
            if(r % 2 == 1){
                ans = max(ans, tree[--r]);
            }
            l /= 2;
            r /= 2;
        }
        return ans;
    }

public:
    SegTree(int size) : n(size), tree(2 * size, 0) {}

    int solve(const vector<int>& signals) {
        int max_signals = 0;
        for(int i = 0; i < signals.size(); i++){
            int length = query(0, signals[i]) + 1; 
            cout << "length: " << length << endl;   
            update(signals[i], length);
            max_signals = max(max_signals, length);
        }
        return max_signals;
    }   
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int p;
    cin >> p;
    vector<int> ports(p);

    for(int i = 0; i < p; i++){
        cin >> ports[i];    
    }

    SegTree st(p+1);

    cout << st.solve(ports) << endl;

    return 0;
}



