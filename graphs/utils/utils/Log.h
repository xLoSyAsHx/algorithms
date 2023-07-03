#pragma once

#include <iostream>
#include <string_view>

class Log
{
public:
    template<typename... Args>
    static void AddErr(const std::string_view format, Args... args);

    template<typename... Args>
    static void AddMsg(const std::string_view format, Args... args);

private:
    Log() {}
};

template<typename... Args>
void Log::AddErr(const std::string_view format, Args... args)
{
    std::printf("[ERROR] ");
    std::printf(format.data(), args...);
    std::printf("\n");
    std::fflush(stdout);
}

template<typename ...Args>
inline void Log::AddMsg(const std::string_view format, Args ...args)
{
    std::printf("[NORMAL] ");
    std::printf(format.data(), args...);
    std::printf("\n");
    std::fflush(stdout);
}
