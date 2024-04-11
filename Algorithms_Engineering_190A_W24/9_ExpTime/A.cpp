#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
//Kattis Page Layout

struct story {
    int w, h, x, y;
    story(int w, int h, int x, int y) : w(w), h(h), x(x), y(y) {}
};  

bool fits(story &s1, story &s2) {
    return s1.x >= s2.x + s2.w || s1.x + s1.w <= s2.x || s1.y >= s2.y + s2.h || s1.y + s1.h <= s2.y;
}
vector<story> stories;
int ans;

int solve(vector<story> &used, int num_tried) {
	if (num_tried == stories.size()) { 
		int area = 0;
		for(auto &s: used) area += s.w * s.h;
		ans = max(ans, area);
		return ans;
	}

	bool fits = true;
	for (auto &s: used) fits = fits && ::fits(stories[num_tried], s);
	
	if (fits) {
		used.push_back(stories[num_tried]);
		solve(used, num_tried + 1);
		used.pop_back();
	}
	
	solve(used, num_tried + 1);
    return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, w, h, x, y;
	cin >> n;
	while (n != 0) {
		stories.clear();
		ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> w >> h >> x >> y;
            story s(w, h, x, y);
			stories.push_back(s);
		}

		vector<story> used;
		solve(used, 0);
		cout << ans << endl;
		cin >> n;
	}

	return 0;
}