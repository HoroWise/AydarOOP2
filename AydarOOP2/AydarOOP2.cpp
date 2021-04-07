#include <iostream>

using namespace std; 

class Point {
protected:
	int x, y;
public:
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

int main()
{
    
}
