#include <iostream>
#include <vector>   
using namespace std;

class SegTree { 
private:
int n;
vector<int> tree;
public:
    SegTree(int size) : n(size), tree(6 * size, 0) {}
    
    void update(int index, int l, int r, int num){
        if (l == num && r == num) {
            tree[index] = 1;
            return;
        }

        if (num < l || num > r) return;
        
        int mid = (l + r)/2;
        update(2 * index, l, mid, num);
        update(2 * index + 1, mid + 1, r, num);
        //both the child nodes have been updated, now update the parent node
        tree[index] = tree[2 * index] + tree[2 * index + 1];
    }


    int query(int index, int l, int r, int x, int y){
        if(l >= x && r <= y) return tree[index];
        if(r < x || l > y) return 0;
        int mid = (l + r) / 2;
        return query(2 * index, l, mid, x, y) + query(2 * index + 1, mid + 1, r, x, y);
    } 

};


// // use merge sort instead to count inversions, should still be nlogn
// long long merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right){
//     int l = left;
//     int r = mid;
//     int temp_idx = left;
//     long long inv_count = 0;

//     while((l < mid) && (r <= right)){
//         if(arr[l] <= arr[r]){
//             temp[temp_idx] = arr[l];
//             temp_idx++;
//             l++;
//         } else { //  If an element from the right sub-array is 
//         //placed into temp before an element from the left sub-array
//         // there is inversions
//             temp[temp_idx] = arr[r];
//             inv_count += (mid - l);
//             temp_idx++;
//             r++;
//         }
//     }

//     while(l <= mid - 1){
//         temp[temp_idx] = arr[l];
//         temp_idx++;
//         l++;
//     }
//     while(r <= right){
//         temp[temp_idx] = arr[r];
//         temp_idx++;
//         r++;
//     }
//     for(int z = left; z <= right; z++){
//         arr[z] = temp[z];
//     }
//     return inv_count;
// }

// long long inv(vector<int>& arr, vector<int>& temp, int left, int right){
//     long long ans = 0;
//     if(right <= left) return 0;
//     else{
//         int mid = (left + right)/2;
//         ans += inv(arr, temp, left, mid); 
//         ans += inv(arr, temp, mid + 1, right);
//         ans += merge(arr, temp, left, mid + 1, right);
//     }
//     return ans;
// }

long long count_inv(vector<int>& a){
    int n = a.size();
    long long ans = 0;
    SegTree tree(n);
    for(int i = 0; i < n; i++){
        ans += tree.query(1, 1, n, a[i]+1, n);
        tree.update(1, 1, n, a[i]);
    }
    return ans;
}



long long solve(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& pos_a, vector<int>& pos_b, vector<int>& pos_c){
    long long n = a.size();
    vector<int> change_a(n);
    vector<int> change_b(n);
    vector<int> change_c(n);

    for (int i = 0; i < n; i++) { 
		change_b[i] = pos_a[b[i]]; // a vs b
        change_c[i] = pos_b[c[i]]; // b vs c
        change_a[i] = pos_c[a[i]]; // c vs a
	}
    // vector<int> temp(n, 0);
    // long long inv_b = inv(change_b, temp, 0, n-1);
    // temp = vector<int>(n, 0);   
    // long long inv_c = inv(change_c, temp, 0, n-1);
    // temp = vector<int>(n, 0);
    // long long inv_a = inv(change_a, temp, 0, n-1);

    // cout << inv_a << " " << inv_b << " " << inv_c << endl;  
    long long inv_b = count_inv(change_b);
    long long inv_c = count_inv(change_c);
    long long inv_a = count_inv(change_a);


    long long permutations = n * (n - 1) / 2;   
    long long total = (inv_a + inv_b + inv_c) / 2;
    return permutations - total;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> jaap(n);
    vector<int> jan(n);
    vector<int> thijs(n);
    vector<int> pos_jaap(n+1);
    vector<int> pos_jan(n+1);
    vector<int> pos_thijs(n+1);


    for(int i = 0; i < n; i++) { 
        cin >> jaap[i]; 
        pos_jaap[jaap[i]] = i+1;
    }
    for(int i = 0; i < n; i++) { 
        cin >> jan[i]; 
        pos_jan[jan[i]] = i+1;
    }
    for(int i = 0; i < n; i++) { 
        cin >> thijs[i]; 
        pos_thijs[thijs[i]] = i+1;
    }

    
    
    cout << solve(jaap, jan, thijs, pos_jaap, pos_jan, pos_thijs) << endl;   

}