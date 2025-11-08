#pragma once
#include "Figure.h"
#include <cmath>

template <typename T>
class Triangle : public Figure<T>
{
private:
	std::unique_ptr<Point<T>> vertices_[3];

public:
	Triangle(Point<T> p1, Point<T> p2, Point<T> p3)
	{
		vertices_[0] = std::make_unique<Point<T>>(p1);
		vertices_[1] = std::make_unique<Point<T>>(p2);
		vertices_[2] = std::make_unique<Point<T>>(p3);
	}

	Triangle(const Triangle &other)
	{
		for (int i = 0; i < 3; ++i)
		{
			vertices_[i] = std::make_unique<Point<T>>(*other.vertices_[i]);
		}
	}

	Triangle &operator=(const Triangle &other)
	{
		if (this != &other)
		{
			for (int i = 0; i < 3; ++i)
			{
				vertices_[i] = std::make_unique<Point<T>>(*other.vertices_[i]);
			}
		}
		return *this;
	}

	Triangle(Triangle &&other) noexcept
	{
		for (int i = 0; i < 3; ++i)
		{
			vertices_[i] = std::move(other.vertices_[i]);
		}
	}

	Triangle &operator=(Triangle &&other) noexcept
	{
		if (this != &other)
		{
			for (int i = 0; i < 3; ++i)
			{
				vertices_[i] = std::move(other.vertices_[i]);
			}
		}
		return *this;
	}

	Point<T> geometricCenter() const override
	{
		Point<T> sum = *vertices_[0] + *vertices_[1] + *vertices_[2];
		return sum / static_cast<T>(3);
	}

	double area() const override
	{
		T x1 = vertices_[0]->x(), y1 = vertices_[0]->y();
		T x2 = vertices_[1]->x(), y2 = vertices_[1]->y();
		T x3 = vertices_[2]->x(), y3 = vertices_[2]->y();

		return std::abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
	}

	void printVertices(std::ostream &os) const override
	{
		os << *vertices_[0] << " " << *vertices_[1] << " " << *vertices_[2];
	}

	std::unique_ptr<Figure<T>> clone() const override
	{
		return std::make_unique<Triangle<T>>(*this);
	}

	bool operator==(const Triangle &other) const
	{
		return *vertices_[0] == *other.vertices_[0] &&
			   *vertices_[1] == *other.vertices_[1] &&
			   *vertices_[2] == *other.vertices_[2];
	}
};