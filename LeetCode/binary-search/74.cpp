#include "include.h"
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        int l = 0;
        int r = matrix.size()-1;
        while(l <= r){
            int row = (l+r)/2;
            if(matrix[row].front() <= target && matrix[row].back() >= target){
                int low = 0;
                int high = matrix[row].size() -1;
                int mid = (low + high)/2;
                while(low <= high){
                    mid = (low + high)/2;
                    if(matrix[row][mid] == target) return true;
                    else if(matrix[row][mid] <= target) low = mid+1;
                    else high = mid-1;
                }
                return false;
            }
            else if(matrix[row].front() >= target) r = row-1;
            else l = row+1;
        }
        return false;

    }
};