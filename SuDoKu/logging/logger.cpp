#include "logger.h"

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>

using namespace LOGGING;


class BoostLogger : public Logger
{
public:
    BoostLogger();
    ~BoostLogger();

    void log_info(const std::string &message) override;
    void log_error(const std::string &message) override;
    void log_warning(const std::string &message) override;
};

Logger *Logger::pinstance = nullptr;
std::mutex Logger::mutex;


BoostLogger::BoostLogger()
{
    // Set up logging to console
    boost::log::add_console_log(std::cout, boost::log::keywords::format = "[%TimeStamp%] [%ThreadID%]: %Message%");

    // Add common attributes like timestamp
    boost::log::add_common_attributes();
}

BoostLogger::~BoostLogger()
{
}

Logger *Logger::getInstance()
{
    if (pinstance == nullptr)
    {
        std::lock_guard<std::mutex> lock(mutex);
        if (pinstance == nullptr)
        {
            pinstance = new BoostLogger();
        }
    }
    return pinstance;
}

void BoostLogger::log_info(const std::string &message) {
    BOOST_LOG_TRIVIAL(info) << message;
}

void BoostLogger::log_error(const std::string &message) {
    BOOST_LOG_TRIVIAL(error) << message;
}

void BoostLogger::log_warning(const std::string &message) {
    BOOST_LOG_TRIVIAL(warning) << message;
}