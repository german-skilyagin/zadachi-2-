#include <vector>
#include <string>
#include <cassert>
#include <iostream>
using namespace std;

int main() {
	vector<int> nPresses(128, -1);
	vector<int > button(128, -1);
	for (int line = 1; line <= 9; line++) {
		char buffer[40 + 1];
		cin >> buffer;
		string s(buffer);
		for (int i = 0; i < (int)s.size(); i++) {
			int c = s[i];
			nPresses[c] = i + 1;
			button[c] = line;
		}
	}
	char endl = 0;
	cin >> endl;
	assert(endl == '\n');
	char buffer[1000 + 1] = {};
	cin >> buffer;
	endl = '\n';
	cin >> endl;
	assert(endl == '\n');
	string s(buffer);

	const int lower = 1;
	const int upper = 2;
	const int first = 3;
	int state = first;
	int lastButton = 0;
	int count = 0;
	for (char c : s) {
		if (c == ' ') {
			count++;
			lastButton = 0;
			continue;
		}
		if (button[c] == lastButton) {
			count++;
		}
		if (c == '.' || c == '?' || c == '!') {
			count += nPresses[c];
			state = first;
		}
		else if ('a' <= c && c <= 'z') {
			count += nPresses[c];
			if (state == upper || state == first) {
				count++;
				state = lower;
			}
		}	
		else if ('A' <= c && c <= 'Z') {
			count += nPresses[c - 'A' + 'a'];
			if (state == lower) {
				count++;
				state = upper;
			}
			else if (state == first) {
				state = lower;
			}
			else {
				assert(state == upper);
			}
		}
		lastButton = button[c];
	}
	cout << count;
}