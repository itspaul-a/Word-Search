#include <iostream>
#include <cstdlib>
#include <ctime>


class wordSearch
{
	private:

		std::vector<std::vector<char>> _grid;

	public:
		int size;
		wordSearch();
		wordSearch(int size);

		const std::vector<std::vector<char>>& getGrid() const;
		void setGrid(std::vector<std::vector<char>>& grid);
		void print();
};

