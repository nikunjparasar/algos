#include "include.h"
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int maxFreq = 0;
        int start = 0;
        int end = 0;
        vector<int> freq(26);
        while(end < s.size()){
            maxFreq = max(maxFreq, ++freq[s[end]-'A']);
            if(end - start + 1 - maxFreq > k){
                freq[s[start]-'A']--;
                start++;
            }
            ans = max(ans, end-start+1);
            end++;
        }
        return ans;
    }
};