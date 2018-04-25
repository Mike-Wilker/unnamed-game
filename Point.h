#pragma once
#include "IGeometry.h"
#include "Rectangle.h"
class Point : public IGeometry
{
private:
	double x;
	double y;
public:
	Point() = delete;
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	const double getX()
	{
		return x;
	}
	const double getY()
	{
		return y;
	}
	void setX(double x)
	{
		this->x = x;
	}
	void setY(double y)
	{
		this->y = y;
	}
	void addX(double x)
	{
		this->x += x;
	}
	void addY(double y)
	{
		this->y += y;
	}
	void multiply(double multiplier)
	{
		this->x *= multiplier;
		this->y *= multiplier;
	}
	void operator+=(Point* right)
	{
		this->setX(this->getX() + right->getX());
		this->setY(this->getY() + right->getY());
	}
	~Point()
	{

	}
};