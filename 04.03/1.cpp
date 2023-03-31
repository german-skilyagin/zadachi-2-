#include <iostream>
using namespace std;
struct Point3d {
	int x;
	int y;
	int z;
	Point3d(int value_x, int value_y, int value_z) {
		x = value_x;
		y = value_y;
		z = value_z;
	}
	void prt() {
		cout << "X =" << x << endl << "Y=" << y << endl << "Z=" << z << endl;
	}

};

struct Point3D
{
	int x;
	int y;
	int z;
	Point3D(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	void Print() {
		cout << "X =" << x << endl << "Y=" << y << endl << "Z=" << z << endl;
	}
};
int main() {
	Point3D a(7, 7, 7);
	a.Print();
	Point3d b(11, 12, 12121);
	b.prt();
	return 0;
}