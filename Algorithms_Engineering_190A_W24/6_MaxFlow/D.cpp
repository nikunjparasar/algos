#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// Kattis Tomography
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m, n;
    cin >> m >> n;

    vector<int> row_sums(m);
    vector<int> col_sums(n);    

    for(int i = 0; i < m; i++){
        cin >> row_sums[i];
    }   
    for(int i = 0; i < n; i++){
        cin >> col_sums[i];
    }

    
    // priority_queue<int> rows(row_sums.begin(), row_sums.end());
    // priority_queue<int> cols(col_sums.begin(), col_sums.end());
    auto cmp = [](int left, int right) { return left < right; }; 

    vector<int>& small = row_sums.size() > col_sums.size() ? col_sums : row_sums;
    vector<int>& big = row_sums.size() > col_sums.size() ? row_sums : col_sums;

    make_heap(small.begin(), small.end(), cmp);
    make_heap(big.begin(), big.end(), cmp);


    // cout << "big heap" << endl;
    // for(int i = 0; i < big.size(); i++){
    //     cout << big[i] << " "; 
    // }
    // cout << endl;
    // cout << "small heap" << endl;
    // for(int i = 0; i < small.size(); i++){
    //     cout << small[i] << " "; 
    // }
    // cout << endl;


    while(small.size() != 0){
        int most = small.front(); // biggest element in the smaller array
        if(most == 0) break;

        int top = big.front(); // smallest element in the bigger array

        vector<int> temps(0, 0);

        for(int i = 0; i < most; i++){
            // take out the top element and decrease it by 1
            
            top = big.front();
            pop_heap(big.begin(), big.end(), cmp);
            big.pop_back();
            // cout << "removed elem from big" << endl;

            temps.push_back(top-1);

        }
        
        // put back the modified elements
        for(int i = 0; i < temps.size(); i++){
            // cout << "put back the modified element" << endl;

            big.push_back(temps[i]);
            push_heap(big.begin(), big.end(), cmp);
        }   
        

        // cout << "reduced size of small" << endl;
        // done with the element in the smaller array   
        pop_heap(small.begin(), small.end(), cmp); 
        small.pop_back();  
    }
    // cout << "big size: " << big.size() << endl; 
    // cout << "small size: " << small.size() << endl; 
    
    bool ans = true;
    for(int i = 0; i < big.size(); i++){
        // cout << big[i] << " "; 
        if(big[i] != 0){
            ans = false;
            break;
        }
    }
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}