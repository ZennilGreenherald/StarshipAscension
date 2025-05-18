#ifndef CAPTAINS_LOG_HPP
#define CAPTAINS_LOG_HPP

#include <string>
#include <vector>

class CaptainsLog
{
private:
    std::vector<std::string> captainsLog;  // To hold the Captain's Log entries
    std::string captainsLogFile = "captains_log.txt";  // Default file name for the log

public:
    // Function to add an entry to the Captain's Log
    void addToCaptainsLog(const std::string &entry);

    // Function to initialize the Captain's Log (load from file or create new)
    void initializeCaptainsLog();

    // Function to create (clear) the Captain's Log
    void createCaptainsLog();

    // Function to save the current Captain's Log to a file
    void saveCaptainsLog();

    // Function to load the Captain's Log from a file
    void loadCaptainsLog();

    // Function to delete the Captain's Log file
    void deleteCaptainsLog();
};

#endif // CAPTAINS_LOG_HPP
