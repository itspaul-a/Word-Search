#include "wordSearch.hpp"

wordSearch::wordSearch() : wordSearch(5)
{}

wordSearch::wordSearch(int size)
{
	char num = '*';
	for(int i = 0; i < size; i++)
	{
		_grid.push_back(std::vector<char>());
		for(int j = 0; j < size; j++)
		{
			_grid.at(i).push_back(num);
		}
	}
}

void wordSearch::print()
{

}
