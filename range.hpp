#pragma once

#include <iostream>
#include <string>
// #include <vector>

namespace itertools
{

    class range
    {
    /* range members */
    private:
        int m_start, m_end;
    public:
        /* the iterator */
        class iterator
        {
        public:
            iterator(int val);
            int operator*() const;
            iterator &operator++();
            bool operator!=(const iterator &other) const;

        private:
            int m_current_number = -1;
        };

    public:
        /* rane methods - decleration */
        range(int from, int to);
        iterator begin() const ;
        iterator end() const;
    };

    
    /* range methods - implementation */
    range::range(int from, int to):
        m_start(from),
        m_end(to){}

    range::iterator::iterator(int val){
        m_current_number = val;
    }  

    range::iterator& range::iterator::operator++(){
        m_current_number++;
        return *this;
    } 

    int range::iterator::operator*() const{
        return m_current_number;
    }

    bool range::iterator::operator!=(const range::iterator& other) const {
        return m_current_number!=other.m_current_number;
    }

    range::iterator range::begin() const{
        return range::iterator{m_start};
    } 

    range::iterator range::end() const{
        return range::iterator{m_end};
    } 
 

} // namespace itertools
