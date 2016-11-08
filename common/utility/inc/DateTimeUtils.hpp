//#-------------------------------------------------
//#
//# File DateTimeUtils.h created by cberry on 11-07-2015 at 10:26:38 PM
//#
//#-------------------------------------------------

#ifndef _CBTEK_COMMON_UTILITY_DATETIMEUTILS_HPP_
#define _CBTEK_COMMON_UTILITY_DATETIMEUTILS_HPP_

#include "TimeUtils.h"
#include "DateUtils.h"
#include "StringUtils.hpp"

namespace cbtek{
namespace common{
namespace utility{
namespace DateTimeUtils{

inline std::string getDisplayTimeStamp()
{
    return (DateUtils::toShortDateString(DateUtils::getCurrentDate(),"mm/dd/yyyy")+" at "+StringUtils::toString(TimeUtils::to12HourTimeString(TimeUtils::getCurrentTime())));
}

inline std::string getTimeStamp()
{
    return (DateUtils::toShortDateString(DateUtils::getCurrentDate(),"yyyymmdd")+"T"+StringUtils::toString(TimeUtils::getCurrentTime().toTimeInteger())+"."+StringUtils::toString((std::uint64_t)TimeUtils::getMillisecondsNow()));
}

}}}} //namespace
#endif //_CBTEK_COMMON_UTILITY_DATETIMEUTILS_HPP_
