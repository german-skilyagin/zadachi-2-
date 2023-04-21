#include <iostream>
#include <vector>
using namespace std;

bool isM(int n, int k, int mk, vector<bool>& mb) {
    if (mk < 1 || mk > k) { return false; }
    if (n - mk == 1) { return false; }
    if (n - mk == 0) { return true; }
    if (mb[n - mk]) { return true; }
    for (int i = 1; i <= k; i++) {
        if (!isM(n - mk, k, i, mb)) { mb[n - mk] = true; return true; }
    }
    mb[n - mk] = false;
    return false;
}

int main() {
    int n, k, p;
    cin >> n >> k >> p;
    vector<int> mass(p);
    vector<bool> mb(n + 1, false);
    for (int i = 0; i < p; i++) {
        int mk;
        cin >> mk;
        mass[i] = (isM(n, k, mk, mb) ? 1 : 0);
    }
    for (int i = 0; i < p; i++) {
        if (mass[i]) { cout << "T" << endl; }
        else { cout << "F" << endl; }
    }
    return 0;
}