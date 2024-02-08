#ifndef DATE_H
#define DATE_H

#include <iostream>
#include "String.h"
#include "Exception.h"
#include <string>


namespace Util
{
    class Date
    {
    private:
        int m_day{};
        int m_month{};
        int m_year{};
        mutable bool m_cacheValid = false;
        mutable String m_cache;

        void adjustDate();
        int daysInMonth() const;

    public:
        Date(int day, int month, int year);
        
        static Date getCurrentDate();

        Date &addDays(int n);
        Date &addMonths(int n);
        Date &addYears(int n);
        Date &setDay(int day);
        Date &setMonth(int month);
        Date &setYear(int year);
        void setDate(int day, int month, int year);

        void refreshDate();
        String getStringRep() const;

        bool operator==(const Date &date) const;
        bool operator!=(const Date &date) const;
        bool operator<(const Date &date) const;
        bool operator>(const Date &date) const;
        bool operator<=(const Date &date) const;
        bool operator>=(const Date &date) const;

        friend std::ostream &operator<<(std::ostream &stream, const Date &date);

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
        bool isLeapYear() const
        {
            return ((m_year % 4 == 0 && m_year % 100 != 0) || (m_year % 400 == 0));
        }
    };

    std::ostream &operator<<(std::ostream &stream, const Date &date);
}

#endif