#ifndef DATE_H
#define DATE_H

#include <iostream>
#include "String.h"
#include <string>

namespace Util
{
    class Date
    {
    private:
        int m_day;
        int m_month;
        int m_year;
        mutable bool m_cacheValid = false;
        mutable String m_cache;

        void adjustDate();
        int daysInMonth() const;

    public:
        Date(int day, int month, int year)
            : m_day{day}, m_month{month}, m_year{year}
        {
            if(m_day < 1 || m_day > daysInMonth() || m_month < 1 || m_month > 12 || m_year < 1){
                // will handle this later
            }
        }
        int getDay() const
        {
            return m_day;
        }
        int getMonth() const
        {
            return m_day;
        }
        int getYear() const
        {
            return m_day;
        }

        Date &setDay(int day)
        {
            if (day < 1 || day > daysInMonth())
            {
                // will handle this later
            }
            m_day = day;
            m_cacheValid = false;
            return *this;
        }
        Date &setMonth(int month)
        {
            if (month < 1 || month > 12)
            {
                // will handle this later
            }

            m_month = month;
            m_cacheValid = false;
            return *this;
        }
        Date &setYear(int year)
        {
            if (year < 1)
            {
                // will handle this later
            }
            m_year = year;
            m_cacheValid = false;
            return *this;
        }
        bool isLeapYear() const
        {
            return ((m_year % 4 == 0 && m_year % 100 != 0) || (m_year % 400 == 0));
        }
        void setDate(int day, int month, int year)
        {
            setDay(day);
            setMonth(month);
            setYear(year);
            m_cacheValid = false;
        }

        static Date getCurrentDate();

        void print() const;
        void refreshDate();
        String getStringRep() const;

        Date &addDays(int n);
        Date &addMonths(int n);
        Date &addYears(int n);

        bool operator==(const Date &date) const;
        bool operator!=(const Date &date) const;
        bool operator<(const Date &date) const;
        bool operator>(const Date &date) const;
        bool operator<=(const Date &date) const;
        bool operator>=(const Date &date) const;

        friend std::ostream &operator<<(std::ostream &stream, const Date &date);
    };

    std::ostream &operator<<(std::ostream &stream, const Date &date);
}

#endif