#include <iostream>
#include <Windows.h>
#include <string>

class Fraction {
private:
	int numerator_; // числитель
	int denominator_; // знаменатель

	int nod(int x, int y) {
		if (x == y) return x;
		x > y ? nod(x - y, y) : nod(x, y - x);
	}
	Fraction cut() {
		int a = numerator_ > 0 ? numerator_ : (numerator_ * -1);
		int b = denominator_ > 0 ? denominator_ : (denominator_ * -1);
		int x = nod(a, b);

		return Fraction(numerator_ / x, denominator_ / x);
	}
public:
	Fraction(int numerator, int denominator) {
		numerator_ = numerator;
		denominator_ = denominator;
	}

	Fraction operator	+	(Fraction other) {
		int numberUp = numerator_ * other.denominator_ + other.numerator_ * denominator_;
		int numberDown = denominator_ * other.denominator_;

		return Fraction(numberUp, numberDown).cut();
	}

	Fraction operator	-	(Fraction other) {
		int numberUp = numerator_ * other.denominator_ - other.numerator_ * denominator_;
		int numberDown = denominator_ * other.denominator_;

		return Fraction(numberUp, numberDown).cut();
	}

	Fraction operator	*	(Fraction other) {
		// сократить дробь
		return Fraction(numerator_ * other.numerator_, denominator_ * other.denominator_).cut();
	}

	Fraction operator	/	(Fraction other) {
		// сократить дробь
		return Fraction(numerator_ * other.denominator_, denominator_ * other.numerator_).cut();
	}

	Fraction& operator	++	() {
		numerator_ = numerator_ + denominator_;
		return *this;
	}

	Fraction operator	++	(int) {
		Fraction temp = *this;
		(*this).numerator_ = numerator_ + denominator_;
		return temp;
	}

	Fraction& operator	--	() {
		numerator_ = numerator_ - denominator_;
		return *this;
	}

	Fraction operator	--	(int) {
		Fraction temp = *this;
		(*this).numerator_ =  numerator_ - denominator_;
		return temp;
	}

	std::string print() { return std::to_string(numerator_) + "/" + std::to_string(denominator_); }
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int x1, x2;
	std::cout << "Введите числитель дроби 1: ";
	std::cin >> x1;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> x2;

	int y1, y2;
	std::cout << "Введите числитель дроби 1: ";
	std::cin >> y1;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> y2;


	Fraction f1(x1, x2);
	Fraction f2(y1, y2);

	std::cout << f1.print() + " + " + f2.print() + " = " + (f1 + f2).print() << std::endl;
	std::cout << f1.print() + " - " + f2.print() + " = " + (f1 - f2).print() << std::endl;
	std::cout << f1.print() + " * " + f2.print() + " = " + (f1 * f2).print() << std::endl;
	std::cout << f1.print() + " / " + f2.print() + " = " + (f1 / f2).print() << std::endl;
	// не понимаю в чём тут проблема ... Если я объединяю 2-е строчки ниже в одну,
	// то у меня f1.print() выдаёт значение, будто я написал ++f1.print()
	// Почему так происходит, не очень понимаю =(
	std::cout << "++" + f1.print() + " * " + f2.print() + " = ";
	std::cout << (++f1 * f2).print() << std::endl;
	std::cout << "Значение дроби 1 = " + f1.print() << std::endl;
	// тут ситуация аналогичная ...
	std::cout << f1.print() + "-- * " + f2.print() + " = ";
	std::cout << (f1-- * f2).print() << std::endl;
	std::cout << "Значение дроби 1 = " + f1.print() << std::endl;

	return 0;
}