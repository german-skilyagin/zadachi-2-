#include <iostream>
# include <cmath>

using namespace std;
int main () {

	int minut, hour;
	cin >> minut >> hour;
	cout << (abs(((hour % 12) * 30) - (6 * minut)));
	if (hour > 12){
		hour - hour - 12;
	}
	return 0;
	
}
