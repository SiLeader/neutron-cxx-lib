//                    (C) 2016 SiLeader.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <developer_settings.hpp>

#include <typeinfo>
#ifdef ENABLE_CTTI
namespace ncxx
{
    namespace ctti
    {
        namespace detail
        {
            template<class To>To anypointer_cast(void *from)
            {
                union{void *from, To to} uc;
                uc.from=from;
                return uc.to;
            }

            template<class T>struct dummy{static void f(){}};
        }

        template<class T>std::type_info type_id(T)
        {
            std::type_info ti(&ncxx::ctti::detail::dummy<T>::f);
            return ti;
        }

        template<class To, class From> To downstatic_cast(From from)
        {

        }
    }
}
#endif
