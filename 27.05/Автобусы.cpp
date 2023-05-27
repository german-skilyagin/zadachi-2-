#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

const int INF = 1000000000;
int main() {
	int n, start, finish, r;
	cin >> n >> start >> finish;
	vector<vector<tuple<int, int, int>>>g(n + 1);
	cin >> r;
	for (int i = 0; i < r; i++) {
		int start, start_time, finish, finish_time;
		cin >> start >> start_time >> finish >> finish_time;
		g[start].push_back(make_tuple(start_time, finish, finish_time));
	}
	vector<int> time(n + 1, INF);
	time[start] = 0;
	vector<bool> used(n + 1);
	int min_time = 0;
	int min_village = start;
	while (min_time < INF) {
		used[min_village] = true;
		int start = min_village;
		for (auto j : g[start]) {
			int start_time = get<0>(j);
			int finish = get<1>(j);
			int finish_time = get<2>(j);
			if ((time[start] <= start_time) && (finish_time < time[finish])) { time[finish] = finish_time; }
		}
		min_time = INF;
		for(int j = 0; j < n; ++j){
			if ((!used[j]) && (time[j] < min_time)) { min_time = time[j]; min_village = j; }
		}
	}
	if (time[finish] == INF) { cout << -1 << endl; }
	else { cout << time[finish] << endl; }
}