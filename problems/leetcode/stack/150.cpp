#include "include.h"
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int second = nums.top();
                nums.pop();
                int first = nums.top();
                nums.pop(); 
                if(tokens[i] == "+") nums.push(first +second);
                else if (tokens[i] == "-") nums.push(first - second);
                else if (tokens[i] == "*") nums.push(first * second);
                else nums.push(first/second);
            }
            else{
                nums.push(stoi(tokens[i]));
            }
        }

        return nums.top();
    }
};

