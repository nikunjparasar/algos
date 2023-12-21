#include "include.h"
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;
        vector<int> freq_1(26, 0);
        vector<int> freq_2(26, 0);
        for(int i = 0; i < s1.size(); i++){
            freq_1[s1[i]-'a']++;
            freq_2[s2[i]-'a']++;
        }
        for(int i = 0; i < s2.size()-s1.size();i++){
            if(freq_1 == freq_2) return true;
            freq_2[s2[i]-'a']--;
            freq_2[s2[i+s1.size()]-'a']++;
        }
        if(freq_1 == freq_2) return true;
        return false;
    }
};