#pragma once

#include <vector>
#include <iostream>

template<typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T>& v)
{
	for(auto &i : v)
		os << i << " ";
	return os;
}