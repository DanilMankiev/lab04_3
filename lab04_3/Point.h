#pragma once
#include <iostream>
using namespace std;
class Point {
	double x, y;
	friend class Rect;
public:
	Point();
	Point(double x, double y);
	friend ostream& operator<< (ostream& out, const Point& point);
	double& getX();
	double& getY();
	bool operator<(const Point p) const;
	Point& operator=(const Point& p);
	bool operator==(const Point& p) const;
};

class Rect{
	Point first;
	Point second;
public:
	Rect(double x1, double y1, double x2, double y2);
	Rect(Point p1, Point p2);
	Point GetCenter();
	bool operator<(Rect& rect);
};
