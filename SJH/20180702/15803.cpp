#include <iostream>

using namespace std;
using uint = unsigned int;

const double VERTICAL = 999999.0;

int main(void)
{
	int x1, y1;
	int x2, y2;
	int x3, y3;
	
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;


	double delta1 = (x2 - x1) == 0.0 ? VERTICAL : double(y2 - y1) / double(x2 - x1);
	double delta2 = (x3 - x1) == 0.0 ? VERTICAL : double(y3 - y1) / double(x3 - x1);


	if (delta1 == delta2)
		cout << "WHERE IS MY CHICKEN?" << endl;
	else
		cout << "WINNER WINNER CHICKEN DINNER!" << endl;

	return 0;
}