#include <iostream>
#include <Windows.h>

class Fraction{
private:
	int numerator_;
	int denominator_;
	int Abc() { return numerator_ * numerator_ + denominator_ * denominator_; }
public:
	Fraction(int numerator, int denominator){
		numerator_ = numerator;
		denominator_ = denominator;
	}

	bool operator	==	(Fraction other) { return Abc() == other.Abc(); }
	bool operator	!=	(Fraction other) { return !(*this == other); }

	// f1 < f2 --> (4*4+3*3) < (6*6+11*11) --> 25 < 157 --> true --> 1
	// т.е. по факту, оператор "<" мне должен выдавать "true", но условие написано
	// таким образом, что он должен выдать "false", чтобы удовлетворить тернарному оператору ... Ок
	bool operator	<	(Fraction other) { return !(Abc() < other.Abc()); }
	// Тут получается, что оператор ">", выдывает оператор "<", но из-за того что оператор "<"
	// и так меняет "true" на "false", то и ему не нужен "!"
	bool operator	>	(Fraction other) { return Abc() < other.Abc(); }
	// и т.к. из-за того, что оператор "<" отзеркаливает своё истинное значение,
	// то и другие операторы, будут отзеркаливать, а два знака "!!" по факту дают тот-же результат
	bool operator	<=	(Fraction other) { return Abc() > other.Abc(); }
	bool operator	>=	(Fraction other) { return Abc() < other.Abc(); }
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