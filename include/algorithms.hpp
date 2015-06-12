#pragma once

#include <vector>
#include <algorithm>

#ifdef _DEBUG
	#include <unistd.h>
	#include "utils.hpp"
#endif

#ifdef _64ARCH
typedef long int signed_int;
#else
typedef long long int signed_int;
#endif

#define SHELL_SORT_ALPHA 0.5

namespace dra{
	class sort{
	public:
		template<typename T>
		static void binary(std::vector<T>& vec);
		
		template<typename T>
		static void bubble(std::vector<T>& vec);

		template<typename T>
		static void cocktail(std::vector<T>& vec);

		template<typename T>
		static void heap(std::vector<T>& vec);

		template<typename T>
		static void insertion(std::vector<T>& vec);

		template<typename T>
		static void merge(std::vector<T>& vec);

		template<typename T>
		static void quick(std::vector<T>& vec);

		template<typename T>
		static void radix(std::vector<T>& vec);

		template<typename T>
		static void selection(std::vector<T>& vec);

		template<typename T>
		static void shell(std::vector<T>& vec);
	private:
		template<typename T>
		static void shift_down(std::vector<T>& vec, std::size_t i, std::size_t n);

		template<typename T>
		static void quick(std::vector<T>& vec, std::size_t beg, std::size_t end);

		template<typename T>
		static void mix_sorted(std::vector<T>& vec, std::vector<T>& left, std::vector<T>& right);

		template<typename T>
		static void count_sort(std::vector<T>& vec, int exp);

	};

	template<typename T>
	void sort::binary(std::vector<T>& vec)
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
	void sort::bubble(std::vector<T>& vec)
	{
		bool change = true;
		for(std::size_t i = 1; (i < vec.size()) && (change); i++){
			change = false;
			for(std::size_t j = vec.size()-1; j >= i; j--)
				if( vec[j] < vec[j-1]){
					std::swap(vec[j-1], vec[j]);
					change = true;
				}
			}
		}

	template<typename T>
	void sort::cocktail(std::vector<T>& vec)
	{
		bool change = true;
		for(std::size_t beg = 1, end = vec.size() - 1; (beg < end) && (change);){
			change = false;
			for(std::size_t j = beg; j <= end; j++)
				if(vec[j] < vec[j-1]){
					std::swap(vec[j-1], vec[j]);
					change = true;
				}

				end--;
				for(std::size_t j = end; j >= beg; j--)
					if(vec[j] < vec[j-1]){
						std::swap(vec[j-1], vec[j]);
						change = true;
					}

				beg++;
		}
	}

	template<typename T>
	void sort::heap(std::vector<T>& vec)
	{
		for(signed_int i = vec.size()/2 - 1; i >= 0; i--)
			shift_down(vec, i, vec.size());
		
		for(signed_int i = vec.size() - 1; i > 0; i--){
			std::swap(vec[0], vec[i]);
			shift_down(vec, 0, i-1);
		}
	}

	template<typename T>
	void sort::shift_down(std::vector<T>& vec, std::size_t i, std::size_t n)
	{
		while(i * 2 < n)
		{
			std::size_t c1 = i * 2 + 1;
			std::size_t c2 = i * 2 + 2;
			
			std::size_t max = c1;

			if((c2 < n) && (vec[c1] < vec[c2])) //if c2 exists and is bigger than c1
					max = c2;

			if(vec[max] <= vec[i])
				return;
			else{
				std::swap(vec[i], vec[max]);
				i = max;
			}
		}
	}

	template<typename T>
	void sort::insertion(std::vector<T>& vec)
	{
		for(std::size_t i = 1, j = 0; i < vec.size(); i++, j = i){
			while ((j > 0) && (vec[i] < vec[j-1])) //important (j<0) to be first
				j--;

				vec.insert(vec.begin() + j, vec[i]);
				vec.erase(vec.begin() + i + 1);
			}
	}

	template<typename T>
	void sort::merge(std::vector<T>& vec)
	{
		if(vec.size() == 1)
			return;

		auto mid = vec.begin() + (vec.size()/2);

		std::vector<T> left(vec.begin(), mid);
		std::vector<T> right(mid, vec.end());

		merge(left);
		merge(right);

		mix_sorted(vec, left, right);
	}

	template<typename T>
	void sort::mix_sorted(std::vector<T>& vec, std::vector<T>& left, std::vector<T>& right)
	{
		std::size_t i, j, k;

		for(i = 0, j = 0, k = 0; (i < left.size()) && (j < right.size()); k++){
			if(left[i] < right[j]){
				vec[k] = left[i];
				i++;
			}
			else{
				vec[k] = right[j];
				j++;
			}
		}

		for(i = i; i < left.size(); i++, k++)
			vec[k] = left[i];

		for(j = j; j < right.size(); j++, k++)
			vec[k] = right[j];
	}

	template<typename T>
	void sort::quick(std::vector<T>& vec)
	{
		quick(vec, 0, vec.size());
	}

	template<typename T>
	void sort::quick(std::vector<T>& vec, std::size_t beg, std::size_t end)
	{
		std::size_t b = beg;
		std::size_t e = end;
		T piv = vec[(beg + end)/2];

		while (b <= e){
			while (vec[b] < piv) b++;
			while (vec[e] > piv) e--;
			if (b <= e){
				std::swap(vec[b], vec[e]);
				b++; e--;
			}
		}

		if (beg < e) quick(vec, beg, e);
		if (b < end) quick(vec, b, end);
	}

	template<typename T>
	void sort::radix(std::vector<T>& vec)
	{
		int m = *std::max_element(vec.begin(), vec.end());
    	for (int exp = 1; m / exp > 0; exp *= 10)
        	count_sort(vec, exp);
	}

	template<typename T>
	void sort::count_sort(std::vector<T>& vec, int exp)
	{
		std::vector<T> output(vec.size());
		std::vector<int> count(10, 0);

		for (std::size_t i = 0; i < vec.size(); i++)
			count[(vec[i]/exp)%10]++;
		for(std::size_t i = 1; i < 10; i++)
			count[i] += count[i - 1];

		for (signed_int i = vec.size() - 1; i >= 0; i--){
			output[count[(vec[i] / exp) % 10] - 1] = vec[i];
			count[(vec[i] / exp) % 10]--;
		}
		vec = output;
	}

	template<typename T>
	void sort::selection(std::vector<T>& vec)
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
	void sort::shell(std::vector<T>& vec)
	{
		std::size_t delta = vec.size();
		while(delta > 1){
			delta *= SHELL_SORT_ALPHA;;

			for(std::size_t i = delta; i < vec.size(); i++){
				T it = vec[i];

				std::size_t j;
				for(j = i; (j >= delta) && (it < vec[j-delta]); j-=delta)
					vec[j] = vec[j-delta];

				vec[j] = it;
			}
		}
	}

}