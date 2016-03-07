//                    (C) 2016 SiLeader.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <developer_settings.hpp>

namespace STD
{
    template<class CharT, class Traits=char_traits<CharT>, class Allocator=allocator<CharT>>class basic_string
    {
    public:
        using traits_type=Traits;
        using value_type=Traits::char_type;
        using allocator_type=Allocator;
        using size_type=STD::allocator_traits<Allocator>::size_type;
        using difference_type=STD::allocator_traits<Allocator>::difference_type;
        using reference=value_type&;
        using const_reference=const value_type&;
        using pointer=STD::allocator_traits<Allocator>::pointer;
        using const_pointer=STD::allocator_traits<Allocator>::const_pointer;
        using iterator;
        using const_iterator;
        using reverse_iterator;
        using const_reverse_iterator;
    private:
        CharT *m_buf;

        void m_copy(CharT *another)//copy m_buf's address only
        {
            m_buf=another;
        }
        void m_clone(CharT *another)//copy m_buf's contains
        {
            
        }
    public:
        basic_string();
        explicit basic_string(const Allocator& alloc=Allocator());
        basic_string( size_type count, CharT ch, const Allocator& alloc = Allocator());
        basic_string( const basic_string& other, size_type pos, size_type count = STD::basic_string::npos, const Allocator& alloc = Allocator());
        basic_string( const CharT* s, size_type count, const Allocator& alloc = Allocator());
        basic_string( const CharT* s, const Allocator& alloc = Allocator());
        template<class InputIt>basic_string(InputIt first, InputIt last, const Allocator& alloc = Allocator());
        basic_string(const basic_string& other);
        basic_string(const basic_string& other, const Allocator& alloc);
        basic_string(basic_string&& other);
        basic_string(basic_string&& other, const Allocator& alloc);
        basic_string(STD::initializer_list<CharT> init, const Allocator& alloc = Allocator());
    };
}
