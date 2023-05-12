#include <iostream>
using namespace std;
double eps = 1e-9;
double Fabs(double a) {
    if (a < 0)
        return -a;
    return a;
}
bool Equal(double a, double b) {
    return Fabs(a - b) <= eps;
}
bool Less(double a, double b) {
    return a < b && !Equal(a, b);
}
struct point
{
    int x, y;
    void input()
    {
        cin >> x >> y;
    }
}p1, p2, p3, p4;
struct line
{
    double a, b, c;
    line(point p1, point p2)
    {
        a = p2.y - p1.y;
        b = p1.x - p2.x;
        c = -a * p1.x - b * p1.y;
    }
    int getSign(point p)
    {
        double value = a * p.x + b * p.y + c;
        if (Equal(value, 0.0)) return 0;
        else if (Less(value, 0.0)) return -1;
        else return 1;
    }
};
void input() {
    p1.input(); p2.input(); p3.input(); p4.input();
}
bool point_in_box(point p, point p1, point p2)
{
    return  min(p1.x, p2.x) <= p.x && p.x <= max(p1.x, p2.x) &&
        min(p1.y, p2.y) <= p.y && p.y <= max(p1.y, p2.y);
}
bool is_cross_segments(point p1, point p2, point p3, point p4)
{
    line l1 = line(p1, p2);
    line l2 = line(p3, p4);

    int sign1 = l1.getSign(p3) * l1.getSign(p4);
    int sign2 = l2.getSign(p1) * l2.getSign(p2);
    if (sign1 == 0 && sign2 == 0) // отрезки лежат на одной прямой
    {
        return point_in_box(p1, p3, p4) || point_in_box(p2, p3, p4)
            || point_in_box(p3, p1, p2) || point_in_box(p4, p1, p2);
    }
    else
        return sign1 <= 0 && sign2 <= 0; // отрезки пересекаются если знаки 0 или -1
}
int main() {
    input();
    if (is_cross_segments(p1, p2, p3, p4)) cout << "Yes";
    else cout << "No";
    return 0;
}