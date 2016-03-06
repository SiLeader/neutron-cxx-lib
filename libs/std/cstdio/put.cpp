//                    (C) 2016 SiLeader.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <developer_settings.hpp>
#include <cstdio>

namespace STD
{
    int putchar(int ch)
    {
        ncxx::utility::detail::print_char(static_cast<char>(ch));
        return ch;
    }
}
