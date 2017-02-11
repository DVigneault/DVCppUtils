#include <dvInsertionSort.h>
#include <cstdlib>
#include <algorithm>
#include <cassert>

int main()
{

  std::vector<int> v(31);
  std::iota(v.begin(), v.end(), -15);
  std::random_shuffle(v.begin(), v.end());

  dv::InsertionSort(v);

  assert(std::is_sorted(v.cbegin(), v.cend()));

  return EXIT_SUCCESS;

}
