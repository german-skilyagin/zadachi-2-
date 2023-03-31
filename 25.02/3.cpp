#include <iostream>
using namespace std;
extern int n = 10;
extern int m = 100;
int main() {
	int k = n;
	n = m;
	m = k;


	cout << n << " "<< m;  