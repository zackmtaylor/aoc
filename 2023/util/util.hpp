#include <optional>
#include <string>
#include <vector>

namespace util
{
    std::optional<int> parsePart(int const argc, char const *const argv[]);

    std::vector<std::string> getLines(std::string const &filename);
}
