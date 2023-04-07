#include <vector>
using namespace std;

int main() {
	int h, w, n;
	cin >> h >> w >> n;
	vector<vector<int>> f(h + 1, vector<int>(w + 1, 0));

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> f[i][j];
		}
	}

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			f[i][j] = f[i][j] + f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
		}
	}

	for (int q = 0; q < n; q++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		int res = f[c][d] - f[c][b - 1] - f[a - 1][d] + f[a - 1][b - 1];
		cout << res << endl;
	}

	return 0;
}