//                    (C) 2016 SiLeader.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <developer_settings.hpp>

namespace STD
{
    void *memcpy(void *dest, const void *src, STD::size_t n)
    {
        auto d=reinterpret_cast<unsigned char*>(dest), s=reinterpret_cast<unsigned char*>(src);
        for(STD::size_t i=0; i<n; ++i){
            d[i]=s[i];
        }
        return dest;
    }

    void *memmove(void *dest, const void *src, STD::size_t n)
    {
        auto tmp[n], d=reinterpret_cast<unsigned char*>(dest), s=reinterpret_cast<unsigned char*>(src);
        for(STD::size_t i=0; i<n; ++i){
            tmp[i]=s[i];
            d[i]=tmp[i];
        }
        return dest;
    }

    int memcmp(const void *p1, const void *p2, STD::size_t n)
    {
        auto s1=reinterpret_cast<unsigned char*>(p1), s2=reinterpret_cast<unsigned char*>(p2);
        for(STD::size_t i=0; i<n; ++i){
            if(s1[i]!=s2[i])return s1[i]-s2[i];
        }
        return 0;
    }

    void *memchr(const void *src, int c, STD::size_t n)
    {
        auto ch=static_cast<unsigned char>(c);
        auto s=reinterpret_cast<unsigned char*>(src);
        for(STD::size_t i=0; i<n; ++i){
            if(s[i]==ch)return s+i;
        }
        return nullptr;
    }

    void *memset(void *dest, int c, STD::size_t n)
    {
        auto d=reinterpret_cast<unsigned char*>(dest);
        auto ch=static_cast<unsigned char>(c);
        for(STD::size_t i=0; i<n; ++i){
            d[i]=ch;
        }
        return dest;
    }
}
