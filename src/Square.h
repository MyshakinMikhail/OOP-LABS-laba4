#pragma once
#include "Figure.h"
#include <cmath>

template <typename T>
class Square : public Figure<T>
{
private:
	std::unique_ptr<Point<T>> vertices_[4];

public:
	Square(Point<T> center, T side)
	{
		T half = side / 2;
		vertices_[0] = std::make_unique<Point<T>>(center.x() - half, center.y() - half);
		vertices_[1] = std::make_unique<Point<T>>(center.x() + half, center.y() - half);
		vertices_[2] = std::make_unique<Point<T>>(center.x() + half, center.y() + half);
		vertices_[3] = std::make_unique<Point<T>>(center.x() - half, center.y() + half);
	}

	Square(const Square &other)
	{
		for (int i = 0; i < 4; ++i)
		{
			vertices_[i] = std::make_unique<Point<T>>(*other.vertices_[i]);
		}
	}

	Square &operator=(const Square &other)
	{
		if (this != &other)
		{
			for (int i = 0; i < 4; ++i)
			{
				vertices_[i] = std::make_unique<Point<T>>(*other.vertices_[i]);
			}
		}
		return *this;
	}

	Square(Square &&other) noexcept
	{
		for (int i = 0; i < 4; ++i)
		{
			vertices_[i] = std::move(other.vertices_[i]);
		}
	}

	Square &operator=(Square &&other) noexcept
	{
		if (this != &other)
		{
			for (int i = 0; i < 4; ++i)
			{
				vertices_[i] = std::move(other.vertices_[i]);
			}
		}
		return *this;
	}

	Point<T> geometricCenter() const override
	{
		Point<T> sum = *vertices_[0] + *vertices_[1] + *vertices_[2] + *vertices_[3];
		return sum / static_cast<T>(4);
	}

	double area() const override
	{
		T side = std::abs(vertices_[1]->x() - vertices_[0]->x());
		return side * side;
	}

	void printVertices(std::ostream &os) const override
	{
		os << *vertices_[0] << " " << *vertices_[1] << " "
		   << *vertices_[2] << " " << *vertices_[3];
	}

	std::unique_ptr<Figure<T>> clone() const override
	{
		return std::make_unique<Square<T>>(*this);
	}

	bool operator==(const Square &other) const
	{
		for (int i = 0; i < 4; ++i)
		{
			if (!(*vertices_[i] == *other.vertices_[i]))
				return false;
		}
		return true;
	}
};