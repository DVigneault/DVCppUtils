#ifndef dv_InsertionSort_h
#define dv_InsertionSort_h

#include <vector>

/*
dv::InsertionSort implements a simple sorting algorithm.

Advantages:
- Simple Implementation
- Efficient for small data sets
- Efficiency increases for sets that are substantially sorted

Disadvantages:
- Inefficient for large lists - O(N^2)
*/

namespace dv
{
template<typename T>
void InsertionSort(std::vector<T> &v)
{
  for (std::size_t i = 1; i < v.size(); ++i)
    {
    T temp = v[i];
    int j = i - 1;
    for (; (j >= 0 && v[j] > temp); --j)
      {
      v[j+1] = v[j];
      }
    v[j+1] = temp;
    }
}
}

#endif
