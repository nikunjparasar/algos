#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>
#include <cctype> 
using namespace std;

int main() {


    ifstream file("01_data.txt");
    string line;
    long long ans = 0;

    while (getline(file, line)) {
        vector<int> nums(line.size(), -1);
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
        ans += nums[0]*10;
        ans+= nums[nums.size()-1];
    }

    cout << "ANSWER: " << ans << "\n"; 
    return 0;
}
