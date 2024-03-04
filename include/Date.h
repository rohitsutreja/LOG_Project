#include <iostream>
#include <string>

#include "..\include\Exception.h" 



#ifndef DATE_H
#define DATE_H
using String = std::string;
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

       Date& addDays(int n);
       Date& addMonths(int n);
       Date& addYears(int n);
       Date& setDay(int day);
       Date& setMonth(int month);
       Date& setYear(int year);
       void setDate(int day, int month, int year);

       void refreshDate();
       String getStringRep() const;

       bool operator==(const Date& date) const noexcept;
       bool operator!=(const Date& date) const noexcept;
       bool operator<(const Date& date) const noexcept;
       bool operator>(const Date& date) const noexcept;
       bool operator<=(const Date& date) const noexcept;
       bool operator>=(const Date& date) const noexcept;

       friend std::ostream& operator<<(std::ostream& stream, const Date& date);

       constexpr int getDay() const noexcept
       {
           return m_day;
       }
       constexpr int getMonth() const noexcept
       {
           return m_day;
       }
       constexpr int getYear() const noexcept
       {
           return m_day;
       }
       constexpr bool isLeapYear() const noexcept
       {
           return ((m_year % 4 == 0 && m_year % 100 != 0) || (m_year % 400 == 0));
       }
   };

   std::ostream& operator<<(std::ostream& stream, const Date& date);
}

#endif