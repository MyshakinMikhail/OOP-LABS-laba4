#pragma once
#include <type_traits>
#include <memory>
#include <iostream>

template <typename T>
class Point
{
private:
	T x_, y_;

public:
	Point() : x_(0), y_(0) {}
	Point(T x, T y) : x_(x), y_(y) {}

	T x() const { return x_; }
	T y() const { return y_; }

	Point<T> operator+(const Point<T> &other) const
	{
		return Point<T>(x_ + other.x_, y_ + other.y_);
	}

	Point<T> operator/(T divisor) const
	{
		return Point<T>(x_ / divisor, y_ / divisor);
	}

	friend std::ostream &operator<<(std::ostream &os, const Point<T> &point)
	{
		os << "(" << point.x_ << ", " << point.y_ << ")";
		return os;
	}

	bool operator==(const Point<T> &other) const
	{
		return x_ == other.x_ && y_ == other.y_;
	}
};