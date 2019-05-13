#include "sequence1.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>

using namespace std;
using namespace main_savitch_3;


typedef double value_type;
        typedef size_t size_type;
       
        static const size_type CAPACITY = 30;



sequence::sequence()
{
current_index = 0;
used = 0;
}

void sequence::start(){
   if(size() > 0)
      current_index = 0;
}

void sequence::advance()
{
    if(is_item() == true)
    ++current_index;
}

void sequence::insert(const value_type& entry)
{
    assert(size() < CAPACITY);

    if(is_item()==false)
    {
        current_index = 0;
    }
   
    
        for(size_type i = used; i > current_index; --i)
        {
            data[i]=data[i-1];
        }
    
    data[current_index] = entry;
 ++ used;
}

void sequence::attach(const value_type& entry)
{
    assert( size() < CAPACITY);
		if(!is_item() == false){

		 current_index= used-1;
		}

		++current_index;

		for(size_type i = used; i>current_index; --i){
			data[i] = data[i-1];
		}

		data[current_index] = entry; 
		++used;
}

void sequence::remove_current()
{

    if(is_item() == true){
    
    for(size_type i = current_index; i<used - 1; ++i)
    {
        data[i]=data[i+1];
    }
    
--used;
}
}

 sequence::size_type sequence::size()const
    {
        return used;
    }



sequence::value_type sequence::current()const
{
    if (is_item())
    return data[current_index];
}

bool sequence::is_item() const
{
    return (current_index >= 0 && current_index < used);
}








