#pragma once

#include <vector>
#include <algorithm>

#ifdef _DEBUG
	#include "utils.hpp"
#endif

#ifdef _64ARCH
	typedef long int signed_int;
#else
	typedef long long int signed_int;
#endif

namespace dra{
	namespace sort{

		template<typename T>
		void binary(std::vector<T>& vec)
		{
			for(std::size_t i = 1; i < vec.size(); i++){

				signed_int beg = 0;
				signed_int end = i - 1;
				while (beg <= end){
					std::size_t med = (beg+end)/2;
					if(vec[med] < vec[i])
						beg = med+1;
					else
						end = med-1;
				}

				vec.insert(vec.begin() + beg, vec[i]);
				vec.erase(vec.begin() + i + 1);
			}
		}

		template<typename T>
		void bubble(std::vector<T>& vec)
		{
			bool change = true;
			for(std::size_t i = 1; i < vec.size() && change; i++, change = true)
				for(std::size_t j = vec.size()-1; j >= i; j--)
					if( vec[j] < vec[j-1]){
						std::swap(vec[j-1], vec[j]);
						change = false;
					}
		}

		template<typename T>
		void heap(std::vector<T>& vec)
		{

		}
		
		template<typename T>
		void insertion(std::vector<T>& vec)
		{
			for(std::size_t i = 1, j = 0; i < vec.size(); i++, j = i){
				while ((j > 0) && (vec[i] < vec[j-1])) //important (j<0) to be first
					j--;

				vec.insert(vec.begin() + j, vec[i]);
				vec.erase(vec.begin() + i + 1);
			}
		}

		template<typename T>
		void merge(std::vector<T>& vec)
		{

		}

		template<typename T>
		void quick(std::vector<T>& vec)
		{

		}

		template<typename T>
		void radix(std::vector<T>& vec)
		{

		}

		template<typename T>
		void selection(std::vector<T>& vec)
		{
			for(std::size_t i = 0; i < vec.size(); i++){
				std::size_t min = i;
				for(std::size_t j = i + 1; j < vec.size(); j++)
					if(vec[j] < vec[min])
						min = j;
	
				std::swap(vec[i], vec[min]);
			}
		}

		template<typename T>
		void shake(std::vector<T>& vec)
		{

		}

		template<typename T>
		void shell(std::vector<T>& vec)
		{

		}
	}
}