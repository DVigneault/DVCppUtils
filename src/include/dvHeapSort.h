#ifndef dv_HeapSort_h
#define dv_HeapSort_h

#include <algorithm>

/*
- O(nlog(n)) sorting algorithm
- Based on the `heap' data structure, which is a complete, binary tree
  where the highest priority node is always placed at the root.
- Not stable (doesn't preserve order of equal elements)
- Naive implementation requires additonal space, but clever implementations
  exist to do it in place.
*/

namespace dv
{

template<typename It>
void HeapSort(const It b, const It e)
{
  std::make_heap(b, e);
  std::sort_heap(b, e);
}

}

#endif
