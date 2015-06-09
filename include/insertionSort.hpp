#ifndef INSERTIONSORT
#define INSERTIONSORT

#include <vector>

namespace dra{
	namespace sort{
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
	}
}

#endif //INSERTIONSORT