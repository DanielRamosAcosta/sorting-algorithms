#include <iostream>
#include <vector>

#include "insertionSort.hpp"

template<typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T>& v)
{
	for(auto &i : v)
		os << i << " ";
	return os;
}

int main(void)
{	
	std::vector<int> vec = {3, 2, 0, 9, 5, 7, 8, 1, 4, 6};

	std::cout << "Before: " << vec << std::endl;
	dra::sort::insertion(vec);
	std::cout << " After: " << vec << std::endl;

	return 0;
}