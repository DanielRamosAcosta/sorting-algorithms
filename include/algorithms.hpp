#include <vector>
#include <algorithm>

namespace dra{
	namespace sort{

		template<typename T>
		void binary(std::vector<T>& v)
		{

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
			for(unsigned i = 1, j = 0; i < v.size(); i++, j = i - 1){

				while ((j > 0) && (v[i] < v[j-1])) //important (j<0) to be first
					j--;

				v.insert(v.begin() + j, v[i]);
				v.erase(v.begin() + i + 1);
			}
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
			for(unsigned i = 0; i < v.size(); i++){
				unsigned min = i;
				for(unsigned j = i + 1; j < v.size(); j++){
					if(v[j] < v[min])
						min = j;
				}
				std::swap(v[i], v[min]);
			}
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