
#include "utility/inc/StringUtils.hpp"

namespace cbtek {
namespace common {
namespace utility {
namespace DateUtils {

static inline std::string toShortDateString(const DateEntity &date, const std::string &format)
{
    std::string dateStr=format;

    if (StringUtils::contains(dateStr,"yyyy"))
    {
        dateStr=StringUtils::replace(dateStr,"yyyy",StringUtils::toString(date.getYear()));
    }

    if(StringUtils::contains(dateStr,"mm"))
    {
        dateStr=StringUtils::replace(dateStr,"mm",(date.getMonth()<10?"0"+StringUtils::toString(date.getMonth()):StringUtils::toString(date.getMonth())));
    }

    if(StringUtils::contains(dateStr,"dd"))
    {
        dateStr=StringUtils::replace(dateStr,"dd",(date.getDay()<10?"0"+StringUtils::toString(date.getDay()):StringUtils::toString(date.getDay())));
    }
    return dateStr;
}

static inline std::string toLongDateString(const DateEntity &date)
{
    std::string months[12] =
    {
        "January","February","March","April",
        "May","June","July","August",
        "September","October","November","December"
    };

    if (date.getMonth() <13)
    {
        return months[date.getMonth()-1]+" "+StringUtils::toString(date.getDay())+", "+StringUtils::toString(date.getYear());
    }
    return "";
}

static inline DateEntity getCurrentDate()
{
    time_t t = time(0);
    struct tm * now = localtime( & t );
    return DateEntity(now->tm_mon + 1,now->tm_mday,now->tm_year + 1900);
}

}}}//namespace
