//                    (C) 2016 SiLeader.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include<iterator>

namespace ncxx
{
    namespace utility
    {
        enum class IteratorTags
        {
            Input, Output, Forward, Bidirectional, RandomAccess
        };

        template<>constexpr ncxx::utility::IteratorTags iterator_check<STD::input_iterator_tag>()
        {
            return ncxx::utility::IteratorTags::Input;
        }

        template<>constexpr ncxx::utility::IteratorTags iterator_check<output_iterator_tag>()
        {
            return ncxx::utility::IteratorTags::Output;
        }

        template<>constexpr ncxx::utility::IteratorTags iterator_check<forward_iterator_tag>()
        {
            return ncxx::utility::IteratorTags::Forward;
        }

        template<>constexpr ncxx::utility::IteratorTags iterator_check<bidirectional_iterator_tag>()
        {
            return ncxx::utility::IteratorTags::Bidirectional;
        }

        template<>constexpr ncxx::utility::IteratorTags iterator_check<random_access_iterator_tag>()
        {
            return ncxx::utility::IteratorTags::RandomAccess;
        }
    }
}
