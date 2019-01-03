#include <iostream>
#include <fstream>
using namespace std;

double lag(int, double[], int, double);
double wiel(double[], double[], int, double);

void forSin();
void parabola();

int main() {
	/*double taby[3] = { 1,4,9 };
	double tabx[3] = { 1,2,3 };

	cout << "Suma "<<wiel(tabx, taby, 3, 7)<<endl;*/

	forSin();
	//parabola();

	//system("pause");
}

double lag(int k, double xs[], int n, double x) {
	double licznik{1};
	double mianownik{1};

	for (int i = 0; i < k; i++) {
		licznik *= x - xs[i];
		mianownik *= xs[k] - xs[i];
	}
	for (int i = k + 1; i < n; i++) {
		licznik *= x - xs[i];
		mianownik *= xs[k] - xs[i];
	}
	
	return licznik / mianownik;
}

double wiel(double xs[], double ys[], int n, double x) {
	double suma{ 0 };
	for (int i = 0; i < n; i++) {
		suma += lag(i,xs,n,x)*ys[i];
	}
	return suma;
}

void forSin() {
	ofstream plik;
	plik.open("dane.txt");

	double xs[] = {
		0,
		0.52359877559829887307710723054658,
		0.78539816339744830961566084581988,
		1.0471975511965977461542144610932,
		1.5707963267948966192313216916398,
		3.1415926535897932384626433832795
	};
	double ys[] = {
		0,
		0.5,
		0.70710678118654752440084436210485,
		0.86602540378443864676372317075294,
		1,0
	};
	//n=5

	for (double i = 0; i <= 3.142; i += 0.001) {
		plik << i << ";" << wiel(xs, ys, 6, i) << endl;
	}
	plik.close();
}

void parabola() {
	double tabx[] = { -2, 0 ,-1,-3};
	double taby[] = { 0, 4,1,1};

	cout << wiel(tabx, taby, 4, 0.647) << endl; //16: x=-6 x=2

}