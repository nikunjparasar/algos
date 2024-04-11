#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;
//kattis cutting corners

struct point {
    int x, y;
    point(int x, int y): x(x), y(y){}
};

double angle(const point& p1, const point& p2, const point& p3) {
    double ax = p2.x - p1.x;
    double ay = p2.y - p1.y;
    double bx = p3.x - p2.x;
    double by = p3.y - p2.y;

    double dot_product = ax * bx + ay * by;
    double magnitude_a = hypot(ax, ay); 
    double magnitude_b = hypot(bx, by);

    // Check for zero-length vectors
    if (magnitude_a == 0 || magnitude_b == 0) {
        return 0; // Angle is undefined or 0 for zero-length vectors
    }

    double cos_angle = dot_product / (magnitude_a * magnitude_b);
    cos_angle = max(-1.0, min(1.0, cos_angle)); // Clamping to avoid precision issues

    // Convert the angle from radians to degrees
    double angle_radians = acos(cos_angle);
    double angle_degrees = angle_radians * (180.0 / M_PI);

    return 180 - angle_degrees;
}


pair<int, double> sharpest_angle(vector<point>& shape) {
    double min_angle = numeric_limits<double>::max();
    int min_index = 0;
    for (int i = 0; i < shape.size(); i++) {
        point p1 = shape[i];
        point p2 = shape[(i + 1) % shape.size()];
        point p3 = shape[(i + 2) % shape.size()];
        double ang = angle(p1, p2, p3);
        // print the points
        // cout << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << " " << p3.x << " " << p3.y << endl;        
        // cout << ang << endl;
        if (ang < min_angle) {
            min_angle = ang;
            min_index = (i + 1) % shape.size();
        }
    }
    return make_pair(min_index, min_angle);
}

vector<point> cut_shape(vector<point>& shape){
    if(shape.size() == 3) return shape; 
    // calculate the sharpest angle
    pair<int, double> min_angle = sharpest_angle(shape);
    // cout << shape[min_angle.first].x << " " << min_angle.second << endl; 
    // remove that point
    vector<point> new_shape;
    for(int i = 0; i < shape.size(); i++){
        if(i != min_angle.first) new_shape.push_back(shape[i]);
    }
    // find the new sharpest angle
    pair<int, double> new_min_angle = sharpest_angle(new_shape);
    // if the new angle is less than the old angle, stop and return the old shape
    if(new_min_angle.second < min_angle.second) return shape;
    else return cut_shape(new_shape);

}   


int main() {
    int n;
    cin >> n;
    while (n) {
        vector<point> shape;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            shape.push_back(point(x, y));
        }
        vector<point> new_shape = cut_shape(shape);
        cout << new_shape.size() << " ";
        for (const point& p : new_shape) {
            cout << p.x << " " << p.y << " ";
        }
        cout << endl;
        cin >> n;
        
    }
    return 0;
}