#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point {
    int x;
    int y;
};



int main() {
    int mx, my;
    double r;
    cin >> mx >> my >> r;
    int n;
    cin >> n;
    vector <Point> p;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x -= mx;
        y -= my;
        if (sqrt(x * x + y * y) <= r) { p.push_back(Point{ x, y }); }
    }
    int ans = 0;
    for (Point p1 : p) {
        int on = 0, left = 0, right = 0;
        for (Point p2 : p) {
            int cp = p1.x * p2.y - p2.x * p1.y;
            if (cp < 0) { left++; }
            else if (cp > 0) { right++; }
            else { on++; }
        }
        ans = max({ ans, on + left, on + right });
    }
    cout << ans;
    return 0;
}