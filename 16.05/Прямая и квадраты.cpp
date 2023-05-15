#include <iostream>
using namespace std;

struct Point {
	int x;

	int y;
};

struct Line {
	int a;

	int b;

	int c;

	Line(const Point &p1, const Point &p2)
		: a(p2.y - p1.y), b(p1.x - p2.x), c(p1.y * p2.x - p1.x * p2.y)
	{	}
	int sign(const Point& p) const {
		return a * p.x + b * p.y + c;
	}
};

int main() {
	int n, w, e, ans = 0;
	cin >> n >> w >> e;
	Line line(Point{ 0, w }, Point{ 100 * n, e });
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			Point p1{ 100 * i, 100 * j };
			Point p2{ 100 * i, 100 * j - 100 };
			Point p3{ 100 * i - 100, 100 * j };
			Point p4{ 100 * i - 100, 100 * j - 100 };
			int v1 = line.sign(p1);
			int v2 = line.sign(p2);
			int v3 = line.sign(p3);
			int v4 = line.sign(p4);
			if((v1 > 0 && v2 > 0 && v3 > 0 && v4 > 0) || (v1 < 0 && v2 < 0 && v3 < 0 && v4 < 0)){ /*skip*/ }
			else { ans++; }

		}
	}
	cout << ans;
	return 0;
}