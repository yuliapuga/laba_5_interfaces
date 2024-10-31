/*2. Створити клас, що містить методи знаходження площі, периметра, радіуса вписаного і
описаного кола для рівностороннього, рівнобедреного, різностороннього та
прямокутного трикутників. Для різного типу трикутників передбачити відповідні
інтерфейси.*/

#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;

//Загальний клас-інтерфейс для рівностороннього трикутника
class I_Metods_For_Rivnostoronniy_Triangle {
protected:
	virtual const double getArea() const = 0;
	virtual const double getPerimeter() const = 0;
	virtual const double getRadius_of_circumscribed_circle() const = 0;
	virtual const double getRadius_of_inscribed_circle() const = 0;
	virtual void print() const = 0;
	virtual ~I_Metods_For_Rivnostoronniy_Triangle() = default;

};

//Загальний клас-інтерфейс для рівнобедренного трикутника
class I_Metods_For_Rivnobedrenniy_Triangle {
public:
	virtual const double getArea() const = 0;
	virtual const double getPerimeter() const = 0;
	virtual const double getRadius_of_circumscribed_circle() const = 0;
	virtual const double getRadius_of_inscribed_circle() const = 0;
	virtual void print() const = 0;
	virtual ~I_Metods_For_Rivnobedrenniy_Triangle() = default;

};

//Загальний клас-інтерфейс для різностороннього трикутника
class I_Metods_For_Riznostoronniy_Triangle {
public:
	virtual const double getArea() const = 0;
	virtual const double getPerimeter() const = 0;
	virtual const double getRadius_of_circumscribed_circle() const = 0;
	virtual const double getRadius_of_inscribed_circle() const = 0;
	virtual void print() const = 0;
	virtual ~I_Metods_For_Riznostoronniy_Triangle() = default;

};

//Клас для рівносторонніх трикутників
class Rivnostoronniy_Triangle : public I_Metods_For_Rivnostoronniy_Triangle {
	double m_a;
public:
	Rivnostoronniy_Triangle(double side) {
		if (side > 0) {
			m_a = side;
		}
		else {
			m_a = 0;
			cout << "Значення присвоєне для сторони рівностороннього трикутника = 0 " << endl;
		}
	}
	virtual const double getArea() const {
		return (sqrt(3) / 4) * pow(m_a, 2);
	}

	virtual const double getPerimeter() const {
		return 3 * m_a;
	};

	virtual const double getRadius_of_circumscribed_circle() const {
		return m_a / sqrt(3);
	}

	virtual const double getRadius_of_inscribed_circle() const {
		return m_a / (2 * sqrt(3));
	}

	virtual void print() const {
		cout << "Сторона рівностороннього трикутника: " << m_a << endl;
		cout << "Площа рівностороннього трикутника: " << getArea() << endl;
		cout << "Периметр рівностороннього трикутника: " << getPerimeter() << endl;
		cout << "Радіус оописаного кола рівностороннього трикутника: " << getRadius_of_circumscribed_circle() << endl;
		cout << "Радіус вписаного кола рівностороннього трикутника: " << getRadius_of_inscribed_circle() << endl;
	}


};

//Клас для рівносторонніх трикутників
class Rivnobedrenniy_Triangle : public I_Metods_For_Rivnobedrenniy_Triangle {
	double m_a, m_base;
public:
	Rivnobedrenniy_Triangle(double side, double base) {
		if ((side > 0 && base > 0) and (2 * side > base)) {
			m_a = side;
			m_base = base;
		}
		else {
			m_a = 0;
			m_base = 0;
			cout << "Значення присвоєні для сторін рівнобедренного трикутника = 0 " << endl;
		}
	}
	virtual const double getArea() const {
		double height = sqrt(m_a * m_a - 0.25 * m_base * m_base);
		return 0.5 * m_a * height;

	}

	virtual const double getPerimeter() const {
		return 2 * m_a + m_base;
	};

	virtual const double getRadius_of_circumscribed_circle() const {
		return m_a * m_a / (sqrt(4 * m_a * m_a - m_base * m_base));
	}

	virtual const double getRadius_of_inscribed_circle() const {
		return 0.5 * m_base * sqrt((2 * m_a - m_base) / (2 * m_a + m_base));
	}

	virtual void print() const {
		cout << "Сторони рівнобедренного трикутника: " << m_a << " " << m_base << " " << m_a << endl;
		cout << "Площа рівнобедренного трикутника: " << getArea() << endl;
		cout << "Периметр рівнобедренного трикутника: " << getPerimeter() << endl;
		cout << "Радіус оописаного кола рівнобедренного трикутника: " << getRadius_of_circumscribed_circle() << endl;
		cout << "Радіус вписаного кола рівностороннього трикутника: " << getRadius_of_inscribed_circle() << endl;
	}

};

//Клас для рівносторонніх трикутників
class Riznostoronniy_Triangle : public I_Metods_For_Riznostoronniy_Triangle {
	double m_a, m_b, m_c;
public:
	Riznostoronniy_Triangle(double firstside, double secondside, double thirdside) {
		if ((firstside > 0 && secondside > 0 && thirdside) and (firstside + secondside > thirdside && firstside + thirdside > secondside && secondside + thirdside > firstside))
		{
			m_a = firstside;
			m_b = secondside;
			m_c = thirdside;
		}
		else {
			m_a = 0;
			m_b = 0;
			m_c = 0;
			cout << "Значення присвоєні для сторін рівнобедренного трикутника (введено некоректні сторони) = 0 " << endl;
		}
	}
	virtual const double getArea() const {
		double p = 0.5 * (m_a + m_b + m_c);
		return sqrt(p * (p - m_a) * (p - m_b) * (p - m_c));

	}

	virtual const double getPerimeter() const {
		return m_a + m_b + m_c;
	};

	virtual const double getRadius_of_circumscribed_circle() const {
		return m_a * m_b * m_c / (4 * getArea());
	}

	virtual const double getRadius_of_inscribed_circle() const {
		double p = 0.5 * (m_a + m_b + m_c);
		return sqrt((p - m_a) * (p - m_b) * (p - m_c) / p);
	}

	virtual void print() const {
		cout << "Сторони різностороннього трикутника: " << m_a << " " << m_b << " " << m_c << endl;
		cout << "Площа різностороннього трикутника: " << getArea() << endl;
		cout << "Периметр різностороннього трикутника: " << getPerimeter() << endl;
		cout << "Радіус описаного кола різностороннього трикутника: " << getRadius_of_circumscribed_circle() << endl;
		cout << "Радіус вписаного кола різностороннього трикутника: " << getRadius_of_inscribed_circle() << endl;
	}

};


//Тестування 
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Rivnostoronniy_Triangle triangle1(12);
	Rivnobedrenniy_Triangle triangle2(12, 6);
	Riznostoronniy_Triangle triangle3(3, 4, 5);
	triangle1.print();
	triangle2.print();
	triangle3.print();
}
