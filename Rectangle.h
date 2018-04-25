#pragma once
#include <algorithm>

#include "IGeometry.h"
#include "Point.h"
class Rectangle : public IGeometry
{
private:
	Point* origin;
	Point* dimensions;
public:
	Rectangle(double x, double y, double width, double height)
	{
		this->origin = new Point(x, y);
		this->dimensions = new Point(width, height);
	}
	Rectangle(Point* origin, double width, double height)
	{
		this->origin = origin;
		this->dimensions = new Point(width, height);
	}
	Rectangle(Point* origin, Point* dimensions)
	{
		this->origin = origin;
		this->dimensions = dimensions;
	}
	const double getX()
	{
		return origin->getX();
	}
	const double getY()
	{
		return origin->getY();
	}
	const double getCenterX()
	{
		return origin->getX() + (this->dimensions->getX() / 2.0);
	}
	const double getCenterY()
	{
		return origin->getY() + (this->dimensions->getY() / 2.0);
	}
	const double getWidth()
	{
		return this->dimensions->getX();
	}
	const double getHeight()
	{
		return this->dimensions->getY();
	}
	void setX(double x)
	{
		this->origin->setX(x);
	}
	void setY(double y)
	{
		this->origin->setY(y);
	}
	void setOrigin(Point* origin)
	{
		this->origin = origin;
	}
	void setWidth(double width)
	{
		this->dimensions->setX(width);
	}
	void setHeight(double height)
	{
		this->dimensions->setY(height);
	}
	void setSize(double size)
	{
		this->dimensions->setX(size);
		this->dimensions->setY(size);
	}
	bool checkCollision(Point* subject)
	{
		return subject->getX() >= this->getX() && subject->getX() <= this->getX() + this->getWidth() && subject->getY() >= this->getY() && subject->getY() <= this->getY() + this->getHeight();
	}
	bool checkCollision(Rectangle* subject)
	{
		return (std::abs(this->getCenterX() - subject->getCenterX()) <= std::abs(this->getWidth() - subject->getWidth())
			&& std::abs(this->getCenterY() - subject->getCenterY()) <= std::abs(this->getHeight() - subject->getHeight()));
	}
	double distanceTo(Point* subject)
	{
		return sqrt(pow(std::max(subject->getX(), getCenterX()) - std::min(subject->getX(), getCenterX()), 2) + pow(std::max(subject->getY(), getCenterY()) - std::min(subject->getY(), getCenterY()), 2));
	}
	double distanceTo(Rectangle* subject)
	{
		return sqrt(pow(std::max(subject->getCenterX(), getCenterX()) - std::min(subject->getCenterX(), getCenterX()), 2) + pow(std::max(subject->getCenterY(), getCenterY()) - std::min(subject->getCenterY(), getCenterY()), 2));
	}
	~Rectangle()
	{
		delete dimensions;
	}
};