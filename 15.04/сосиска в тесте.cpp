#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double d, r;
    cin >> d >> r;
    int n;
    cin >> n;
    const double pi = acos(-1.0);
    for (int i = 1; i < n; i++) {
        double s = i * (pi * r * r + 2 * r * d) / n;
        double left = 0;
        double right = 2 * r + d;
        for (int j = 0; j < 64; j++) {
            double mid = (left + right) / 2;
            double mids;
            if (mid < r) {
                double teta = 2 * acos((r - mid)/r);
                mids = r * r / 2 * (teta - sin(teta));
            }
            else if (mid <= r + d) {
                mids = pi * r * r / 2 + (mid - r) * 2 * r;
            }
            else {
                double teta = 2 * acos((r - (2 * r + d - mid)) / r);
                mids = (pi * r * r + 2 * r * d) - r * r / 2 * (teta - sin(teta));
            }
            if (mids > s) {
                right = mid;
            }
            else { left = mid; }
        }
        cout << (left + right) / 2 << endl;
    }

    return 0;
}