#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int n; cin >> n; int sum = 0; int maxx = 0;
	for (int i = 0; i < n; i++) { int value; cin >> value; sum += value; maxx = max(maxx, value); }
	cout << min(sum / 2, sum - maxx) << endl;
	return 0;
}