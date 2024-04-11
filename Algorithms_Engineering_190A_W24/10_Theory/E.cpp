#include <iostream>
#include <vector>   
#include <cmath>
#include <algorithm>
#include <stack>
#include <iomanip>
using namespace std;
//kattis board wrapping
#define ld long double  

struct point{
    ld x, y;
    point(ld x, ld y): x(x), y(y) { }
    point& operator=(const point &p){
        x = p.x;
        y = p.y;
        return *this;
    }
    bool operator==(const point &p) const{
        return abs(x - p.x) < 0.000001 && abs(y - p.y) < 0.000001;
    }
    bool operator<(const point &p) const{
        return x < p.x || (abs(x- p.x) < 0.000001 && y < p.y);
    }
    point(ld center_x, ld center_y, ld x, ld y, ld angle){
        ld dx = x - center_x;
        ld dy = y - center_y;   
        this->x = center_x + sqrt(dx*dx + dy*dy) * cos(atan2(dy, dx) - angle);
        this->y = center_y + sqrt(dx*dx + dy*dy) * sin(atan2(dy, dx) - angle);
    }
};

bool left_turn(point& a, point& b, point& c){
    return (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x) > 0;
}

vector<point> gscan(vector<point>& points){
    sort(points.begin(), points.end());
    vector<point> hull;
    hull.push_back(points[0]);
    hull.push_back(points[1]);
    for(int i = 2; i < points.size(); i++){
        hull.push_back(points[i]);  
        while(left_turn(hull[hull.size()-3], hull[hull.size()-2], hull[hull.size()-1])){
            point top = hull.back(); hull.pop_back();
            hull.pop_back();
            hull.push_back(top);
        }
    }
    for(int i = points.size()-2; i >= 0; i--){
        hull.push_back(points[i]);
        while(left_turn(hull[hull.size()-3], hull[hull.size()-2], hull[hull.size()-1])){
            point top = hull.back(); hull.pop_back();
            hull.pop_back();
            hull.push_back(top);
        }
    }
    return hull;
}

ld area_hull(vector<point>& points){
    int n = points.size();
    ld area = 0.0;

    for (int i = 0; i < n - 1; ++i) {
        area += points[i].x * points[i + 1].y - points[i + 1].x * points[i].y;
    }
    area += points[n - 1].x * points[0].y - points[0].x * points[n - 1].y;
    area = std::abs(area) / 2.0;
    return area;
}   

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int n;
        cin >> n;
        ld used_area = 0;
        vector<point> points;
        for(int j = 0; j < n; j++){
            ld x, y, w, h, v;
            cin >> x >> y >> w >> h >> v;
            v /= (180.0/M_PI);

            used_area += w*h;
            w /= 2;
            h /= 2;
            points.push_back(point(x, y, x-w, y-h, v));
            points.push_back(point(x, y, x+w, y-h, v));
            points.push_back(point(x, y, x-w, y+h, v));
            points.push_back(point(x, y, x+w, y+h, v));
        }   
        vector<point> convex_hull = gscan(points);
        ld total_area = area_hull(convex_hull);
        cout << fixed << setprecision(1) << double((used_area/total_area)*100.0)<< " %" << endl;  

    }
    return 0;
}