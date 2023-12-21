#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>
#include <cctype> 
using namespace std;

int main() {
    map<string, int> wordMap;
    wordMap["zero"] = 0;
    wordMap["one"] = 1;
    wordMap["two"] = 2;
    wordMap["three"] = 3;
    wordMap["four"] = 4;
    wordMap["five"] = 5;
    wordMap["six"] = 6;
    wordMap["seven"] = 7;
    wordMap["eight"] = 8;
    wordMap["nine"] = 9;


    ifstream file("01_data.txt");
    string line;
    long long ans = 0;

    int l = 1;
    while (getline(file, line)) {
        vector<int> nums(line.size(), -1);

        for(auto it = wordMap.begin(); it != wordMap.end(); it++) {
            while(line.find(it->first) != string::npos){
                size_t pos = line.find(it->first);
                line[pos+1] = '*';
                nums[pos] = it->second;
            }
        }
        for(int i = 0; i< line.size(); i++) {
            if (isdigit(line[i])) {
                nums[i] = line[i] - '0';
            }
        }
        while(nums[0] == -1) {
            nums.erase(nums.begin());
        }
        while(nums[nums.size()-1] == -1) {
            nums.erase(nums.end()-1);
        }
        int code = nums[0]*10 + nums[nums.size()-1];
        ans += code;

        std::cout << l++ << ": " << code << endl;
        
    }

    std::cout << "ANSWER: " << ans << "\n"; 
    return 0;
}

