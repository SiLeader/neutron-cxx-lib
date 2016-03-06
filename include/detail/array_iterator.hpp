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

    template<class T, STD::size_t N> class array_iterator : public STD::iterator<STD::random_access_iterator_tag, T>
    {
        friend STD::array<T,N>;
    private:
        STD::size_t m_index;
        STD::array<T,N>& m_array;

        array_iterator()=delete;
        array_iterator(STD::array<N,T>& src_array, STD::size_t index)
            : m_index(index), m_array(src_array){}
    public:
        array_iterator(const array_iterator& itr)
            : m_index(itr.m_index), m_array(itr.m_array){}

        array_iterator& operator++()
        {
            ++(this->m_index);
            return *this;
        }

        array_iterator operator++(int)
        {
            array_iterator<T,N> old(*this);
            ++(this->m_index);
            return old;
        }

        array_iterator& operator--()
        {
            if(this->m_index!=0){
                --(this->m_index);
            }
            return *this;
        }

        array_iterator operator--(int)
        {
            if(this->m_index!=0){
                array_iterator<T,N> old(*this);
                --(this->m_index);
                return old;
            }
            return *this;
        }

        bool operator==(const array_iterator<T,N>& itr)const
        {
            return (this->m_index==itr.m_index && this->m_array==itr.m_array);
        }

        bool operator!=(const array_iterator<T,N>& itr)const
        {
            return !((*this)==itr);
        }

        bool operator<(const array_iterator<T,N>& itr)const
        {
            return (this->m_array==itr.m_array && this->m_index<itr.m_index);
        }

        bool operator<=(const array_iterator<T,N>& itr)const
        {
            return ((*this)<itr || (*this)==itr);
        }

        bool operator>(const array_iterator<T,N>& itr)const
        {
            return !((*this)<=itr);
        }

        bool operator>=(const array_iterator<T,N>& itr)const
        {
            return !((*this)<itr);
        }

        array_iterator<T,N> operator+(STD::size_t n)const
        {
            decltype(*this) itr;
            itr.m_index+=n;
            return itr;
        }

        array_iterator<T,N>& operator+=(STD::size_t n)
        {
            *this=(*this)+n;
            return *this;
        }

        array_iterator<T,N> operator-(STD::size_t n)const
        {
            decltype(*this) itr;
            itr.m_index-=n;
            return itr;
        }

        array_iterator<T,N>& operator-=(STD::size_t n)
        {
            *this=(*this)+n;
            return *this;
        }

        T& operator[](STD::size_t n)const
        {
            this->m_array[this->m_index+n];
        }

        T& operator*()
        {
            return (*this)[0];
        }
    };

    template<class T, STD::size_t N> class array_const_iterator : public STD::iterator<STD::random_access_iterator_tag, T>
    {
        friend STD::array<T,N>;
    private:
        STD::size_t m_index;
        STD::array<T,N>& m_array;

        array_iterator()=delete;
        array_iterator(STD::array<N,T>& src_array, STD::size_t index)
            : m_index(index), m_array(src_array){}
    public:
        array_iterator(const array_iterator& itr)
            : m_index(itr.m_index), m_array(itr.m_array){}

        array_iterator& operator++()
        {
            ++(this->m_index);
            return *this;
        }

        array_iterator operator++(int)
        {
            array_iterator<T,N> old(*this);
            ++(this->m_index);
            return old;
        }

        array_iterator& operator--()
        {
            if(this->m_index!=0){
                --(this->m_index);
            }
            return *this;
        }

        array_iterator operator--(int)
        {
            if(this->m_index!=0){
                array_iterator<T,N> old(*this);
                --(this->m_index);
                return old;
            }
            return *this;
        }

        bool operator==(const array_iterator<T,N>& itr)const
        {
            return (this->m_index==itr.m_index && this->m_array==itr.m_array);
        }

        bool operator!=(const array_iterator<T,N>& itr)const
        {
            return !((*this)==itr);
        }

        bool operator<(const array_iterator<T,N>& itr)const
        {
            return (this->m_array==itr.m_array && this->m_index<itr.m_index);
        }

        bool operator<=(const array_iterator<T,N>& itr)const
        {
            return ((*this)<itr || (*this)==itr);
        }

        bool operator>(const array_iterator<T,N>& itr)const
        {
            return !((*this)<=itr);
        }

        bool operator>=(const array_iterator<T,N>& itr)const
        {
            return !((*this)<itr);
        }

        array_iterator<T,N> operator+(STD::size_t n)const
        {
            decltype(*this) itr;
            itr.m_index+=n;
            return itr;
        }

        array_iterator<T,N>& operator+=(STD::size_t n)
        {
            *this=(*this)+n;
            return *this;
        }

        array_iterator<T,N> operator-(STD::size_t n)const
        {
            decltype(*this) itr;
            itr.m_index-=n;
            return itr;
        }

        array_iterator<T,N> operator-=(STD::size_t n)
        {
            *this=(*this)+n;
            return *this;
        }

        const T& operator[](STD::size_t n)const
        {
            this->m_array[this->m_index+n];
        }

        const T& operator*()
        {
            return (*this)[0];
        }
    };
}
