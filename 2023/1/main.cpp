#include "../util/util.hpp"

#include <functional>
#include <iostream>
#include <numeric>

namespace
{
    int getDigitCalibrationValue(std::string const &line)
    {
        auto const firstDigit{std::find_if(line.begin(), line.end(), isdigit)};
        auto const lastDigit{std::find_if(line.rbegin(), line.rend(), isdigit)};

        std::string const calibrationValue{*firstDigit, *lastDigit};
        return std::stoi(calibrationValue);
    }

    int getWrittenCalibrationValue(std::string const &)
    {
        // todo
        return 0;
    }

}

int main(int const argc, char const *const argv[])
{
    std::optional<int> const part{util::parsePart(argc, argv)};
    if (!part)
    {
        std::cerr << "No part specified\n";
        return 1;
    }

    // use different method based on part
    std::function<int(std::string const &)> getCalibrationValue = part == 1 ? getDigitCalibrationValue : getWrittenCalibrationValue;

    auto const lines = util::getLines("input");
    int const total = std::accumulate(lines.begin(), lines.end(), 0, [&](int total, std::string const &line)
                                      { return total + getCalibrationValue(line); });

    std::cout << total << "\n";

    return 0;
}
