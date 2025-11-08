#pragma once
#include "Figure.h"
#include <cmath>

template <typename T>
class Rectangle : public Figure<T>
{
private:
	std::unique_ptr<Point<T>> vertices_[4];

public:
	Rectangle(Point<T> center, T width, T height)
	{
		T half_w = width / 2;
		T half_h = height / 2;
		vertices_[0] = std::make_unique<Point<T>>(center.x() - half_w, center.y() - half_h);
		vertices_[1] = std::make_unique<Point<T>>(center.x() + half_w, center.y() - half_h);
		vertices_[2] = std::make_unique<Point<T>>(center.x() + half_w, center.y() + half_h);
		vertices_[3] = std::make_unique<Point<T>>(center.x() - half_w, center.y() + half_h);
	}

	Rectangle(const Rectangle &other)
	{
		for (int i = 0; i < 4; ++i)
		{
			vertices_[i] = std::make_unique<Point<T>>(*other.vertices_[i]);
		}
	}

	Rectangle &operator=(const Rectangle &other)
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

	Rectangle(Rectangle &&other) noexcept
	{
		for (int i = 0; i < 4; ++i)
		{
			vertices_[i] = std::move(other.vertices_[i]);
		}
	}

	Rectangle &operator=(Rectangle &&other) noexcept
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
		T width = std::abs(vertices_[1]->x() - vertices_[0]->x());
		T height = std::abs(vertices_[2]->y() - vertices_[1]->y());
		return width * height;
	}

	void printVertices(std::ostream &os) const override
	{
		os << *vertices_[0] << " " << *vertices_[1] << " "
		   << *vertices_[2] << " " << *vertices_[3];
	}

	std::unique_ptr<Figure<T>> clone() const override
	{
		return std::make_unique<Rectangle<T>>(*this);
	}

	bool operator==(const Rectangle &other) const
	{
		for (int i = 0; i < 4; ++i)
		{
			if (!(*vertices_[i] == *other.vertices_[i]))
				return false;
		}
		return true;
	}
};