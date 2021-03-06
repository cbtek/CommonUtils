/**
MIT License

Copyright (c) 2016 cbtek

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#pragma once

#include "utility/inc/Font.h"

namespace cbtek {
namespace common {
namespace utility {

namespace fontStyle{
enum FontStyle
{
    NORMAL=0,
    HEADING_1,
    HEADING_2,
    HEADING_3,
    HEADING_4,
    HEADING_5,
    HEADING_6,
    HEADING_7,
    HEADING_8,
    HEADING_9,
    HEADING_10,
    SYSTEM_SMALL,
    SYSTEM_MEDIUM,
    SYSTEM_BIG
};

}
class FontFactory
{

public:
    /**
     * @brief create
     * @param style
     * @return
     */
    static Font create(const fontStyle::FontStyle & style);

    /**
     * @brief create
     * @param fontString
     * @return
     */
    static Font create(const std::string & fontString);

private:
    FontFactory();
    FontFactory(const FontFactory &);
    FontFactory& operator=(const FontFactory&);
};

}}}//namespace
