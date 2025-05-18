#include <string>         // For std::string
#include <algorithm>      // For std::transform, std::remove_if
#include <cctype>         // For std::tolower, std::isspace
#include <iostream>       // For std::cout, std::endl, std::flush
#include <thread>         // For std::this_thread::sleep_for
#include <chrono>         // For std::chrono::milliseconds

#include "input_utils.hpp"

std::string sanitizeInput(const std::string &input)
{
    std::string sanitized = input;
    std::transform(sanitized.begin(), sanitized.end(), sanitized.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    sanitized.erase(std::remove_if(sanitized.begin(), sanitized.end(), ::isspace), sanitized.end());
    return sanitized;
}

void initializeStep(const std::string &step)
{
    std::cout << "Initializing " << step << "..." << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Simulate processing delay
    std::cout << " Done!" << std::endl;
}
