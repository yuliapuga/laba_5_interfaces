/*2. �������� ����, �� ������ ������ ����������� �����, ���������, ������ ��������� �
��������� ���� ��� ���������������, �������������, ��������������� ��
������������ ����������. ��� ������ ���� ���������� ����������� �������
����������.*/

#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;

//��������� ����-��������� ��� ��������������� ����������
class I_Metods_For_Rivnostoronniy_Triangle {
protected:
	virtual const double getArea() const = 0;
	virtual const double getPerimeter() const = 0;
	virtual const double getRadius_of_circumscribed_circle() const = 0;
	virtual const double getRadius_of_inscribed_circle() const = 0;
	virtual void print() const = 0;
	virtual ~I_Metods_For_Rivnostoronniy_Triangle() = default;

};

//��������� ����-��������� ��� �������������� ����������
class I_Metods_For_Rivnobedrenniy_Triangle {
public:
	virtual const double getArea() const = 0;
	virtual const double getPerimeter() const = 0;
	virtual const double getRadius_of_circumscribed_circle() const = 0;
	virtual const double getRadius_of_inscribed_circle() const = 0;
	virtual void print() const = 0;
	virtual ~I_Metods_For_Rivnobedrenniy_Triangle() = default;

};

//��������� ����-��������� ��� ��������������� ����������
class I_Metods_For_Riznostoronniy_Triangle {
public:
	virtual const double getArea() const = 0;
	virtual const double getPerimeter() const = 0;
	virtual const double getRadius_of_circumscribed_circle() const = 0;
	virtual const double getRadius_of_inscribed_circle() const = 0;
	virtual void print() const = 0;
	virtual ~I_Metods_For_Riznostoronniy_Triangle() = default;

};

//���� ��� ������������ ����������
class Rivnostoronniy_Triangle : public I_Metods_For_Rivnostoronniy_Triangle {
	double m_a;
public:
	Rivnostoronniy_Triangle(double side) {
		if (side > 0) {
			m_a = side;
		}
		else {
			m_a = 0;
			cout << "�������� �������� ��� ������� ��������������� ���������� = 0 " << endl;
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
		cout << "������� ��������������� ����������: " << m_a << endl;
		cout << "����� ��������������� ����������: " << getArea() << endl;
		cout << "�������� ��������������� ����������: " << getPerimeter() << endl;
		cout << "����� ���������� ���� ��������������� ����������: " << getRadius_of_circumscribed_circle() << endl;
		cout << "����� ��������� ���� ��������������� ����������: " << getRadius_of_inscribed_circle() << endl;
	}


};

//���� ��� ������������ ����������
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
			cout << "�������� ������� ��� ����� �������������� ���������� = 0 " << endl;
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
		cout << "������� �������������� ����������: " << m_a << " " << m_base << " " << m_a << endl;
		cout << "����� �������������� ����������: " << getArea() << endl;
		cout << "�������� �������������� ����������: " << getPerimeter() << endl;
		cout << "����� ���������� ���� �������������� ����������: " << getRadius_of_circumscribed_circle() << endl;
		cout << "����� ��������� ���� ��������������� ����������: " << getRadius_of_inscribed_circle() << endl;
	}

};

//���� ��� ������������ ����������
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
			cout << "�������� ������� ��� ����� �������������� ���������� (������� ��������� �������) = 0 " << endl;
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
		cout << "������� ��������������� ����������: " << m_a << " " << m_b << " " << m_c << endl;
		cout << "����� ��������������� ����������: " << getArea() << endl;
		cout << "�������� ��������������� ����������: " << getPerimeter() << endl;
		cout << "����� ��������� ���� ��������������� ����������: " << getRadius_of_circumscribed_circle() << endl;
		cout << "����� ��������� ���� ��������������� ����������: " << getRadius_of_inscribed_circle() << endl;
	}

};


//���������� 
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