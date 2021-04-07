#include <iostream>

using namespace std; 

class Point {
public:
	int x, y;

	Point() {
		x = 0;
		y = 0;
		printf("Запуск конструктора по умолчанию у класса Point\n");
	}

	Point(int x, int y) {
		this->x = x;
		this->y = y;
		printf("Запуск конструктора c параметрами у класса Point\n");
		printf("Координаты точки (%d; %d)\n", x, y);
	}

	Point(const Point& p) {
		x = p.x;
		y = p.y;
		printf("Запуск конструктора копирования у класса Point\n");
		printf("Координаты точки (%d; %d)\n", x, y);
	}

	void move(int mx, int my) { 
		x += mx;
		y += my;
		printf("Запуск метода move у класса Point\n");
		printf("Новые координаты точки: (%d;%d)\n", x, y);
	}

	void reset();

	virtual ~Point() {
		printf("\nЗапуск деструктора у класса Point\n");
		printf("Последние координаты точки(%d;%d)\n", x, y);
	}
};

void Point::reset() {
	x = 0;
	y = 0;
	printf("Запуск метода reset у класса Point\n");
	printf("Координаты точки (%d; %d)\n", x, y);
}

class Point3D : public Point {
protected:
	int z;
public:
	Point3D() : Point() {
		z = 0;
		printf("Запуск конструктора по умолчанию у класса Point3D\n");
	}

	Point3D(int x, int y, int z) : Point(x, y) {
		this->z = z;
		printf("Запуск конструктора c параметрами у класса Point3D\n");
		printf("Координаты точки (%d;%d;%d)\n", x, y, z);
	}

	Point3D(const Point3D& p3D) {
		x = p3D.x;
		y = p3D.y;
		z = p3D.z;
		printf("Запуск конструктора копирования у класса Point3D\n");
		printf("Координаты точки (%d;%d;%d)\n", x, y, z);
	}
	void move(int mx, int my, int mz) { // Реализация метода в определении класса
		x += mx;
		y += my;
		z += mz;
		printf("Запуск метод move у класса Point3D\n");
		printf("Координаты точки (%d;%d;%d)\n", x, y, z);
	}
	~Point3D() {
		printf("\nЗапуск деструктора у класса Point3D\n");
		printf("Последние координаты точки (%d;%d;%d)\n", x, y, z);
	}
};

class Line {
public:
	Point* p1;
	Point* p2;

	Line() {
		p1 = new Point();
		p2 = new Point();
		printf("Запуск конструктора по умолчанию у класса Line\n");
		printf("Координаты точки p1(%d;%d) p2(%d;%d)\n", p1->x, p1->y, p2->x, p2->y);
	}

	Line(int x1, int y1, int x2, int y2) {
		p1 = new Point(x1, y1);
		p2 = new Point(x2, y2);
		printf("Запуск конструктора c параметрами у класса Line\n");
		printf("Координаты точки p1(%d;%d) p2(%d;%d)\n", p1->x, p1->y, p2->x, p2->y);
	}

	Line(const Line& l) {
		p1 = new Point(*(l.p1));
		p2 = new Point(*(l.p2));
		printf("Запуск конструктора копирования у класса Line\n");
		printf("Координаты точки p1(%d;%d) p2(%d;%d)\n", p1->x, p1->y, p2->x, p2->y);

	}

	void length_line() { 
		int a, b;
		double length;
		a = (p1->x) - (p2->x);
		b = (p1->y) - (p2->y);
		length = sqrt(a * a + b * b);
		printf("Координаты точек p1(%d;%d) p2(%d;%d)\n", p1->x, p1->y, p2->x, p2->y);
		printf("Длина линии = %.2f\n", length);

	}
	~Line() {
		printf("\nЗапуск деструктора у класса Line\n");
		printf("Координаты точки p1(%d;%d) p2(%d;%d)\n", p1->x, p1->y, p2->x, p2->y);
		delete p1;
		delete p2;
	}
};

int main()
{
	setlocale(0, "");
	printf("Взаимодействие с классом Point \n\n");
	{
		printf("Point t;\n");
		Point t;
		printf("\nt.move(8, 5);\n");
		t.move(8, 5);

		printf("\nPoint t1(2, 5);\n");
		Point t1(2, 5);

		printf("\nPoint t2(t1);\n");
		Point t2(t1);
		printf("\nt2.reset();\n");
		t2.reset();

		printf("\nPoint* t01 = new Point();\n");
		Point* t01 = new Point();

		printf("\nPoint* t02 = new Point(3, 6);\n");
		Point* t02 = new Point(3, 6);

		printf("\nPoint* t03 = new Point(*tochka02);\n");
		Point* t03 = new Point(*t02);

		printf("\ndelete tochka01;");
		delete t01;
		printf("\ndelete tochka02;");
		delete t02;
		printf("\n'delete tochka03;'");
		delete t03;
	}
	printf("Взаимодействие с классом Point3D \n\n");
	{
		printf("\nPoint3D p1;\n");
		Point3D p1;

		printf("\nPoint* p2 = new Point3D(1, 2, 3);\n");
		Point* p2 = new Point3D(1, 2, 3);

		printf("\np1.move(2, 4, 5);\n");
		p1.move(2, 4, 5);

		printf("\ndelete p2;");
		delete p2;
	}
}
