#include"Point.h"
#include<iostream>

Point::Point() :x(0), y(0) {}
Point::Point(double x, double y) : x(x), y(y) {}
double& Point::getX() { return x; }
double& Point::getY() { return y; }
bool Point::operator<(const Point p) const {
	return double(sqrt(x * x + y * y)) < double(sqrt(p.x * p.x + p.y * p.y));
}
Point& Point::operator=(const Point& p) {
	x = p.x;
	y = p.y;
	return *this;
}
bool Point::operator==(const Point& p) const {
	return (x == p.x && y == p.y);
}

ostream& operator<<(ostream& out, const Point& point) {
	out << "x: " << point.x << " y: " << point.y << endl;
	return out;
};
Rect::Rect(double x1, double y1, double x2, double y2) {
	first.getX() = x1;
	first.getY() = y1;
	second.getX() = x2;
	second.getY() = y2;
}
Rect::Rect(Point p1, Point p2) {
	first = p1;
	second = p2;
}
Point Rect::GetCenter() {
	return Point((first.getX() + second.getX()) / 2, (first.getY() + second.getY()) / 2);
}
bool Rect::operator<(Rect& rect) {
	return this->GetCenter() < rect.GetCenter();
}