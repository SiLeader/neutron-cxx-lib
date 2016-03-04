//                    (C) 2016 SiLeader.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

namespace ncxx
{
    namespace utility
    {
        inline constexpr unsigned long long power(unsigned int base, unsigned int index)
        {
            if(index==0){
                return 1;
            }else{
                return ncxx::utility::power(base, index-1)*base;
            }
        }
    }
}
