#include "../include/Util.h"

std::string Util::getLogTimeString()
{
    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);
    std::tm currentTime;
    localtime_s(&currentTime, &time);

    int d = currentTime.tm_mday;
    int m = currentTime.tm_mon + 1;
    int y = currentTime.tm_year + 1900;

    int H = currentTime.tm_hour;
    int M = currentTime.tm_min;
    int S = currentTime.tm_sec + 1;

    return {
        (d < 10 ? "0" : "") + std::to_string(d) + "/" + (m < 10 ? "0" : "") + std::to_string(m) + "/" + std::to_string(y) + " " + (H < 10 ? "0" : "") + std::to_string(H) + ":" + (M < 10 ? "0" : "") + std::to_string(M) + ":" + (S < 10 ? "0" : "") + std::to_string(S)};
}
