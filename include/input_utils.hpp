#ifndef INPUT_UTILS_HPP
#define INPUT_UTILS_HPP

#include <string>

// Function to sanitize input by converting to lowercase and removing spaces
std::string sanitizeInput(const std::string &input);

// Function to simulate an initialization step with a delay
void initializeStep(const std::string &step);

#endif // INPUT_UTILS_HPP
