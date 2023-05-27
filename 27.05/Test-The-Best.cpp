#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

vector<vector<char>> read() {
	int sizeI, sizeJ;
	cin >> sizeI >> sizeJ;
	vector <vector<char>> a(sizeI, vector<char>(sizeJ));
	for (int i = 0; i < sizeI; i++) {
		for (int j = 0; j < sizeJ; j++) {
			cin >> a[i][j];
		}
	}
	return a;
}

vector<vector<char>> diagMirror(const vector< vector <char>>& a) {
	int sizeI = (int)a.size();
	int sizeJ = (int)a[0].size();
	vector<vector<char>> r(sizeJ, vector<char>(sizeI));
	for (int i = 0; i < sizeI; i++) {
		for (int j = 0; j < sizeJ; j++) {
			r[j][i] = a[i][j];
		}
	}
	return r;
}

vector<vector<char>> horizMirror(const vector< vector <char>>& a) {
	int sizeI = (int)a.size();
	int sizeJ = (int)a[0].size();
	vector<vector<char>> r(sizeI, vector<char>(sizeJ));
	for (int i = 0; i < sizeI; i++) {
		for (int j = 0; j < sizeJ; j++) {
			r[sizeI - 1 - i][j] = a[i][j];
		}
	}
	return r;
}

vector<vector<char>> rotate90(const vector< vector <char>>& a) {
	return horizMirror(diagMirror(a));
}

vector<vector<char>> removeBorders(const vector< vector <char>>& a) {
	int sizeI = (int)a.size();
	int sizeJ = (int)a[0].size();
	int minI = sizeI;
	int maxI = -1;
	int minJ = sizeJ;
	int maxJ = -1;
	for (int i = 0; i < sizeI; i++) {
		for (int j = 0; j < sizeJ; j++) {
			if (a[i][j] == '#') {
				minI = min(minI, i);
				minJ = min(minJ, j);
				maxI = max(maxI, i);
				maxJ = max(maxJ, i);
			}
		}
	}
	if (maxI == -1) {
		return vector<vector<char>> ();
	}
	vector<vector<char>> r(maxI- minI + 1, vector<char>(maxJ - minJ + 1));
	for (int i = minI; i <= maxI; i++) {
		for (int j = minJ; j <= maxJ; j++) {
			r[i - minI][j - minJ] = a[i][j];
		}
	}
	return r;
}

int main(){
	vector<vector<char>> a = removeBorders(read());
	vector<vector<char>> b = removeBorders(read());
	for (int m = 0; m < 2; m++) {
		a = horizMirror(a);
		for (int r = 0; r < 4; r++) {
			a = rotate90(a);
			if (a == b) {
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
	return 0;
}