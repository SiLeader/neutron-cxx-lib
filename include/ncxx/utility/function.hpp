//                    (C) 2016 SiLeader.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

namespace ncxx
{
    namespace utility{
        template<class> class function;

        template<class Ret, class... Args> class function<Ret(Args...)>
        {
        public:
            using func_pointer=Ret(*)(Args...);

        private:
            func_pointer m_pointer;
            function()=delete;

        public:
            function(func_pointer pointer):m_pointer(pointer){}

            function& operator=(func_pointer pointer)
            {
                this->m_pointer=pointer;
                return *this;
            }

            explicit operator bool()
            {
                return m_pointer!=nullptr;
            }

            Ret operator()(Args... arg)
            {
                return m_pointer(arg...);
            }
        };
    }
}
