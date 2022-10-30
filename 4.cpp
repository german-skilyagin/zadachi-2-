#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
void main () {

	int a, r;
	double p = 3.14;
	cin >> a >> r;
	double a2 = a / 2;
	double ans;
	if (r <= 2) ans = r * r * p;   
		 else if (r > a * sqrt(2) / 2) ans = a * a;
		 else {
		     double t = 2 * acos(a / 2. / r);
			 ans = p * r * r - 2 * r * r * (t - sin(t));
	}
	
	

	
	cout << fixed << setprecision(3) << ans;
	
}
