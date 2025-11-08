#include <iostream>
#include <memory>
#include "Point.h"
#include "Triangle.h"
#include "Square.h"
#include "Rectangle.h"
#include "Array.h"

void printMenu()
{
	std::cout << "\n=== Figure Management System ===\n";
	std::cout << "1. Add Triangle\n";
	std::cout << "2. Add Square\n";
	std::cout << "3. Add Rectangle\n";
	std::cout << "4. Print all figures\n";
	std::cout << "5. Calculate total area\n";
	std::cout << "6. Remove figure by index\n";
	std::cout << "7. Exit\n";
	std::cout << "Choose option: ";
}

int main()
{
	Array<std::shared_ptr<Figure<double>>> figures;

	int choice;
	while (true)
	{
		printMenu();
		std::cin >> choice;

		try
		{
			switch (choice)
			{
			case 1:
			{
				double x1, y1, x2, y2, x3, y3;
				std::cout << "Enter triangle vertices (x1 y1 x2 y2 x3 y3): ";
				std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
				auto triangle = std::make_shared<Triangle<double>>(
					Point<double>(x1, y1),
					Point<double>(x2, y2),
					Point<double>(x3, y3));
				figures.push_back(triangle);
				std::cout << "Triangle added successfully!\n";
				break;
			}
			case 2:
			{
				double x, y, side;
				std::cout << "Enter square center (x y) and side length: ";
				std::cin >> x >> y >> side;
				auto square = std::make_shared<Square<double>>(Point<double>(x, y), side);
				figures.push_back(square);
				std::cout << "Square added successfully!\n";
				break;
			}
			case 3:
			{
				double x, y, width, height;
				std::cout << "Enter rectangle center (x y), width and height: ";
				std::cin >> x >> y >> width >> height;
				auto rectangle = std::make_shared<Rectangle<double>>(Point<double>(x, y), width, height);
				figures.push_back(rectangle);
				std::cout << "Rectangle added successfully!\n";
				break;
			}
			case 4:
			{
				std::cout << "\n=== All Figures ===\n";
				for (size_t i = 0; i < figures.size(); ++i)
				{
					std::cout << "[" << i << "] " << *figures[i] << "\n";
				}
				break;
			}
			case 5:
			{
				std::cout << "Total area of all figures: " << figures.totalArea() << "\n";
				break;
			}
			case 6:
			{
				size_t index;
				std::cout << "Enter index to remove: ";
				std::cin >> index;
				figures.remove(index);
				std::cout << "Figure removed successfully!\n";
				break;
			}
			case 7:
				std::cout << "Goodbye!\n";
				return 0;
			default:
				std::cout << "Invalid choice!\n";
			}
		}
		catch (const std::exception &e)
		{
			std::cout << "Error: " << e.what() << "\n";
		}
	}

	return 0;
}