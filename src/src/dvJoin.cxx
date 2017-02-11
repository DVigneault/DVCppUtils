#include <dvJoin.h>
#include <iterator>
#include <cassert>

namespace dv
{

std::string
Join_impl(const std::string &delim,
          const std::vector<std::string>::const_iterator begin,
          const std::vector<std::string>::const_iterator end,
          const std::string &append = "")
{

  switch (std::distance(begin, end))
    {
    case 1: return *begin + delim + append; break;
    default: return Join_impl(delim, begin, end - 1, *(end - 1) + delim + append); break;
    }

}

std::string
Join(const std::string &delim,
     const std::vector<std::string>::const_iterator begin,
     const std::vector<std::string>::const_iterator end)
{
  const auto d = std::distance(begin, end);
  assert(d >= 0);
  switch (std::distance(begin, end))
    {
    case 0: return ""; break;
    case 1: return *begin; break;
    default: return Join_impl(delim, begin, end - 1, *(end - 1));
    }
}

}
