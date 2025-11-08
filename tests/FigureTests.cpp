#include <gtest/gtest.h>
#include "../src/Point.h"
#include "../src/Triangle.h"
#include "../src/Square.h"
#include "../src/Rectangle.h"
#include "../src/Array.h"

TEST(PointTest, ConstructionAndOperations)
{
	Point<double> p1(1.0, 2.0);
	Point<double> p2(3.0, 4.0);

	auto sum = p1 + p2;
	EXPECT_DOUBLE_EQ(sum.x(), 4.0);
	EXPECT_DOUBLE_EQ(sum.y(), 6.0);

	auto div = sum / 2.0;
	EXPECT_DOUBLE_EQ(div.x(), 2.0);
	EXPECT_DOUBLE_EQ(div.y(), 3.0);
}

TEST(TriangleTest, AreaAndCenter)
{
	Triangle<double> t(Point<double>(0, 0), Point<double>(4, 0), Point<double>(0, 3));

	auto center = t.geometricCenter();
	EXPECT_DOUBLE_EQ(center.x(), 4.0 / 3);
	EXPECT_DOUBLE_EQ(center.y(), 1.0);

	EXPECT_DOUBLE_EQ(t.area(), 6.0);
}

TEST(SquareTest, AreaAndCenter)
{
	Square<double> s(Point<double>(0, 0), 4.0);

	auto center = s.geometricCenter();
	EXPECT_DOUBLE_EQ(center.x(), 0.0);
	EXPECT_DOUBLE_EQ(center.y(), 0.0);

	EXPECT_DOUBLE_EQ(s.area(), 16.0);
}

TEST(RectangleTest, AreaAndCenter)
{
	Rectangle<double> r(Point<double>(0, 0), 4.0, 6.0);

	auto center = r.geometricCenter();
	EXPECT_DOUBLE_EQ(center.x(), 0.0);
	EXPECT_DOUBLE_EQ(center.y(), 0.0);

	EXPECT_DOUBLE_EQ(r.area(), 24.0);
}

TEST(ArrayTest, BasicOperations)
{
	Array<std::shared_ptr<Figure<double>>> arr;

	auto triangle = std::make_shared<Triangle<double>>(
		Point<double>(0, 0), Point<double>(4, 0), Point<double>(0, 3));
	auto square = std::make_shared<Square<double>>(Point<double>(0, 0), 2.0);

	arr.push_back(triangle);
	arr.push_back(square);

	EXPECT_EQ(arr.size(), 2);
	EXPECT_DOUBLE_EQ(arr.totalArea(), 6.0 + 4.0);

	arr.remove(0);
	EXPECT_EQ(arr.size(), 1);
	EXPECT_DOUBLE_EQ(static_cast<double>(*arr[0]), 4.0);
}

TEST(ArrayTest, MoveSemantics)
{
	Array<std::string> arr;

	std::string str1 = "Hello";
	std::string str2 = "World";

	arr.push_back(std::move(str1));
	arr.push_back(std::move(str2));

	EXPECT_TRUE(str1.empty());
	EXPECT_TRUE(str2.empty());
	EXPECT_EQ(arr[0], "Hello");
	EXPECT_EQ(arr[1], "World");
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}