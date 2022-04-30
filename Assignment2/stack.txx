//
// Assignment 2 : Simple calculator using Stack
//
// Array-based stack data structure
//
// COSE213 Spring 2021
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

template<class type>
Stack<type>::~Stack()
{
 delete []array;
}

template<class type>
type& Stack<type>::Top()
{
return array[top];
}

template<class type>
void Stack<type>::Push(const type& item)
{
 if(top >= capacity -1)
  {
   realloc(array, 2*capacity*sizeof(*array));
   capacity *= 2;
  }
 else
  {
   array[++top] = item;
  }
}

template<class type>
void Stack<type>::Pop()
{
 if(IsEmpty())
  {
   return;
  }
 else
  {
   array[top--];
  }
}

template<class type>
bool Stack<type>::IsEmpty() const
{
	// ToDo	
   return top == NULL;
}

