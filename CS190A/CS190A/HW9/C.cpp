#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <map>
#include <unordered_map>
#include <sstream>
using namespace std;

// long long serialize_grid(const vector<vector<char>>& grid){
//     long long s = 0;
//     for(int x = 0; x < 5; ++x){
//         for(int y = 0; y < 5; ++y){

//         }
//     }
//     return s;
// }

// int serialize_loc(int x, int y){
//     return x * 5 + y;
// }
// pair<int, int> deserialize_loc(int spc){
//    return make_pair(spc / 5, spc % 5);
// }

struct hash_grid {
    size_t operator()(const vector<vector<char>>& grid) const {
        long long s = 0;
        for(int x = 0; x < 5; ++x){
            for(int y = 0; y < 5; ++y){
                s = s * 10 + grid[x][y];
            }
        }
        return hash<long long>()(s);
    }
};


int main(){
    // clock_t start = clock();
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    const vector<vector<char>> TARGET_BOARD = {
        {'1', '1', '1', '1', '1'},
        {'0', '1', '1', '1', '1'},
        {'0', '0', ' ', '1', '1'},
        {'0', '0', '0', '0', '1'},
        {'0', '0', '0', '0', '0'}
    };
    // const string FEN = serialize_grid(TARGET_BOARD);


    map<vector<vector<char>>, int> precomp;
    queue<vector<vector<char>>> q;  
    precomp[TARGET_BOARD] = 0;
    q.push(TARGET_BOARD);

    const int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    const int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    
    while(!q.empty()){
        auto board = q.front();
        q.pop();

        if(precomp[board] >= 10) continue; 
        int spacex = -1, spacey = -1;
        for (int x = 0; x < 5 && spacex == -1; ++x) {
            for (int y = 0; y < 5; ++y) {
                if (board[x][y] == ' ') {
                    spacex = x;
                    spacey = y;
                    break;
                }
            }
        }


        for(int i = 0; i < 8; ++i){
            int newx = spacex + dx[i];
            int newy = spacey + dy[i];
            if(newx >= 0 && newx < 5 && newy >= 0 && newy < 5){
                vector<vector<char>> new_board(5, vector<char>(5));
                for(int x = 0; x < 5; ++x){
                    for(int y = 0; y < 5; ++y){
                        new_board[x][y] = board[x][y];
                    }
                }
                swap(new_board[spacex][spacey], new_board[newx][newy]);
                if(precomp.count(new_board) == 0){
                    precomp[new_board] = precomp[board] + 1;
                    q.push(new_board);
                }
                swap(new_board[spacex][spacey], new_board[newx][newy]);
            }
        }
    }

    // for(auto it = precomp.begin(); it != precomp.end(); ++it){
    //     cout << it->first << " " << (int)it->second << endl;
    // }
    // cout << precomp.size() << endl;    


    // printf("Time taken: %.2fs\n", (double)(clock() - start)/CLOCKS_PER_SEC);

    int n;
    cin >> n;
    ostringstream oss("");
    while(n) {
        vector<vector<char>> board(5, vector<char>(5));
        for(int i = 0; i < 5; i++) {
            cin.ignore();
            for(int j = 0; j < 5; j++) {
                board[i][j] = getchar();
            }
        }
        // string st = serialize_grid(board);
        auto it = precomp.find(board);
        if(it != precomp.end()) {
            cout << "Solvable in " << precomp[board] << " move(s)." << endl;
        }
        else {
            cout << "Unsolvable in less than 11 move(s)." << endl;
        }
        n--;
    }
    // cout << oss.str();  

    return 0;
}