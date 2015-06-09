#ifndef SELECTIONSORT
#define SELECTIONSORT

#include <vector>
#include <algorithm>

namespace dra{
	namespace sort{
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
	}
}

#endif //SELECTIONSORT