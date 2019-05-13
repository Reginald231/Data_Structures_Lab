//  reginaldImplementation.cpp
//  linkedList
//  Created by Reginald Long on 2/20/19.
//  Copyright © 2019 Reginald Long. All rights reserved.
//


/*
 Step1: default constructor
 Step2: Copy Constructor
 Step3: Deconstructor
 Step4: Set cursor to head pointer
 Step5: Moves cursor by one
 Step6: inserts a value at the current cursor
 Step7: removes the current cursor value
 Step8: overrides = operator
 Step 9: returns the current item
 */

#include "sequence3.h"


namespace main_savitch_5
{
    //constructors & deconstructors
    sequence::sequence()
    {
    //Library facilities used: cstdlib
        many_nodes = 0;
        cursor = precursor = tail_ptr = head_ptr = NULL;
    }
    
    sequence::sequence(const sequence & source)
    {
    //Library facilities used: cstdlib node1.h
    
        many_nodes = source.many_nodes;
        cursor = precursor = tail_ptr = head_ptr = NULL;
        
        node * remember_precursor = NULL;
        
        if(source.head_ptr != NULL)
        {
            head_ptr = cursor = new node(source.head_ptr->data());
            precursor = NULL;
            
            for (node * temp_cursor = source.head_ptr->link(); temp_cursor != NULL; temp_cursor = temp_cursor->link())
            {
                precursor = cursor;
                cursor = new node(temp_cursor->data());
                precursor->set_link(cursor);
                
                if(temp_cursor == source.precursor)
                    remember_precursor = cursor;
                    
            }
        }
        tail_ptr = cursor;
        precursor = remember_precursor;
        if(precursor == NULL)
            cursor = head_ptr;
        else
            cursor = precursor->link();
    }
    
    sequence::~sequence()
    {
    // Library facilities used: node1.h
        cursor = head_ptr;
        
        while(cursor != tail_ptr)
        {
            precursor = cursor;
            cursor = cursor->link();
            delete precursor;
        }
        delete cursor;
    }
    
    //mod member functions
    void sequence::start()
    {
        if(many_nodes != 0)
            cursor = head_ptr;
        precursor = NULL;
    }
    
    void sequence::advance()
    {
    // Library facilities used: node1.h
    if(cursor != NULL)
        {
            precursor = cursor;
            cursor = cursor -> link();
        }
    }
    
    void sequence::insert(const value_type& entry)
    {
    // Library facilities used: node1.h cstdlib
    
        if((!is_item()) || cursor == head_ptr) // if adding to start of sequence
        {
            cursor = new node(entry, head_ptr);
            head_ptr = cursor;
            precursor = NULL;
            
            if(many_nodes == 0)
                tail_ptr = cursor;
        }
        else
        {
            cursor = new node(entry, cursor);
            precursor->set_link(cursor);
        }
        
        many_nodes++;
    }
    
    void sequence::attach(const value_type & entry)
    {
    // Library facilities used: node1.h cstdlib
    
        if(!(is_item()) || cursor == tail_ptr) // if adding to end
        {
            precursor = tail_ptr;
            cursor = new node(entry, NULL);
            if(precursor != NULL)
                precursor->set_link(cursor);
            tail_ptr = cursor;
            
            if(many_nodes == 0)
                head_ptr = cursor;
        }
        else
        {
            precursor = cursor;
            cursor = new node(entry, cursor->link());
            precursor->set_link(cursor);
        }
        
        many_nodes++;
    }
    
    void sequence::remove_current()
    {
    // Library facilities used: node1.h cstdlib
        if(cursor == head_ptr)
        {
            head_ptr = cursor->link();
            delete cursor;
            cursor = head_ptr;
            
            if(many_nodes == 1)
                precursor = tail_ptr = NULL;
        }
        else if(cursor == tail_ptr)
        {
            delete cursor;
            tail_ptr = precursor;
            precursor->set_link(NULL);
            cursor = NULL;
        }
        else
        {
            precursor->set_link(cursor->link());
            delete cursor;
            cursor = precursor->link();
        }
        
        many_nodes--;
    }
    
    void sequence::operator=(const sequence& source)
    {
    // Library facilities used: node1.h cstdlib
        if( (&source == this) || ((source.head_ptr == NULL) && (head_ptr == NULL)) )
            return;
        
        many_nodes = source.many_nodes;
        
        if((source.head_ptr != NULL) && (head_ptr != NULL))
        {
            cursor = head_ptr;
            node * temp_cursor = source.head_ptr;
            node * remember_precursor = NULL;

            
            while ( (temp_cursor != NULL)&&(cursor != NULL) )
            {
                precursor = cursor;
                cursor->set_data(temp_cursor->data());
                
                temp_cursor = temp_cursor -> link();
                cursor = cursor -> link();
                
                if(temp_cursor == source.precursor)
                    remember_precursor = cursor;
            }
            
            if(temp_cursor == NULL)
            {
                while(cursor != NULL)
                {
                    precursor = cursor;
                    delete precursor;
                    cursor = cursor->link();
                }
                
                tail_ptr = precursor;
                precursor = remember_precursor;
                if(precursor == NULL)
                    cursor = head_ptr;
                else
                    cursor = precursor->link();
                
                return;
            }
            else
            {
                cursor = precursor;
                
                for (node * temp_cursor2 = temp_cursor; temp_cursor2 != NULL; temp_cursor2 = temp_cursor2->link())
                {
                    precursor = cursor;
                    cursor = new node(temp_cursor2->data());
                    precursor->set_link(cursor);
                    
                    if(temp_cursor == source.precursor)
                        remember_precursor = cursor;
                }
            }
            
            precursor = remember_precursor;
            if(precursor == NULL)
                cursor = head_ptr;
            else
                cursor = precursor->link();
            
        }
        else if( (source.head_ptr == NULL)&&(head_ptr != NULL) )
        {
            cursor = head_ptr;
            while(cursor != NULL)
                {
                    precursor = cursor;
                    cursor = cursor->link();
                    delete precursor;
                }
                
                tail_ptr = precursor = cursor = head_ptr = NULL;
                return;
        }
        else if( (source.head_ptr != NULL)&&(head_ptr == NULL) )
        {
            head_ptr = precursor = cursor = new node(source.head_ptr->data());
            node * remember_precursor = NULL;
            
            for (node * temp_cursor2 = source.head_ptr->link(); temp_cursor2 != NULL; temp_cursor2 = temp_cursor2->link())
            {
                precursor = cursor;
                cursor = new node(temp_cursor2->data());
                precursor->set_link(cursor);
                
                if(temp_cursor2 == source.precursor)
                    remember_precursor = cursor;
            }
            
            precursor = remember_precursor;
            if(precursor == NULL)
                cursor = head_ptr;
            else
                cursor = precursor->link();
        }
    }
   /*
    // Constant member functions
    sequence::size_type sequence::size() const
    {
        return many_nodes;
    }
    
    bool sequence::is_item() const
    {
    // Library facilities used: cstdlib
        return (many_nodes && (cursor != NULL) );
    }
    */
    node::value_type sequence::current() const
    {
    // Library facilities used: node1.h
        return cursor -> data();
    }
}

