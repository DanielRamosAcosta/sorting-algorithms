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
		void binary(std::vector<T>& v)
		{
			for(std::size_t i = 1; i < v.size(); i++){
				#ifdef _DEBUG
					std::cout << "i = " << i << "; " << v << std::endl;
				#endif

				signed_int beg = 0;
				signed_int end = i - 1;
				while (beg <= end){
					std::size_t med = (beg+end)/2;
					if(v[med] < v[i])
						beg = med+1;
					else
						end = med-1;
				}

				v.insert(v.begin() + beg, v[i]);
				v.erase(v.begin() + i + 1);

				#ifdef _DEBUG
					std::cout << "i = " << i << "; " << v << "✓" << std::endl;
				#endif
			}
			#ifdef _DEBUG
				std::cout << v << "✔" << std::endl;
			#endif
		}

		template<typename T>
		void bubble(std::vector<T>& v)
		{
			
		}

		template<typename T>
		void heap(std::vector<T>& v)
		{

		}
		
		template<typename T>
		void insertion(std::vector<T>& v)
		{
			for(std::size_t i = 1, j = 0; i < v.size(); i++, j = i){
				#ifdef _DEBUG
					std::cout << "i = " << i << "; " << v << std::endl;
				#endif
				while ((j > 0) && (v[i] < v[j-1])) //important (j<0) to be first
					j--;

				v.insert(v.begin() + j, v[i]);
				v.erase(v.begin() + i + 1);

				#ifdef _DEBUG
					std::cout << "i = " << i << "; " << v << "✓" << std::endl;
				#endif
			}
			#ifdef _DEBUG
				std::cout << v << "✔" << std::endl;
			#endif
		}

		template<typename T>
		void merge(std::vector<T>& v)
		{

		}

		template<typename T>
		void quick(std::vector<T>& v)
		{

		}

		template<typename T>
		void radix(std::vector<T>& v)
		{

		}

		template<typename T>
		void selection(std::vector<T>& v)
		{
			for(std::size_t i = 0; i < v.size(); i++){
				#ifdef _DEBUG
					std::cout << "i = " << i << "; " << v << std::endl;
				#endif
				std::size_t min = i;
				for(std::size_t j = i + 1; j < v.size(); j++){
					if(v[j] < v[min])
						min = j;
				}
				std::swap(v[i], v[min]);
				#ifdef _DEBUG
					std::cout << "i = " << i << "; " << v << "✓" << std::endl;
				#endif
			}
			#ifdef _DEBUG
				std::cout << v << "✔" << std::endl;
			#endif
		}

		template<typename T>
		void shake(std::vector<T>& v)
		{

		}

		template<typename T>
		void shell(std::vector<T>& v)
		{

		}
	}
}