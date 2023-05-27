#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

int main(){
	int sizeI, sizeJ;
	cin >> sizeI >> sizeJ;
	vector<vector<int>> a(sizeI, vector<int>(sizeJ));
	for (int i = 0; i < sizeI; i++) {
		for (int j = 0; j < sizeJ; j++) {
			cin >> a[i][j];
		}
	}
	int i1 = -1;
	for (int i = 0; i < sizeI; i++) {
		for (int j = 0; j < sizeJ; j++) {
			if (a[i][j] == 1) { i1 = i; }
		}
	}
	vector<string> ans;
	assert(i1 >= 0);
	for (int dstJ = 0; dstJ < sizeJ; dstJ++) {
		int minJ = dstJ;
		for (int j = dstJ; j < sizeJ; j++) {
			if (a[i1][j] < a[i1][minJ]) { minJ = j; }
		}
		if (minJ != dstJ) {
			for (int i = 0; i < sizeI; i++) {
				swap(a[i][minJ], a[i][dstJ]);
			}
			ans.push_back("C" + to_string(dstJ + 1) + " " + to_string(minJ + 1));
		}
	}
	for (int dstI = 0; dstI < sizeI; dstI++) {
		int minI = dstI;
		for (int i = dstI; i < sizeI; i++) {
			if (a[i][0] < a[minI][0]) { minI = i; }
		}
		if (minI != dstI) {
			for (int j = 0; j < sizeJ; j++) {
				swap(a[minI][j], a[dstI][j]);
			}
			ans.push_back("R" + to_string(dstI + 1) + " " + to_string(minI + 1));
		}
	}
	cout << (int)ans.size();
	for (const string& s : ans) { cout << s.c_str(); }
	return 0;
}