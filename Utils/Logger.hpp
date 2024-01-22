#pragma once

#include <algorithm>
#include <chrono>
#include <format>
#include <fstream>
#include <iostream>
#include <mutex>
#include <string>
#include <vector>

namespace Utils
{

enum class LogLevel
{
    INFO,
    DEBUG,
    WARNING,
    ERROR
};

class Logger
{

public:
    ~Logger();

    static Logger& getInstance()
    {
        static Logger instance;
        return instance;
    }

    // Log a message to all output destinations
    void log(const std::string& text, LogLevel level = LogLevel::INFO) {
        std::string formattedMessage = formatLogMessage(text, level);

        std::lock_guard<std::mutex> lock(m_mutex);

        for (auto destination : m_outputDestinations) {
            if (destination) {
                (*destination) << formattedMessage;
            }
        }
    }

    // Add an output destination
    void addOutputDestination(std::ostream& output) {
        m_outputDestinations.push_back(&output);
    }

    // Remove an output destination
    void removeOutputDestination(std::ostream& output) {
        auto it = std::find(m_outputDestinations.begin(), m_outputDestinations.end(), &output);
        if (it != m_outputDestinations.end()) {
            m_outputDestinations.erase(it);
        }
    }
private:

    Logger();

    void setLogLevel(LogLevel level);

    std::string getTimestamp()
    {
        std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

        std::string s(30, '\0');
        std::strftime(&s[0], s.size(), "%Y-%m-%d %H:%M:%S", std::localtime(&now));

        return s;
    };

    std::string getLogLevel(LogLevel lvl)
    {
        switch (lvl)
        {
        case LogLevel::INFO: return "INFO";
        case LogLevel::DEBUG: return "DEBUG";
        case LogLevel::WARNING: return "WARNING";
        case LogLevel::ERROR: return "ERROR";
        default: return "DEBUG";
        }
    };

    // Format log message with timestamp and log level
    std::string formatLogMessage(const std::string& text, LogLevel level) {
        std::string lvl = getLogLevel(level);
        std::string timestamp = getTimestamp();

        std::string message = std::string(" -- ") + "[" + lvl + "] " + text + "\n";
        // std::string message = std::string("asdf ") + "jklö";
        return message;
    }

    std::vector<std::ostream*> m_outputDestinations;
    std::mutex m_mutex;
};

Logger::Logger()
{
}

Logger::~Logger()
{}

}