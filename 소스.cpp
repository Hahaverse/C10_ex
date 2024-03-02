#include <iostream>
using namespace std;

class Fraction {
private:
	int numer;
	int denom;

public:
	Fraction();
	Fraction(int n, int d);
	~Fraction();

	Fraction operator+(Fraction& c) {
		Fraction f(0, 0);
		Fraction f1(this->numer, this->denom);
		Fraction f2(c.numer, c.denom);
		int x;
		while (f2.denom != 0) {
			x = f1.denom % f2.denom;
			f1.denom = f2.denom;
			f2.denom = x;
		}
		f.denom = this->denom * c.denom / f1.denom;

		f1.numer = f1.numer * (f.denom / this->denom);
		f2.numer = f2.numer * (f.denom / c.denom);
		f.numer = f1.numer + f2.numer;
		return f;
	}
	Fraction operator*(Fraction& c) {
		Fraction f(0, 0);
		f.numer = this->numer * c.numer;
		f.denom = this->denom * c.denom;
		return f;
	}

	friend ostream& operator<<(ostream& oc, const Fraction& f);
};
Fraction::Fraction() {
	numer = 0;
	denom = 0;
}
Fraction::Fraction(int n, int d) {
	numer = n;
	denom = d;
}
Fraction::~Fraction() {}
ostream& operator<<(ostream& os, const Fraction& f) {
	os << f.numer << "/" << f.denom << endl;
	return os;
}

int main() {
	Fraction a(3, 8);
	Fraction b(1, 8);
	Fraction c = a + b;
	Fraction d = a * b;

	cout << a;
	cout << b;
	cout << c;
	cout << d;
}