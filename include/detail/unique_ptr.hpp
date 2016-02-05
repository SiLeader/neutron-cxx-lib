//                    (C) 2016 SiLeader.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once
#include <developer_settings.hpp>

namespace STD
{
    template<class TType>struct default_delete
    {
        void operator()(TType* ptr) const { delete ptr; }
    };

    template<class TType>struct default_delete<TType[]>
    {
        void operator()(TType* arr) const { delete[] arr; }
    };

    template<class TType,class TDeleter = default_delete<TType>>class unique_ptr //< noncopyable
    {
    private:
        template<class T> struct remove_extent { typedef T type; };
        template<class T> struct remove_extent<T[]> { typedef T type; };
    public:
        typedef typename remove_extent<TType>::type element_type;
        typedef TDeleter deleter_type;
        typedef element_type* pointer;

        explicit unique_ptr(pointer ptr = pointer(), const deleter_type& del = deleter_type()) : m_managed_pointer(ptr), m_managed_deleter(del) {}

        ~unique_ptr()
        {
            if (this->m_managed_pointer != pointer()) {
                this->get_deleter()(this->m_managed_pointer);
            }
        }

        pointer release()
        {
            pointer R_ = this->m_managed_pointer;
            this->m_managed_pointer = pointer();
            return R_;
        }

        void reset(pointer ptr = pointer())
        {
            pointer old = this->m_managed_pointer;
            this->m_managed_pointer = ptr;
            if (old != pointer()) {
                this->get_deleter()(old);
            }
        }

        pointer get() const { return (this->m_managed_pointer); }
        element_type& operator*() const { return (*this->m_managed_pointer); }
        pointer operator->() const { return &**this; }
        deleter_type& get_deleter() { return m_managed_deleter; }
        const deleter_type& get_deleter() const { return m_managed_deleter; }
        explicit operator bool() const { return (this->m_managed_pointer != pointer()); }
    private:
        unique_ptr(const unique_ptr&)=delete; //< noncopyable
        unique_ptr& operator=(const unique_ptr&)=delete; //< noncopyable

        pointer m_managed_pointer;
        deleter_type m_managed_deleter;
    };
}
