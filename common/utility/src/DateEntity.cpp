#include "DateObj.h"
#include <StringUtils.hpp>

namespace cbtek {
namespace common {
namespace utility {

Date::Date()
{
    m_month=1;
    m_day=1;
    m_year=1970;
}

Date::Date(const size_t &month, const size_t &day, const size_t &year)
{
    m_month=month;
    m_day=day;
    m_year=year;
}

Date::Date(const size_t &dateInteger)
{
    std::string dateStr=StringUtils::toString(dateInteger);
    if (dateStr.size()==8)
    {
        m_year=StringUtils::toNumber<size_t>(dateStr.substr(0,4));
        m_month=StringUtils::toNumber<size_t>(dateStr.substr(4,2));
        m_day=StringUtils::toNumber<size_t>(dateStr.substr(6,2));
    }   
    else
    {
        m_month=1;
        m_day=1;
        m_year=1970;
    }
}

size_t Date::getMonth() const
{
    return m_month;
}

size_t Date::getDay() const
{
    return m_day;
}

size_t Date::getYear() const
{
    return m_year;
}

void Date::setMonth(const size_t &month)
{
    m_month=month;
}

void Date::setDay(const size_t &day)
{
    m_day=day;
}

void Date::setYear(const size_t &year)
{
    m_year=year;
}

size_t Date::toDateInteger() const
{
    std::string dateStr=StringUtils::toString(m_year)+
            (m_month<10?"0"+StringUtils::toString(m_month):StringUtils::toString(m_month))+
            (m_day<10?"0"+StringUtils::toString(m_day):StringUtils::toString(m_day));
    return StringUtils::toNumber<size_t>(dateStr);
}

bool Date::operator <(const Date &date) const
{
   return toDateInteger() < date.toDateInteger();
}

bool Date::operator <=(const Date &date) const
{
    return toDateInteger() <= date.toDateInteger();
}

bool Date::operator >(const Date &date) const
{
    return toDateInteger()>date.toDateInteger();
}

bool Date::operator >=(const Date &date) const
{
    return toDateInteger()>=date.toDateInteger();
}

bool Date::operator ==(const Date &date) const
{
    return toDateInteger()==date.toDateInteger();
}

bool Date::operator !=(const Date &date) const
{
    return toDateInteger()!=date.toDateInteger();
}

size_t Date::operator -(const Date &date) const
{

    size_t lowYear=0,highYear=0;
    size_t days = 0;
    if (m_year<date.getYear())
    {
        lowYear=m_year;
        highYear=date.getYear();
    }

    else if (m_year>date.getYear())
    {
        lowYear=date.getYear();
        highYear=m_year;
    }

    for (size_t a1 = lowYear;a1<highYear;++a1)
    {
        days+=365;
        if (Date(1,1,a1).isLeapYear())
        {
            days++;
        }
    }
    Date d1(date.getMonth(),date.getDay(),1901);
    Date d2(getMonth(),getDay(),1901);
    size_t d1Days = d1.getDays();
    size_t d2Days = d2.getDays();
    if (d1Days>d2Days)
    {
        days += d1Days-d2Days;
    }
    else
    {
        days += d2Days-d1Days;
    }

    return days;
}

bool Date::isLeapYear() const
{
//    The year is evenly divisible by 4;
//    If the year can be evenly divided by 100, it is NOT a leap year, unless;
//    The year is also evenly divisible by 400. Then it is a leap year.
    return ((m_year % 4 == 0 && m_year % 100 != 0) || m_year % 400 == 0);
}

size_t Date::getDays() const
{
    size_t daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    size_t days=0;
    for (size_t a1 = 0;a1<m_month-1;++a1)
    {
        if (a1 < 12)
        {
            if(a1==1 && isLeapYear())
            {
                days+=daysInMonth[a1]+1;
            }
            else
            {
                days+=daysInMonth[a1];
            }

        }

    }
    return days+(m_day);
}

}}}//namespace
