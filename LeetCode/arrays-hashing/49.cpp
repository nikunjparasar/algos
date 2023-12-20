#include "include.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for(auto e : strs){
            string base = e;
            sort(base.begin(), base.end());
            map[base].push_back(e);
        }


        vector<vector<string>> ans;
        for(auto e : map){
            ans.push_back(e.second);
        }

        return ans;
    }
};