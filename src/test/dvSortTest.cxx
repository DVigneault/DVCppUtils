#include <dvInsertionSort.h>
#include <dvMergeSort.h>
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <iostream>

int main()
{

  std::vector<int> v(31);
  std::iota(v.begin(), v.end(), -15);

  ////////////////////
  // Insertion Sort //
  ////////////////////

  std::random_shuffle(v.begin(), v.end());
  dv::InsertionSort(v);
  assert(std::is_sorted(v.cbegin(), v.cend()));

  ////////////////
  // Merge Sort //
  ////////////////

  std::random_shuffle(v.begin(), v.end());
  for (const auto i : v) std::cout << i << ' ';
  std::cout << std::endl;
  dv::MergeSort(v.begin(), v.end());
  assert(std::is_sorted(v.cbegin(), v.cend()));
  for (const auto i : v) std::cout << i << ' ';
  std::cout << std::endl;

  return EXIT_SUCCESS;

}
