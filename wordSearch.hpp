#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <cstdlib>
#include <ctime>

class WordSearch
{
	private:
	    int _gridSize;
	
	    std::vector<std::vector<char>> _grid;
	    std::vector<std::string> _wordBank;
	    std::vector<std::vector<std::pair<int,int>>> _positions;

	public:
	    WordSearch();

	    void print();
	    void addWord();
		void addRandomLetters();
	    void printSolution();
	    void wordBank();
		void playGame();
};

