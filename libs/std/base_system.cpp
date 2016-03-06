//                    (C) 2016 SiLeader.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <developer_settings.hpp>
#include <ncxx/utility/function.hpp>

#include <cstdio>

namespace ncxx
{
    namespace detail
    {
        ncxx::utility::function<void(char)> print_char;
        ncxx::utility::function<void(char*)> print_str;
        ncxx::utility::function<char(void)> keyboard;
    }
    void initialize_lib(ncxx::utility::function<void(char)> print_char, ncxx::utility::function<void(char*)> print_str, ncxx::utility::function<char(void)> keyboard)
    {
        ncxx::detail::print_char=print_char;
        ncxx::detail::print_str=print_str;
        ncxx::detail::keyboard=keyboard;

        STD::detail::ins_stdin.count=STD::detail::ins_stdout.count=STD::detail::ins_stderr.count=0;
        STD::detail::ins_stdin.ptr=STD::detail::ins_stdout.ptr=STD::detail::ins_stderr.ptr=nullptr;
        STD::detail::ins_stdin.base=STD::detail::ins_stdout.base=STD::detail::ins_stderr.base=nullptr;
        STD::detail::ins_stdin.all_size=STD::detail::ins_stdout.all_size=STD::detail::ins_stderr.all_size=0;
        STD::detail::ins_stdin.access_mode=STD::detail::ins_stdout.access_mode=STD::detail::ins_stderr.access_mode=0xffff;
        STD::detail::ins_stdin.file_desc=0;
        STD::detail::ins_stdout.file_desc=1;
        STD::detail::ins_stderr.file_desc=2;

        STD::stdin=&STD::detail::ins_stdin;
        STD::stdout=&STD::detail::ins_stdout;
        STD::stderr=&STD::detail::ins_stderr;

    }
}
