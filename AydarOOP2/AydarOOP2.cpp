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
	printf("Запустился метод reset у класса Point\n");
	printf("Координаты точки (%d; %d)\n", x, y);
}


int main()
{
    
}
