#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool GreyCode(vector<int>& mass) {
    int n = mass.size();
    for (int i = 0; i < n; i++) {
        int diff = mass[i] ^ mass[(i + 1) % n];
        if ((diff & (diff - 1)) != 0) { return false; }
    }
    return true;
}

int main() {
    int num;
    cin >> num;
    vector<int> mass(1 << num);
    for (int i = 0; i < (1 << num); i++) { cin >> mass[i]; }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int ch_1, ch_2;
        cin >> ch_1 >> ch_2;
        swap(mass[ch_1], mass[ch_2]); 
        if (GreyCode(mass)) { cout << "YES" << endl; }
        else { cout << "NO" << endl; }
    }
    return 0;
}