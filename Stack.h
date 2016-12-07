#ifndef STACK
#define STACK

#include "LinkedList.h"

// Last in, first out
template<class T>
class Stack : private LinkedList<T>{

    public:

        // Add a value to the front of the Stack
        void push(T);
        // Remove and return the first element of the Stack
        T pop();
        // Look at the first element of the Stack
        T peek();
        // Check to see if the Stack is empty
        bool isEmpty();
        // Returns the depth level of the Stack
        int getDepth();

    private:

        LinkedList<T> data;
        // Keeps track of the deepest level of the Stack
        int depth;

};

template<class T>
void Stack<T>::push(T rhs)
{
    this->addToFront(rhs);

    depth = this->size();
}

template<class T>
T Stack<T>::pop()
{
    return this->remove(0);

    depth = this->size();
}

template<class T>
T Stack<T>::peek()
{
    return this->get(0);
}

template<class T>
bool Stack<T>::isEmpty()
{
    return this->isEmpty();
}

template<class T>
int Stack<T>::getDepth()
{
    return depth;
}

#endif
