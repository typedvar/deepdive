#pragma once

#include <vector>
#include <algorithm>
#include <sstream>

namespace dialgaUtils
{
    template<typename T>
    std::string vec2Str(std::vector<T>& cont)
    {
        std::stringstream ss;
        std::for_each(cont.begin(), cont.end(), [&](int x) {
            if (x == std::numeric_limits<T>::min())
            {
                ss << "x";
            }
            else
            {
                ss << x;
            }
            });
        return ss.str();
    }
}
