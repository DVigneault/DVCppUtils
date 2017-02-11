#ifndef dvJoin_h
#define dvJoin_h

#include <string>
#include <vector>

namespace dv
{

std::string
Join(const std::string &delim,
     const std::vector<std::string>::const_iterator begin,
     const std::vector<std::string>::const_iterator end);

}

#endif
