#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <cassert>
using namespace std;

void research() {
	typedef long double real;
	vector <real> xs;
	for (int a = -200; a <= 200; a++) {
		for (int b = -200; b <= 200; b++) {
			for (int c = -200; c <= 200; c++) {
				if (a == 0 && b == 0) {
					
				}
				else if (a == 0) {
					real x = -(real)c / b;
					if (0 <= x && x <= 1) {
						xs.push_back(x);
					}
				}
				else {
					assert(a != 0);
					int d = b * b - 4 * a * c;
					if (d >= 0) {
						real x1 = (-b + sqrt((real)d)) / (2 * a);
						if (0 <= x1 && x1 <= 1) {
							xs.push_back(x1);
						}
						real x2 = (-b + sqrt((real)d)) / (2 * a);
						if (0 <= x2 && x2 <= 1) {
							xs.push_back(x2);
						}
					}
				}
			}
		}
	}
	sort(xs.begin(), xs.end());
	xs.erase(unique(xs.begin(), xs.end()), xs.end());
	real minD = 0;
	real maxD = 0;
	for (int i = 1; i < (int)xs.size(); i++) {
		real d = xs[i] - xs[i - 1];
		assert(d > 0);
		if (d > 1e-12) {
			minD = min(minD, d);

		}
		else {
			maxD = max(maxD, d);
		}
	}
	cout << (double)minD << (double)maxD;
	exit(0);
}
void addRoots(int a, int b, int c, vector<double>& xs) {
	assert(-100 <= a && a <= 100);
	assert(-100 <= b && b <= 100);
	assert(-100 <= c && c <= 100);
	if (a == 0 && b == 0) {
		
	}
	else if (a == 0) {
		double x = (double)-c / b;
		if (0 < x && x < 1) {
			xs.push_back(x);
		}
	}
	else {
		assert(a != 0);
		int d = b * b - 4 * a * c;
		if (d >= 0) {
			double x1 = (-b - sqrt((double)d)) / (2 * a);
			if (0 < x1 && x1 < 1) {
				xs.push_back(x1);
			}
			double x2 = (-b + sqrt((double)d)) / (2 * a);
			if (0 < x2 && x2 < 1) {
				xs.push_back(x2);
			}
		}
	}
}

struct Item {
	double s;
	int index;
	int rank;
};

int main() {
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(3));
	for (int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	vector <double> xs;
	xs.push_back(0);
	xs.push_back(1);
	for (int i = 0; i < n; i++) {
		for (int j = 1 + i; j < n; j++) {
			addRoots(a[i][0] - a[j][0], a[i][1] - a[j][1], a[i][2] - a[j][2], xs);
		}
	}
	sort(xs.begin(), xs.end());
	int last = 0;
	for (int i = 1; i < (int)xs.size(); i++) {
		double d = xs[i] - xs[last];
		assert(d >= 0);
		if (d > 1e-12) {
			last++;
			xs[last] = xs[i];
		}
	}
	xs.resize(last + 1);
	{
		assert(xs[0] == 0);
		assert(xs.size() >= 2);
		vector<double> t;
		for (int i = 1; i < (int)xs.size(); i++) {
			t.push_back((xs[i] + xs[i - 1]) / 2);
			t.push_back(xs[i]);
		}
		xs.swap(t);
	}
	vector<vector<int>> ans;
	vector<Item> items(n);
	for (double x : xs) {
		for (int i = 0; i < n; i++) {
			items[i].s = a[i][0] * x * x + a[i][1] * x + a[i][2];
			items[i].index = i;
		}
		sort(items.begin(), items.end(), [](const Item& left, const Item& right) {
			return left.s > right.s;
			});
		items[0].rank = 0;
		for (int i = 1; i < n; i++) {
			double d = items[i - 1].s - items[i].s;
			assert(d >= 0);
			if (d <= 1e-13) {
				items[i].rank = items[i - 1].rank;
			}
			else {
				items[i].rank = i;
			}
		}
		sort(items.begin(), items.end(), [](const Item& left, const Item& right) {
			return left.index < right.index;
			});
		ans.push_back(vector<int>(n));
		for (int i = 0; i < n; i++) {
			ans.back()[i] = items[i].rank;
		}
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	cout << (int)ans.size();
	return 0;
}