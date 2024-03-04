#include "..\include\Date.h"
#include "..\include\Exception.h" 
#include <chrono>

using Util::Date;

using Exception::DateException;


Date::Date(int day, int month, int year)
    : m_day{ day }, m_month{ month }, m_year{ year }
{
    if (m_day < 1 || m_day > daysInMonth() || m_month < 1 || m_month > 12 || m_year < 1)
    {
       throw DateException{ "Date: Invalid date" };
    }
}

Date Date::getCurrentDate()
{
    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);
    std::tm currentTime;
    localtime_s(&currentTime, &time);
  
    int d = currentTime.tm_mday;
    int m = currentTime.tm_mon + 1;
    int y = currentTime.tm_year + 1900;

    return { d, m, y };  
}

void Date::refreshDate()
{
    Date systemDate = Date::getCurrentDate();

    if (!(*this == systemDate))
    {
        m_day = systemDate.m_day;
        m_month = systemDate.m_month;
        m_year = systemDate.m_year;

        m_cacheValid = false;
    }
};

std::string Date::getStringRep() const
{
    if (!m_cacheValid)
    {
        m_cache = "";
        m_cache =
            std::string{ (m_day < 10 ? "0" : "") }
            + std::to_string(m_day) 
            + "/" 
            + (m_month < 10 ? "0" : "")
            + std::to_string(m_month)
            +("/")
            +(m_year < 1000 ? (m_year < 100 ? ((m_year < 10) ? "000" : "00") : "0") : "")
            +std::to_string(m_year);

        m_cacheValid = true;
    }
    return m_cache;
}

bool Date::operator==(const Date& date) const noexcept
{
    return (m_day == date.m_day && m_month == date.m_month && m_year == date.m_year);
}

bool Date::operator!=(const Date& date) const noexcept
{
    return !(*this == date);
}

bool Date::operator<(const Date& date) const noexcept
{
    if (m_year < date.m_year)
    {
        return true;
    }
    else if (m_year == date.m_year)
    {
        if (m_month < date.m_month)
        {
            return true;
        }
        else if (m_month == date.m_month)
        {
            if (m_day < date.m_day)
            {
                return true;
            }
        }
    }
    return false;
}

bool Date::operator>(const Date& date) const noexcept
{
    return !(*this < date || *this == date);
}

bool Date::operator<=(const Date& date) const noexcept
{
    return (*this < date || *this == date);
}

bool Date::operator>=(const Date& date) const noexcept
{
    return (*this > date || *this == date);
}

void Date::adjustDate()
{
    while (m_day > daysInMonth())
    {
        m_day -= daysInMonth();
        if (++m_month > 12)
        {
            m_month = 1;
            ++m_year;
        }
    }
}

int Date::daysInMonth() const
{
    if (m_month == 2)
    {
        return isLeapYear() ? 29 : 28;
    }
    else if (m_month == 4 || m_month == 6 || m_month == 9 || m_month == 11)
    {
        return 30;
    }
    else
    {
        return 31;
    }
}

Date& Date::addDays(int days)
{
    m_day += days;
    adjustDate();
    m_cacheValid = false;
    return *this;
}

Date& Date::addMonths(int months)
{
    m_month += months;
    while (m_month > 12)
    {
        m_year++;
        m_month -= 12;
    }
    m_cacheValid = false;
    return *this;
}
Date& Date::addYears(int n)
{
    m_year += n;
    m_cacheValid = false;
    return *this;
}

Date& Date::setDay(int day)
{
    if (day < 1 || day > daysInMonth())
    {
        throw DateException{ "Day: Invalid day" };
    }
    m_day = day;
    m_cacheValid = false;
    return *this;
}
Date& Date::setMonth(int month)
{
    if (month < 1 || month > 12)
    {
       throw DateException{ "Date: Invalid Month" };
    }

    m_month = month;
    m_cacheValid = false;
    return *this;
}
Date& Date::setYear(int year)
{
    if (year < 1)
    {
       throw DateException{ "Date: Invalid Year" };
    }
    m_year = year;
    m_cacheValid = false;
    return *this;
}
void Date::setDate(int day, int month, int year)
{

        setDay(day);
        setMonth(month);
        setYear(year);

    m_cacheValid = false;
}

std::ostream& Util::operator<<(std::ostream& stream, const Date& date)
{
        stream << (date.m_day < 10 ? "0" : "");
        stream << "/";
        stream << (date.m_month < 10 ? "0" : "");
        stream << date.m_month;
        stream << "/";
        stream << (date.m_year < 1000 ? (date.m_year < 100 ? ((date.m_year < 10) ? "000" : "00") : "0") : "");
        stream << date.m_year;

    return stream;
}
