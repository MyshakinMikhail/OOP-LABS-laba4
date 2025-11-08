#pragma once
#include "Point.h"
#include <type_traits>
#include <memory>
#include <vector>
#include <iostream>

template <typename T>
class Figure
{
	static_assert(std::is_arithmetic_v<T>, "T must be an arithmetic type");

public:
	virtual ~Figure() = default;

	virtual Point<T> geometricCenter() const = 0;
	virtual double area() const = 0;
	virtual void printVertices(std::ostream &os) const = 0;
	virtual operator double() const { return area(); }

	virtual std::unique_ptr<Figure<T>> clone() const = 0;

	friend std::ostream &operator<<(std::ostream &os, const Figure<T> &fig)
	{
		os << "Center: " << fig.geometricCenter() << ", Area: " << fig.area() << ", Vertices: ";
		fig.printVertices(os);
		return os;
	}
};