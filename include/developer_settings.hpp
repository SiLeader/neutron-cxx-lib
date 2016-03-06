//                    (C) 2016 SiLeader.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <ncxx/utility/function.hpp>

// name of std namespace (default=kstd)
#define STD kstd

// Neutron.CTTI(Compile-Time Type Identification) is RTTI like system
// if you want to use it,define this.
#define ENABLE_CTTI

namespace ncxx
{
    namespace detail
    {
        extern ncxx::utility::function<void(char)> print_char;
        extern ncxx::utility::function<void(char*)> print_str;
        extern ncxx::utility::function<char(void)> keyboard;
    }
    void initialize_lib(ncxx::utility::function<void(char)> print_char, ncxx::utility::function<void(char*)> print_str, ncxx::utility::function<char(void)> keyboard);
}
