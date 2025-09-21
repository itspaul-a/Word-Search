#include "wordSearch.hpp"

int main()
{
	wordSearch ws;
	int xPos;
	int yPos;

	std::cout << "Enter x: ";
	std::cin >> xPos;
	std::cout << "Enter y: ";
	std::cin >> yPos;

	ws.addWords(xPos, yPos);
	ws.print();
	return 0;
}
