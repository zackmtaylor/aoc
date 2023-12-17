#include <algorithm>
#include <cstring>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

int getDigitCalibrationValue(std::string const &line)
{
    auto const firstDigit{std::find_if(line.begin(), line.end(), ::isdigit)};
    auto const lastDigit{std::find_if(line.rbegin(), line.rend(), ::isdigit)};

    std::string const calibrationValue{*firstDigit, *lastDigit};
    return std::stoi(calibrationValue);
}

int getWrittenCalibrationValue(std::string const &line)
{
    // todo
    return 0;
}

int main(int const argc, char const *const argv[])
{
    if (argc == 1)
    {
        std::cerr << "Provide part to solve.\n";
        return 1;
    }

    std::function<int(std::string const &)> getCalibrationValue;

    if (std::strcmp("1", argv[1]) == 0)
    {
        getCalibrationValue = getDigitCalibrationValue;
    }
    else if (std::strcmp("2", argv[1]) == 0)
    {
        getCalibrationValue = getWrittenCalibrationValue;
    }
    else
    {
        std::cerr << "Invalid part to solve.\n";
        return 1;
    }

    int total{0};
    std::fstream input{"input"};
    std::string line;

    while (std::getline(input, line))
    {
        total += getCalibrationValue(line);
    }

    input.close();

    std::cout << total << "\n";

    return 0;
}
