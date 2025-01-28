#pragma once

#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <mutex>

namespace LOGGING {

class Logger
{
private:
    static Logger *pinstance;
    static std::mutex mutex;

public:
    Logger(Logger &other) = delete;
    void operator=(const Logger &) = delete;

    Logger(/* args */) {};
    ~Logger() {};

    static Logger *getInstance();

    virtual void log_info(const std::string &message) = 0;

    virtual void log_error(const std::string &message) = 0;

    virtual void log_warning(const std::string &message) = 0;
};

} // namespace LOGGING

#endif // LOGGER_H