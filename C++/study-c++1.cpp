#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	double length, width, hight;
	double ml;
	double y,m;
	cout << "input length,width,hight"<<endl;
	cin >> length >> width >> hight;
	m = sqrt(125);
	y = sqrt(125 - 6.25)*2;
	ml = sqrt(pow(53, 2) + pow((25 - y / 2), 2));
	cout << y<<"   "<<ml << endl;
}