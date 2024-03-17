#include "include.h"
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //check all rows
        for(int i = 0; i< 9; i++){
            if(!check_2D_gen(board, i, i, 0, 8)) return false;
        }
        //check all columns
        for(int i = 0; i<9; i++){
            if(!check_2D_gen(board, 0, 8, i, i)) return false;
        }
        //check all squares
        for(int i = 2; i<9; i+=3){
            int j=i-2;
            if(!check_2D_gen(board, 0, 2, j, i) || 
               !check_2D_gen(board, 3, 5, j, i) || 
               !check_2D_gen(board, 6, 8, j, i)){
                return false;
            }
        }
        return true;
  
        
    }
    bool check_2D_gen(vector<vector<char>>& board, int start_row, int end_row, int start_col, int end_col){
        unordered_map<int, bool> m;
        for(int i = start_col; i <=end_col; i++){
            for(int j = start_row; j<=end_row; j++){
                if(board[i][j] == '.') continue;
                else{
                    int curr = int(board[i][j] - '0');
                    if(m[curr]) return false;
                    else m[curr] = true;
                }
                
            }
        }
        return true;
    }
};