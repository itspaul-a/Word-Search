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
			//_grid.at(i).push_back(static_cast<char>(97 + rand() % (122-97 + 1)));
			_grid.at(i).push_back('*');
		}
	}
}

void wordSearch::addWords(int xPos, int yPos)
{
	int numberOfWords;
	int wordCount;
	int direction;
	
	std::cout << "enter word count: ";
	std::cin >> wordCount;

	std::cout << "Enter direction 1-3: ";
	std::cin >> direction;

	switch(direction)
	{
		case 1:
			//diagonal
			for(int i = 0; i < wordCount; i++)
			{
				_grid[i+xPos][i+yPos] = '%';
			}
		break;
	
		case 2:
			//vertical
			for(int i = 0; i<wordCount; i++)
			{
				_grid[i][0] = '%';
			}
		break;
		
		case 3:
			//horizontal
			for(int i = 0; i < wordCount; i++)
			{
				_grid[0][i] = '%';
			}
		break;
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



