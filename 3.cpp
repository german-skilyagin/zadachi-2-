#include <iostream>
# include <cmath>

using namespace std;
int main () {

	int h, t, v, x, min, max;
	min = 10000;
	max = 0;
	cin >> h >> t >> v >> x;
	for (int i = 0; i <= t; i++) {
		if (((i * v) + ((t - i) * x)) >= h) {
			if (i > max) {
				max = i;
			}
			if (i < min) {
				min = i;
			}
		}
	}
	cout << min << " " << max;
	
	return 0;
	
}
