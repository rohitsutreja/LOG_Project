#include <ctime>
#include "..\include\Date.h"
#include "String.h"

using Util::Date;
using Util::String;


Date::Date(int day, int month, int year)
    : m_day{day}, m_month{month}, m_year{year}
{
    if (m_day < 1 || m_day > daysInMonth() || m_month < 1 || m_month > 12 || m_year < 1)
    {
    
    }
}

Date Date::getCurrentDate()
{
    return {2, 2, 2024};
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

String Date::getStringRep() const
{
    if (!m_cacheValid)
    {
        m_cache = "";
        m_cache
            .append(m_day < 10 ? "0" : "")
            .append(String::toString(m_day))
            .append("/")
            .append(m_month < 10 ? "0" : "")
            .append(String::toString(m_month))
            .append("/")
            .append(m_year < 1000 ? (m_year < 100 ? ((m_year < 10) ? "000" : "00") : "0") : "")
            .append(String::toString(m_year));

        m_cacheValid = true;
    }
    return m_cache;
}

bool Date::operator==(const Date &date) const
{
    return (m_day == date.m_day && m_month == date.m_month && m_year == date.m_year);
}

bool Date::operator!=(const Date &date) const
{
    return !(*this == date);
}

bool Date::operator<(const Date &date) const
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

bool Date::operator>(const Date &date) const
{
    return !(*this < date || *this == date);
}

bool Date::operator<=(const Date &date) const
{
    return (*this < date || *this == date);
}

bool Date::operator>=(const Date &date) const
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

Date &Date::addDays(int days)
{
    m_day += days;
    adjustDate();
    m_cacheValid = false;
    return *this;
}

Date &Date::addMonths(int months)
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
Date &Date::addYears(int n)
{
    m_year += n;
    m_cacheValid = false;
    return *this;
}

Date &Date::setDay(int day)
{
    if (day < 1 || day > daysInMonth())
    {
      
    }
    m_day = day;
    m_cacheValid = false;
    return *this;
}
Date &Date::setMonth(int month)
{
    if (month < 1 || month > 12)
    {
        
    }

    m_month = month;
    m_cacheValid = false;
    return *this;
}
Date &Date::setYear(int year)
{
    if (year < 1)
    {
        
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

std::ostream &Util::operator<<(std::ostream &stream, const Date &date)
{
    stream << date.getStringRep();
    return stream;
}
