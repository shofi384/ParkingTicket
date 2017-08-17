// Provided by:   Shofiqur Rahman
// Email Address: shofi384@gmail.com
//								srahman010@citymail.cuny.edu

// FILE: sequence2.cxx
// CLASS Implemented: sequence (see sequence2.h for documentation)
// INVARIANT for the class:
//  1. Then number of items in the sequence is in the member variable used
//  2.The actual items in the sequence is in the partially filled array pointed to by data. The array is a dynamic array.
//  3.The size of the dynamic array is in the member variable capacity.

#include "sequence2.h"
#include <algorithm>      //provides copy function
#include <cassert>        //provides assert function
using namespace std;      //std::algorithm

namespace main_savitch_4
{
    const sequence::size_type sequence::DEFAULT_CAPACITY;

    sequence::sequence(size_type initial_capacity)  // CONSTRUCTOR
    {data = new value_type[initial_capacity];
        capacity = initial_capacity;
        used=0;
        current_index = 0;}

    sequence::sequence(const sequence& source)
    {data = new value_type[source.capacity];
        capacity=source.capacity;
        current_index = source.current_index;
        used=source.used;
        copy(source.data, source.data+used, data);}

    sequence::~sequence( )    // DESTRUCTOR
    {delete []data;}

    // MODIFICATION MEMBER FUNCTIONS
    void sequence::resize(size_type new_capacity)
    {if(capacity==new_capacity) return;
        if(capacity>new_capacity) new_capacity=used;
        value_type* largerarray = new value_type[new_capacity];
        copy(data, data+used, largerarray);
        delete []data;
        data = largerarray;
        capacity = new_capacity;}

    void sequence::insert(const value_type& entry)
    {if(!(used<capacity)) resize(used+1);
        if(!is_item()) current_index = 0;
        for(size_type i=used; i>current_index; --i)
            {data[i] = data[i-1];}
        data[current_index]=entry;
        used++;}

    void sequence::attach(const value_type& entry)
    {if(!(used<capacity)) resize(used+1);
        if(!is_item()) current_index = used;
        else{for(size_type i=used; i>current_index; --i)
            {data[i] = data[i-1];}
            ++current_index;}
        data[current_index]=entry;
        used++;}

    void sequence::remove_current( )
    {assert(is_item());
        for(size_type i=current_index; i<(used-1); ++i)
        {data[i] = data[i+1];}
        --used;}

    void sequence::operator =(const sequence& source)
    {if(this == &source) return;
        value_type* newdata;
        if(capacity!=source.capacity)
        {newdata = new value_type[source.capacity];
            delete []data;
            data = newdata;
            capacity = source.capacity;}
            copy(source.data, source.data+source.used, data);
            used = source.used;
            current_index=source.current_index;}
}
