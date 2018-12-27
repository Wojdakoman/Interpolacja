#include <iostream>
#include <fstream>
using namespace std;

double lag(int, double[], int, double);
double wiel(double[], double[], int, double);

void forSin();

int main() {
	/*double tabx[3] = { 1,4,9 };
	double taby[3] = { 1,2,3 };

	cout << "Suma "<<wiel(tabx, taby, 3, 7)<<endl;*/

	forSin();

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

	double xs[] = {0,0.5236,0.7854,1.0472,1.5708};
	double ys[] = { 0,0.5,0.7071,0.866,1 };
	//n=5

	for (double i = -1.57; i <= 2*3.14; i += 0.01) {
		plik << i << ";" << wiel(xs, ys, 5, i) << endl;
	}
	plik.close();
}