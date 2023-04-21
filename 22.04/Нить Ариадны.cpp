#include <queue>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct Pos {
	int i;
	int j;
	Pos(const int i, const int j)
		:i(i)
		,j(j)
	{}
};

bool operator < (const Pos &left, const Pos &right) {
	if (left.i != right.i) { return left.i < right.i; }
	else { return left.j < right.j; }
}

int main() {
	char buffer[200 + 1] = {};
	cin >> buffer;
	string s(buffer);
	set<Pos> path;	
	int i = 0; int j = 0;
	path.insert(Pos(i, j));
	for (char c : s) {
		if (c == 'E') {
			j++;
			path.insert(Pos(i, j));
			j++;
			path.insert(Pos(i, j));
		}
		else if (c == 'W') {
			j--;
			path.insert(Pos(i, j));
			j--;
			path.insert(Pos(i, j));
		}
		else if (c == 'N') {
			i--;
			path.insert(Pos(i, j));
			i--;
			path.insert(Pos(i, j));
		}
		else if (c == 'S') {
			i++;
			path.insert(Pos(i, j));
			i++;
			path.insert(Pos(i, j));
		}
		else { throw 1; }
	}
	map<Pos, int> len;
	queue<Pos> q;
	q.push(Pos(0, 0));
	len[Pos(0, 0)] = 0;
	while (!q.empty()) {
		Pos cur = q.front();
		q.pop();
		for (int di = -1; di <= 1; di++) {
			for (int dj = -1; dj <= 1; dj++) {
				if (di * di + dj * dj == 1) {
					Pos next(cur.i + di, cur.j + dj);
					if (path.count(next) == 1 && len.find(next) == len.end()) { q.push(next); len[next] = len[cur] + 1; }
				}
			}
		}
	}
	Pos cur(i, j);
	bool odd = 1;
	while (1) {		
		if (cur.i == 0 && cur.j == 0) { break; }		
		Pos n(cur.i - 1, cur.j);
		Pos s(cur.i + 1, cur.j);
		Pos e(cur.i, cur.j + 1);
		Pos w(cur.i, cur.j - 1);
		char ans;
		if (path.count(n) && len[n] < len[cur]) { cur = n; ans = 'N'; }
		else if (path.count(e) && len[e] < len[cur]) { cur = e; ans = 'E'; }
		else if (path.count(s) && len[s] < len[cur]) { cur = s; ans = 'S'; }
		else if (path.count(w) && len[w] < len[cur]) { cur = w; ans = 'W'; }
		else { throw 1; }
		if (odd) { cout << ans; }
			odd = !odd;
	}
	return 0;
}