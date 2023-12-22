#include "util.hpp"

#include <cstring>
#include <fstream>

namespace util
{
    std::optional<int> parsePart(int const argc, char const *const argv[])
    {
        if (argc > 1 && std::strcmp("1", argv[1]) == 0)
        {
            return 1;
        }
        else if (argc > 1 && std::strcmp("2", argv[1]) == 0)
        {
            return 2;
        }
        else
        {
            return std::nullopt;
        }
    }

    std::vector<std::string> getLines(std::string const &filename)
    {
        std::vector<std::string> lines;
        std::fstream input{filename};
        std::string line;
        while (std::getline(input, line))
        {
            lines.push_back(line);
        }
        input.close();
        return lines;
    }
}
