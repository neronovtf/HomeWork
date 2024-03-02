#include <iostream>
#include <Windows.h>

class Fraction{
private:
	int numerator_;
	int denominator_;
	int arr[2] = { 0, 0 };
	void Ac(Fraction other) {
		arr[0] = numerator_ * other.denominator_;
		arr[1] = denominator_ * other.numerator_;
	}
public:
	Fraction(int numerator, int denominator){
		numerator_ = numerator;
		denominator_ = denominator;
	}

	bool operator	==	(Fraction other) {
		Ac(other);
		return arr[0] == arr[1];
	}
	bool operator	!=	(Fraction other) { return !(*this == other); }

	bool operator	<	(Fraction other) {
		Ac(other);
		return arr[0] < arr[1];
	}
	bool operator	>	(Fraction other) {
		Ac(other);
		return arr[0] > arr[1];
	}
	bool operator	<=	(Fraction other) {
		Ac(other);
		return !(arr[0] > arr[1]);
	}
	bool operator	>=	(Fraction other) {
		Ac(other);
		return !(arr[0] < arr[1]);
	}
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';

	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';

	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';

    return 0;
}