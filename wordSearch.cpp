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

void wordSearch::positionWord(std::string word, int direction)
{

	int xPos;
	int yPos;

	int wordCount = word.length();
	
	std::cout << "Enter x: ";
	std::cin >> xPos;
	std::cout << "Enter y: ";
	std::cin >> yPos;

	switch(direction)
	{
		case 1:
			//diagonal
			for(int i = 0; i < wordCount; i++)
			{
				_grid[i+xPos][i+yPos] = word[i];
			}
		break;
	
		case 2:
			//vertical
			for(int i = 0; i<wordCount; i++)
			{
				_grid[i+xPos][yPos] = word[i];
			}
		break;
		
		case 3:
			//horizontal
			for(int i = 0; i < wordCount; i++)
			{
				_grid[xPos][i+yPos] = word[i];
			}
		break;
	}
}

void wordSearch::addWord()
{
	int amountOfWords;
	std::cout << "how many words: ";
	std::cin >> amountOfWords;

	for(int i = 0; i < amountOfWords; i++)
	{
		std::string word;
		std::cout << "Enter word: ";
		std::cin >> word;

		int direction;
		std::cout << "Enter direction 1-3: ";
		std::cin >> direction;

		positionWord(word, direction);
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



