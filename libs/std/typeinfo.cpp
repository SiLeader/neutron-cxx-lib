//                    (C) 2016 SiLeader.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <typeinfo>

std::type_info::type_info(void* id)
    : m_id(id)
{

}

bool std::type_info::operator==(std::type_info& tf)
{
    return (tf.m_id==this->m_id);
}

bool std::type_info::operator!=(std::type_info& tf)
{
    return !(tf==(*this));
}
