#include <iostream>

using namespace std;
int main () {

	int number = 0;
    int summa = 0;
	while (number < 1000) {
		if (number % 3 == 0 || number % 5 == 0) {
			summa = summa + number;
		}
		number ++;
	}
	cout << summa;
	return 0;



	
}
