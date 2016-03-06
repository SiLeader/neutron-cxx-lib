//                    (C) 2016 SiLeader.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <developer_settings.hpp>

#include <iterator>
#include <array>

namespace STD
{
    template<class T, STD::size_t N> class array;

    template<class T, STD::size_t N> class array_reverse_iterator : public STD::iterator<STD::random_access_iterator_tag, T>
    {
    private:
        STD::array_iterator<T,N> m_itr;

        array_reverse_iterator()=delete;
        array_reverse_iterator(const STD::array_iterator<T,N>& itr):m_itr(itr){}
    public:
        array_reverse_iterator(const array_reverse_iterator& itr)
            : m_itr(itr.m_itr){}

        array_iterator& operator++()
        {
            --(this->m_itr);
            return *this;
        }

        array_iterator operator++(int)
        {
            array_reverse_iterator<T,N> old(*this);
            --(*this);
            return old;
        }

        array_iterator& operator--()
        {
            ++(this->m_itr);
            return *this;
        }

        array_iterator operator--(int)
        {
            if(this->m_index!=0){
                array_reverse_iterator<T,N> old(*this);
                ++(*this);
                return old;
            }
            return *this;
        }

        bool operator==(const array_reverse_iterator<T,N>& itr)const
        {
            return (this->m_itr == itr.m_itr);
        }

        bool operator!=(const array_reverse_iterator<T,N>& itr)const
        {
            return !((*this)==itr);
        }

        bool operator<(const array_reverse_iterator<T,N>& itr)const
        {
            return (this->m_itr < itr.m_itr);
        }

        bool operator<=(const array_reverse_iterator<T,N>& itr)const
        {
            return ((*this)<itr || (*this)==itr);
        }

        bool operator>(const array_reverse_iterator<T,N>& itr)const
        {
            return !((*this)<=itr);
        }

        bool operator>=(const array_reverse_iterator<T,N>& itr)const
        {
            return !((*this)<itr);
        }

        array_reverse_iterator<T,N> operator+(STD::size_t n)const
        {
            decltype(*this) itr;
            itr.m_itr-=n;
            return itr;
        }

        array_reverse_iterator<T,N>& operator+=(STD::size_t n)
        {
            *this=(*this)+n;
            return *this;
        }

        array_reverse_iterator<T,N> operator-(STD::size_t n)const
        {
            decltype(*this) itr;
            itr.m_itr+=n;
            return itr;
        }

        array_reverse_iterator<T,N>& operator-=(STD::size_t n)
        {
            *this=(*this)-n;
            return *this;
        }

        T& operator[](STD::size_t n)const
        {
            this->m_itr[N-n];
        }

        T& operator*()
        {
            return (*this)[0];
        }
    };

    template<class T, STD::size_t N> class array_const_reverse_iterator : public STD::iterator<STD::random_access_iterator_tag, T>
    {
    private:
        STD::array_const_iterator<T,N> m_itr;

        array_const_reverse_iterator()=delete;
        array_const_reverse_iterator(const STD::array_const_iterator<T,N>& itr):m_itr(itr){}
    public:
        array_const_reverse_iterator(const array_const_reverse_iterator& itr)
            : m_itr(itr.m_itr){}

        array_const_reverse_iterator& operator++()
        {
            --(this->m_itr);
            return *this;
        }

        array_const_reverse_iterator operator++(int)
        {
            array_const_reverse_iterator<T,N> old(*this);
            --(*this);
            return old;
        }

        array_const_reverse_iterator& operator--()
        {
            ++(this->m_itr);
            return *this;
        }

        array_const_reverse_iterator operator--(int)
        {
            if(this->m_index!=0){
                array_const_reverse_iterator<T,N> old(*this);
                ++(*this);
                return old;
            }
            return *this;
        }

        bool operator==(const array_const_reverse_iterator<T,N>& itr)const
        {
            return (this->m_itr == itr.m_itr);
        }

        bool operator!=(const array_const_reverse_iterator<T,N>& itr)const
        {
            return !((*this)==itr);
        }

        bool operator<(const array_const_reverse_iterator<T,N>& itr)const
        {
            return (this->m_itr < itr.m_itr);
        }

        bool operator<=(const array_const_reverse_iterator<T,N>& itr)const
        {
            return ((*this)<itr || (*this)==itr);
        }

        bool operator>(const array_const_reverse_iterator<T,N>& itr)const
        {
            return !((*this)<=itr);
        }

        bool operator>=(const array_const_reverse_iterator<T,N>& itr)const
        {
            return !((*this)<itr);
        }

        array_const_reverse_iterator<T,N> operator+(STD::size_t n)const
        {
            decltype(*this) itr;
            itr.m_itr-=n;
            return itr;
        }

        array_const_reverse_iterator<T,N>& operator+=(STD::size_t n)
        {
            *this=(*this)+n;
            return *this;
        }

        array_const_reverse_iterator<T,N> operator-(STD::size_t n)const
        {
            decltype(*this) itr;
            itr.m_itr+=n;
            return itr;
        }

        array_const_reverse_iterator<T,N>& operator-=(STD::size_t n)
        {
            *this=(*this)+n;
            return *this;
        }

        const T& operator[](STD::size_t n)const
        {
            this->m_itr[N-n];
        }

        const T& operator*()
        {
            return (*this)[0];
        }
    };
}
