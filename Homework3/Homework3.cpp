// HW3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
#include <string>
constexpr auto Pi = 3.14159265358979323846;

//Задание 1 

/*
Создать абстрактный класс Figure (фигура). Его наследниками являются классы Parallelogram (параллелограмм)
и Circle (круг). Класс Parallelogram — базовый для классов Rectangle (прямоугольник), Square (квадрат),
Rhombus (ромб). Для всех классов создать конструкторы. Для класса Figure добавить чисто виртуальную функцию
area() (площадь). Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.
*/
void Task1() {

	class Figure {

	public:
		virtual double area() {
			return 0;
		};
	};

	class Parallelogram : virtual Figure {
	private:
		double height, width;
	public:
		Parallelogram() {
			height = 0;
			width = 0;
		};

		double area() {

			cout << "Введите высоту: ";
			cin >> height;
			cout << "Введите ширину: ";
			cin >> width;
			return height * width;
		}

	};

	class Circle : virtual Figure {
	private:

		double m_radius = 0;

	public:
		Circle(int radius = 0) : m_radius(radius) {};
		double area() {

			cout << "\n\nКруг :\nВведите радиус круга: ";
			cin >> m_radius;
			return Pi * pow(m_radius, 2);
		}

	};

	class Rectangle : Parallelogram, virtual Figure {
	private:

		double height, width;

	public:
		Rectangle() {
			height = 0;
			width = 0;
		};
		double area() {

			cout << "\n\nТреугольник :\nВведите высоту треугольника: ";
			cin >> height;
			cout << "Введите ширину треугольника: ";
			cin >> width;
			return 0, 5 * height * width;
		}

	};

	class Square : Parallelogram, virtual Figure {
	private:

		double height;

	public:
		Square() {
			height = 0;
		};
		double area() {

			cout << "\n\nКвадрат :";
			return Parallelogram::area();
		}
	};

	class Rhombus : Parallelogram, virtual Figure {
	private:

		double height, width;

	public:
		Rhombus() {
			height = 0;
			width = 0;
		};
		double area() {

			cout << "\n\nРомб :\n";

			return Parallelogram::area();
		}
	};

	setlocale(LC_ALL, "Russian");
	Parallelogram parallelogram;
	Circle circle;
	Rectangle rectangle;
	Square square;
	Rhombus rhombus;
	cout << "Площадь параллелограма - " << parallelogram.area();
	cout << "Площадь круга - " << circle.area();
	cout << "Площадь треугольника - " << rectangle.area();
	cout << "Площадь квадрата - " << square.area();
	cout << "Площадь ромба - " << rhombus.area();


}

//Задание 2

/*
Создать класс Car (автомобиль) с полями company (компания) и model (модель). Классы-наследники:
PassengerCar (легковой автомобиль) и Bus (автобус). От этих классов наследует класс Minivan (минивэн).
Создать конструкторы для каждого из классов, чтобы они выводили данные о классах. Создать объекты для
каждого из классов и посмотреть, в какой последовательности выполняются конструкторы.
Обратить внимание на проблему «алмаз смерти».
*/
void Task2() {
	class Car
	{
	private:
		string m_company;
		string m_model;

	public:
		Car() {

			cout << "Car constructor" << endl;
		}
		Car(string company, string model)
			: m_company(company), m_model(model)
		{
		}
		string getCompany() const {
			return m_company;
		}
		string getModel() const {
			return m_model;
		}
		~Car() {
			cout << "~Car destructor" << endl;
		}
	};

	class PassengerCar : public virtual Car {

	public:
		string PC_colour;
		PassengerCar() {
			cout << "PassengerCar constructor" << endl;
		}
		PassengerCar(string colour)
			: PC_colour(colour)
		{ }
		string getPassengerCarColour() const {
			return PC_colour;
		}
		~PassengerCar() {
			cout << "~PassengerCar destructor" << endl;
		}
	};

	class Bus : public virtual Car {

	public:
		string B_colour;
		Bus() {
			cout << "Bus constructor" << endl;
		}
		Bus(string colour)
			: B_colour(colour)
		{ }
		string getBusColour() const {
			return B_colour;
		}
		~Bus() {
			cout << "~Bus destructor" << endl;
		}

	};

	class Minivan : public PassengerCar, public Bus {
	private:
		int m_MaxPassenger = 0;
	public:

		Minivan() {
			cout << "Minivan constructor" << endl;
		}
		Minivan(int MaxPassenger)
			: m_MaxPassenger(MaxPassenger) {
		}
		int getMaxPassenger() const {
			return m_MaxPassenger;
		}
		~Minivan() {
			cout << "~Minivan destructor" << endl;
		}

	};


	Car volkswagen("Volkswagen", "Golf");
	PassengerCar PassengerCarcolour("Black");
	Bus Buscolour("Blue");
	Minivan MaxPassenger(560);

	cout << "\n\nCar company - " << volkswagen.getCompany() << " \nCar model - " << volkswagen.getModel() << endl;
	cout << "Passenger car colour - " << PassengerCarcolour.getPassengerCarColour() << endl;
	cout << "Bus colour - " << Buscolour.getBusColour() << endl;
	cout << "Max Passenger - " << MaxPassenger.getMaxPassenger() << "\n\n\n";

}

//Задание 3

/*
Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 9/2).
Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить:
математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
унарный оператор (-)
логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
Примечание: Поскольку операторы < и >=, > и <= — это логические противоположности, попробуйте перегрузить один через другой.
Продемонстрировать использование перегруженных операторов.

*/

void Task3() {
	class Fraction {
	private:
		int numerator;
		int denominator;

	public:
		Fraction() : numerator(1), denominator(1) {
		}

		Fraction(const int m_numerator, const int m_denominator) {
			numerator = m_numerator;
			if (m_denominator)
				denominator = m_denominator;
			else {
				std::cout << "Error, cannot be divided by 0";
			}
		}

		auto operator+(Fraction& fraction) const -> Fraction
		{
			Fraction result;
			if (denominator == fraction.denominator) {
				result.denominator = denominator;
				result.numerator = numerator + fraction.numerator;
			}
			else {
				result.denominator = denominator * fraction.denominator;
				result.numerator = (numerator * fraction.denominator) + (fraction.numerator * denominator);
			}
			return result;
		}

		auto operator-(Fraction& fraction) const -> Fraction
		{
			Fraction result;
			if (denominator == fraction.denominator) {
				result.denominator = denominator;
				result.numerator = numerator - fraction.numerator;
			}
			else {
				result.denominator = denominator * fraction.denominator;
				result.numerator = (fraction.denominator * numerator) - (fraction.numerator * denominator);
			}
			return result;
		}

		auto operator*(Fraction& fraction) const -> Fraction
		{
			Fraction result;
			result.numerator = numerator * fraction.numerator;
			result.denominator = denominator * fraction.denominator;
			return result;
		}

		Fraction operator/(Fraction& fraction) const
		{
			const auto result_1 = Fraction(fraction.denominator, fraction.numerator);
			auto result_2 = Fraction(numerator, denominator);
			const Fraction res = result_1 * result_2;
			return res;
		}

		bool operator== (const Fraction& fraction) const {
			return fraction.numerator == numerator && fraction.denominator == denominator;
		}

		bool operator!= (const Fraction& fraction) const {
			return !(*this == fraction);
		}

		bool operator> (const Fraction& fraction) const {
			if (fraction.denominator == denominator) {
				return fraction.denominator < denominator;
			}
			else {
				return (fraction.denominator * numerator) > (fraction.numerator * denominator);
			}
		}

		bool operator<= (const Fraction& fraction) const {
			return !(*this > fraction);
		}

		bool operator< (const Fraction& fraction) const {
			if (fraction.denominator == denominator) {
				return fraction.denominator > denominator;
			}
			else {
				return (fraction.denominator * numerator) < (fraction.numerator * denominator);
			}
		}

		bool operator>= (const Fraction& fraction) const {
			return !(*this < fraction);
		}

		void print() const {
			std::cout << numerator << "/" << denominator << "\n";
		}
	};
	const Fraction d1(3, 0);
	d1.print();

	Fraction d2(9, 5);
	d2.print();

	const Fraction result_1 = d1 + d2; std::cout << "+: ";
	result_1.print();

	const Fraction result_2 = d1 - d2; std::cout << "-: ";
	result_2.print();

	const Fraction result_3 = d1 * d2; std::cout << "*: ";
	result_3.print();

	const Fraction result_4 = d1 / d2; std::cout << "/: ";
	result_4.print();

	const int x = (d1 == d2);
	std::cout << "==: " << x << "\n";
	const int y = (d1 != d2);
	std::cout << "!=: " << y << "\n";

	const int n = d1 > d2;
	std::cout << ">: " << n << "\n";
	const int h = d1 <= d2;
	std::cout << "<=: " << h << "\n";

	const int m = d1 < d2;
	std::cout << "<: " << m << "\n";
	const int g = d1 >= d2;
	std::cout << ">=: " << g << "\n";
}




int main() {

	//Task1();
	//Task2();
	Task3();
	return 0;
}
//Задание 4

/*Создать класс Card, описывающий карту в игре БлэкДжек.У этого класса должно быть три поля :
масть, значение карты и положение карты(вверх лицом или рубашкой).
Сделать поля масть и значение карты типом перечисления(enum).Положение карты - тип bool.
Также в этом классе должно быть два метода :
метод Flip(), который переворачивает карту, т.е.если она была рубашкой вверх, то он ее поворачивает лицом вверх, и наоборот.
метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.*/



//class Card {
//
//public:
//	//значение карты
//	enum Rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
//	//масть
//	enum Suit { CLUBS, DIAMONDS, HERTS, SPADES };
//	Card(Rank r = ACE, Suit s = SPADES, bool ifu = true);
//	//возвращает значение карты от 1 до 11
//	int getValue() const;
//	//переворачивает карту лицом вверх и наоборот
//	void Flip();
//private:
//	Rank m_rank;
//	Suit m_suit;
//	bool m_isFaceUp;
//};
//
//Card::Card(Rank r, Suit s, bool ifu) : m_rank(r), m_suit(s), m_isFaceUp(ifu) {
//}
//
//int Card::getValue() const {
//	//усли карта лицом вниз, то ее значение равно 0
//	int value = 0;
//	if (m_isFaceUp) {
//		//значение равно числу указанному на карте
//		value = m_rank;
//		//значение равно 10 для открытых карт
//		if (value > 10)
//			value = 10;
//	}
//	return value;
//}
//
//void Card::Flip() {
//	//меняет значение положения карты на противоположный
//	m_isFaceUp = !m_isFaceUp;
//}