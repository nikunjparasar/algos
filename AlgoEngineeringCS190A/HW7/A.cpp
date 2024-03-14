#include <iostream>
#include <vector>
#include <sstream>
using namespace std;


struct line{
    double x1, y1, x2, y2;
    line(double x1, double y1, double x2, double y2): x1(x1), y1(y1), x2(x2), y2(y2){}  
};

struct point{
    double x, y;
    bool valid;
    point(double x, double y, bool valid): x(x), y(y), valid(valid){}
};  

point intersection(line l1, line l2){
    // check if the intersection exists using cramers rule
    // make the system:
    // ax + cy = p
    // bx + dy = q
    // where (a b) is not (0, 0) and (c, d) is not (0, 0)
    // Make matrices:
    // M = |a c|
    //     |b d|
    // Mx = |p c|
    //      |q d|
    // My = |a p|
    //      |b q|
    // Det(M) = ad - bc
    // x = Det(Mx) / Det(M)
    // y = Det(My) / Det(M)
    // has unique solution if det(M) != 0
    double a = l1.y2 - l1.y1;
    double b = l1.x1 - l1.x2;
    double c = l2.y2 - l2.y1;
    double d = l2.x1 - l2.x2;
    double det = a * d - b * c;
    if(abs(det) < 0.0001) return point(0, 0, false);

    double p = l1.x1 * l1.y2 - l1.y1 * l1.x2;
    double q = l2.x1 * l2.y2 - l2.y1 * l2.x2;
    double x = (p * d - b * q) / det;
    double y = (a * q - p * c) / det;

    
    // also need to check that the intersection is on the line segments
    if(x < min(l1.x1, l1.x2) || x > max(l1.x1, l1.x2) || y < min(l1.y1, l1.y2) || y > max(l1.y1, l1.y2)
        || x < min(l2.x1, l2.x2) || x > max(l2.x1, l2.x2) || y < min(l2.y1, l2.y2) || y > max(l2.y1, l2.y2)) return point(0, 0, false);

    return point(x, y, true);
} 


bool test_triangle(line l1, line l2, line l3){
    point p1 = intersection(l1, l2);
    point p2 = intersection(l1, l3);
    point p3 = intersection(l2, l3);

    if(!p1.valid || !p2.valid || !p3.valid) return false;
    
    // false if any of the points are the same
    if(abs(p1.x - p2.x) < 0.0001 && abs(p1.y - p2.y) < 0.0001) return false;
    if(abs(p1.x - p3.x) < 0.0001 && abs(p1.y - p3.y) < 0.0001) return false;
    if(abs(p2.x - p3.x) < 0.0001 && abs(p2.y - p3.y) < 0.0001) return false;


    return true;
}

int main() {
    int n;
    cin >> n;
    stringstream ss;
    while(n){
        vector<line> lines;
        for(int i = 0; i < n; i++){
            double x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            line l(x1, y1, x2, y2);
            lines.push_back(l);
        }

        int num_triangles = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                for(int k = j+1; k < n; k++){
                    if(test_triangle(lines[i], lines[j], lines[k])) num_triangles++;
                }
            }
        }
        ss << num_triangles << endl;    
        cin >> n;
    }
    cout << ss.str();   
    return 0;
}