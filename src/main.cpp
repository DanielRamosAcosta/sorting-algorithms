#include <iostream>
#include <vector>

#include "algorithms.hpp"
#include "utils.hpp"

int main(void)
{	
	std::vector<int> vec = {3, 2, 0, 9, 5, 7, 8, 1, 4, 6};

	std::cout << "Before: " << vec << std::endl;
	dra::sort::cocktail(vec);
	std::cout << " After: " << vec << std::endl;

	return 0;
}