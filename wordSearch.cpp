#include "wordSearch.hpp"

WordSearch::WordSearch()
{
	std::cout << "Enter size of grid (n x n): ";
	std::cin >> _gridSize;

    srand(static_cast<int>(time(0)));

    for (int i = 0; i < _gridSize; i++)
    {
        _grid.push_back(std::vector<char>());
        for (int j = 0; j < _gridSize; j++)
        {
            _grid.at(i).push_back('*');
        }
    }
}

void WordSearch::print()
{
    for (auto i : _grid)
    {
        for (char j : i)
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void WordSearch::printSolution()
{
    std::vector<std::vector<char>> solution(_gridSize, std::vector<char>(_gridSize, '*'));

    for (auto i : _positions)
    {
        for (auto j : i)
        {
            int x = j.first;
            int y = j.second;
            solution[y][x] = _grid[y][x];
        }
    }

    std::cout << "Solution: " << std::endl;
    for (auto i : solution)
    {
        for (char j : i)
        {
            std::cout << j << " ";
        }
		 std::cout << std::endl;
    }
	std::cout << std::endl;
}

void WordSearch::wordBank()
{
    std::cout << "Word Bank:\n";
    for (auto word : _wordBank)
    {
        std::cout << "- " << word << "\n";
    }
	std::cout << std::endl;
}

void WordSearch::addWord()
{
    int numOfWords;
    std::cout << "How many words?: ";
    std::cin >> numOfWords;

    while (numOfWords > 0)
    {
        std::string word;
        std::cout << "Enter word: ";
        std::cin >> word;
        _wordBank.push_back(word);

        int startX, startY, endX, endY;
        std::cout << "Enter start x: ";
        std::cin >> startX;
        std::cout << "Enter start y: ";
        std::cin >> startY;

        std::cout << "Enter end x: ";
        std::cin >> endX;
        std::cout << "Enter end y: ";
        std::cin >> endY;

        // check if word is in bound
        if (startX < 0 || startX >= _gridSize || startY < 0 || startY >= _gridSize ||
            endX < 0 || endX >= _gridSize || endY < 0 || endY >= _gridSize)
        {
            std::cout << "Coordinates out of bounds.\n\n";
            numOfWords--;
            continue;
        }

        int xLen = abs(endX - startX) + 1;
        int yLen = abs(endY - startY) + 1;

        // check if word fits
        if (!(word.size() == xLen || 
              word.size() == yLen || 
              (word.size() == xLen && word.size() == yLen)))
        {
            std::cout << "Word does not fit in range.\n\n";
            numOfWords--;
            continue;
        }

        int xMove = (endX - startX == 0) ? 0 : (endX - startX) / abs(endX - startX);
        int yMove = (endY - startY == 0) ? 0 : (endY - startY) / abs(endY - startY);

        // simulate placement
        std::vector<std::pair<int,int>> tempPositions;
        bool conflict = false;

        int x = startX;
		int y = startY;

        for (int i = 0; i < word.size(); i++)
        {
            if (_grid[y][x] != '*' && _grid[y][x] != word[i])
            {
                std::cout << "Conflict at (" << x << ", " << y << ")\n";
                conflict = true;
                break;
            }

            tempPositions.push_back({x, y});
            x += xMove;
            y += yMove;
        }

        if (!conflict)
        {
            // actual placement
            for (int i = 0; i < word.size(); i++)
            {
                int pX = tempPositions[i].first;
                int pY = tempPositions[i].second;
                _grid[pY][pX] = word[i];
            }

            // save position of words
            _positions.push_back(tempPositions);
			
			//print out coordinates
            //std::cout << "\nCoordinates for " << word << ":\n";
            //for (auto pos : tempPositions)
            //{
            //    std::cout << "(" << pos.first << ", " << pos.second << ") ";
            //}
            //std::cout << std::endl;
        }
        else
        {
            std::cout << "Word '" << word << "' could not be placed due to conflict.\n"  << std::endl;
        }

        numOfWords--;
    }

    // change grid with random letters 
    for (int i = 0; i < _gridSize; i++)
    {
        for (int j = 0; j < _gridSize; j++)
        {
            if (_grid[i][j] == '*')
            {
                _grid[i][j] = 'a' + rand() % 26;
            }
        }
    }

    print();
}

void WordSearch::playGame()
{
	addWord();
	wordBank();
	
	bool check = true;
	while (check)
	{
		std::string answer;
		std::cout << "would you like the solution? (y/n): ";
		std::cin >> answer;

		if(answer == "y" || answer == "yes")
		{
			printSolution();
			check = false;
		}
		else if (answer == "n" || answer == "no")
		{
			check = false;
		}
		else 
		{
			std::cout << "invalid input" << std::endl;
		}
	}
}
