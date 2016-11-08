#ifndef DATE_H
#define DATE_H

#include <cstdlib>
#include <string>

namespace cbtek {
namespace common {
namespace utility {
class Date
{

public:
    Date();

    Date(const size_t & month, const size_t & day, const size_t & year);

    Date(const size_t & dateInteger);

    size_t getMonth() const;

    size_t getDay() const;

    size_t getYear() const;

    void setMonth(const size_t & month);

    void setDay(const size_t & day);

    void setYear(const size_t & year);

    size_t toDateInteger() const;

    bool operator<(const Date & date) const;

    bool operator<=(const Date & date) const;

    bool operator>(const Date & date) const;

    bool operator>=(const Date & date) const;

    bool operator==(const Date & date) const;

    bool operator!=(const Date & date) const;

    size_t operator-(const Date& date)const;

    bool isLeapYear() const;

    size_t getDays() const;
private:   
    size_t m_month,m_day,m_year;

};
}}}//namespace
#endif // DATE_H
