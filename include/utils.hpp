#pragma once

#include <vector>
#include <iostream>
#include <sstream>
#include <string>

template<typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T>& v)
{
	for(auto &i : v)
		os << i << " ";
	return os;
}

template<typename T>
std::string prt(std::vector<T>& v, std::size_t beg, std::size_t end)
{
	std::stringstream ss;
	for(std::size_t i = beg; i <= end; i++)
		ss << v[i] << " ";
	return ss.str();
}