#include<vector>
#include<iostream>
#include<complex>
#include<algorithm>
#include<cmath>
using namespace std;

int NOD(int a, int b)
{
    while (a > 0 && b > 0)
        if (a > b)
            a %= b;
        else
            b %= a;
    return a + b;
}

int main() {
    long long n; 
    cin >> n;
    vector<complex<int>> k(n);
    for (int i = 0; i < n; i++) {
        int x;
        int y;
        cin >> x >> y;
        k[i] = { x, y };
    }
    k.push_back(k[0]);
    int m = 0;
    int p = 0;
    for (int i = 0; i < n; i++) {
        complex<int> x = k[i], y = k[i + 1];
        m += (conj(x) * y).imag();
        complex<int> z = y - x;
        int g = NOD(z.real(), z.imag());
        p += abs(g);
    }
    int out = (abs(m) - p + 2)/2;
    cout << out << ' ' << p << endl;
}