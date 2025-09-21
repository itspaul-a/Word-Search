#include "wordSearch.hpp"

wordSearch::wordSearch()
{
	std::cout << "Enter grid size: ";
	std::cin >> gridSize;

	srand(static_cast<int>(time(0)));
	
	for(int i = 0; i < gridSize; i++)
	{
		_grid.push_back(std::vector<char>());
		for(int j = 0; j < gridSize; j++)
		{
			//_grid.at(i).push_back(static_cast<char>(97 + rand() % (122-97 + 1)));
			_grid.at(i).push_back('*');
		}
	}
}

void wordSearch::positionWord(std::string word)
{

	int sX;
	int sY;

	int eX;
	int eY;

	int wordCount = word.length();
	
	std::cout << "Enter start x: ";
	std::cin >> sX;
	std::cout << "Enter start y: ";
	std::cin >> sY;

	std::cout << "Enter end x: ";
	std::cin >> eX;
	std::cout << "Enter end y: ";
	std::cin >> eY;


	//check if word fits in grid
	if(sX > gridSize || sY > gridSize || eX > gridSize || eY > gridSize)
	{
		std::cout << "word does not fit\n";
		std::exit(EXIT_FAILURE);
	}
	
	//find direction of word
    int xStep = (eX - sX == 0) ? 0 : (eX - sX) / abs(eX - sX);
    int yStep = (eY - sY == 0) ? 0 : (eY - sY) / abs(eY - sY);

	//place word in grid
	for(int i = 0; i < wordCount; i++)
	{
		_grid[sX][sY] = word[i];
		sX += xStep;
		sY += yStep;

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

		positionWord(word);
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



