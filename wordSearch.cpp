#include "wordSearch.hpp"

wordSearch::wordSearch()
{
	int size;
	std::cout << "Enter grid size: ";
	std::cin >> size;

	srand(static_cast<int>(time(0)));
	
	for(int i = 0; i < size; i++)
	{
		_grid.push_back(std::vector<char>());
		for(int j = 0; j < size; j++)
		{
			_grid.at(i).push_back(static_cast<char>(97 + rand() % (122-97 + 1)));
		}
	}
}

void wordSearch::print()
{
	for(auto&  i : _grid)
	{
		for(char j : i)
		{
			std::cout << j << " ";
		}
		std::cout << std::endl;
	}
}



