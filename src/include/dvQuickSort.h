#ifndef dv_QuickSort_h
#define dv_QuickSort_h

#include <algorithm>

namespace dv
{

template<class It, class UnaryPredicate>
It impl_partition(It first, It last, UnaryPredicate p)
{
    // Find the first value where the predicate is false.
    first = std::find_if_not(first, last, p);
    // If no elements cause the predicate to be false, return the first.
    if (first == last) return first;

    // Loop from (first false + 1) to last;
    // If the element is true, switch with first and increment.
    for (It i = std::next(first); i != last; ++i)
      {
      if (p(*i))
        {
        std::iter_swap(i, first);
        ++first;
        }
      }
    return first;
}

template<typename It>
void QuickSort(It b, It e)
{

  if (b == e) return;

  // Get some pivot.
  const auto pivot = *std::next(b, std::distance(b, e) / 2);

  const auto func1 = [pivot](const typename It::value_type &element){ return element<pivot; };
  const auto func2 = [pivot](const typename It::value_type &element){ return element==pivot; };

//  const auto m1 = impl_partition(b, e, func1);
//  const auto m2 = impl_partition(m1, e, func2);
  const auto m1 = std::partition(b, e, func1);
  const auto m2 = std::partition(m1, e, func2);

  QuickSort(b, m1);
  QuickSort(m2, e);

}

}

#endif
