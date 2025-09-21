#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>


class wordSearch
{
	private:

		std::vector<std::vector<char>> _grid;

	public:
		int size;
		wordSearch();
		wordSearch(int size);
		void print();
		void positionWord(std::string word, int direction);
		void addWord();
};

