#pragma once

#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>

namespace dialga
{
    namespace utils
    {
        template<typename T>
        std::string vec2Str(const std::vector<T>& cont, const std::string& separator)
        {
            std::stringstream ss;
            if (!cont.empty())
            {
                std::for_each(cont.begin(), cont.end() - 1, [&](int x) {
                    ss << x << separator;
                    });
                ss << cont[cont.size() - 1];
            }
            return ss.str();
        }

        void intStr2Vec(const std::string& input, const std::string& separator, std::vector<int>& out)
        {
            std::string::size_type startPos = 0;
            std::string::size_type index = input.find(separator, startPos);
            size_t separatorLen = separator.length();
            while (std::string::npos != index)
            {
                std::string token = input.substr(startPos, startPos + index);
                out.emplace_back(std::stoi(token));
                startPos = index + separatorLen;
                index = input.find(separator, startPos);
            }
        }

        void readInts(const std::string& file, const std::string& separator, std::vector<int>& out)
        {
            std::ifstream ifs;
            ifs.open(file);
            if (ifs.is_open())
            {
                std::string line;
                if (std::getline(ifs, line))
                {
                    intStr2Vec(line, separator, out);
                }
            }
        }

        void loadTest(const std::string& fileName, std::vector<int>& input)
        {
            std::string separator = " ";
            readInts(fileName, separator, input);
        }

        static std::vector<int>& fetchTest(const std::string& fileName)
        {
            static std::vector<int> input;
            if (input.empty())
            {
                loadTest(fileName, input);
            }
            return input;
        }
    }
}


// end of file
