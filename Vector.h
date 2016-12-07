#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>

template <class T>
class Vector
{
    public:

        // Default constructor
        Vector(void)
        {
            cap = 10;
            data = new T[cap];
            vectSize = 0;
        }

        // Copy constructor
        Vector(const Vector<T>& rhs)
        {
            if(rhs.data != nullptr)
            {
                // Setting up the new string values
                data = new T[rhs.cap];
                this->cap = rhs.cap;
                this->vectSize = rhs.vectSize;

                // Copying the value in rhs to the new string
                for(int i = 0; i < cap; i++)
                    data[i] = rhs.data[i];
            }
        }

        // Destructor
        ~Vector(void)
        {
            if(data != nullptr)
                delete[]data;
        }

        // Returns the element in the given index
        T& operator[] (int rhs)
        {
            if(rhs < 0)
            {
                int reverse = this->vectSize + rhs;
                return data[reverse];
            }
            else
                return data[rhs];
        }

        // Sets an element to the vector
        Vector<T>& operator= (Vector<T>& rhs)
        {
            if(this != &rhs)
            {
                if(data != nullptr)
                    delete[]data;

                if(rhs.data != nullptr)
                {
                    // Setting up values
                    data = new T[rhs.cap];

                    this->cap = rhs.cap;
                    this->vectSize = rhs.size();

                    // Copying characters
                    for(int i = 0; i < this->cap; i++)
                        data[i] = rhs.data[i];
                }
            }
            return *this;
        }

        // Adds an element after the last in the vector and resizes if necessary
        void add(T rhs)
        {
            data[vectSize] = rhs;
            vectSize++;

            if(vectSize == cap)
                this->resize(data, cap);
        }

        // Checks for the range and returns the value in the given index
        T& get(int rhs)
        {
            if(rhs > cap)
            {
                throw std::out_of_range ("Out of the range of the vector");
            }
            else if(rhs < 0)
            {
                int reverse = this->vectSize + rhs;
                return data[reverse];
            }
            else
                return data[rhs];
        }

        // Adds an element after the last in the vector and resizes if necessary
        void operator+= (T rhs)
        {
            data[vectSize] = rhs;
            vectSize++;

            if(vectSize == cap)
                this->resize(data, cap);
        }

        // Sets a value at the given index
        void set(const T vRhs, int iRhs)
        {
            // If the index is negative, it counts from the end
            if(iRhs > cap)
            {
                resize(data, cap);
                data[iRhs] = vRhs;
            }
            else if(iRhs < 0)
            {
                int reverse = cap + iRhs;
                data[reverse] = vRhs;
            }
            else
                data[iRhs] = vRhs;
        }

        int size()
        {
            return vectSize;
        }

        int getCap()
        {
            return cap;
        }

        // Clears the vector
        void clear()
        {
            data = 0;
            vectSize = 0;
        }

        // Bubble sort
        void sort()
        {
            for(int x = 0; x < vectSize; x++)
            {
                for(int y = 0; y < vectSize - 1; y++)
                {
                    if((int)data[y] > (int)data[y + 1])
                    {
                        T temp = data[y + 1];
                        data[y + 1] = data[y];
                        data[y] = temp;
                    }
                }
            }
        }

        // Special sorting function for article vector
        void sortArticlesVect()
        {
            for(int x = 0; x < vectSize; x++)
            {
                for(int y = 0; y < vectSize - 1; y++)
                {
                    if(data[y].getID() > data[y + 1].getID())
                    {
                        T temp = data[y + 1];
                        data[y + 1] = data[y];
                        data[y] = temp;
                    }
                }
            }
        }

        // Adds an element to the very last vector entry and resizes the vector
        void push_back(T rhs)
        {
            data[cap - 1] = rhs;
            push_backResize(data, cap);
        }

        friend std::ostream& operator<< (std::ostream& output, const Vector<T>& rhs)
        {
            output << rhs.data;

            return output;
        }

    private:

        // Resizes the vector by a factor of 1.5
        void resize(T*& oldData, int& oldCap)
        {
            int nCap = 1.5 * oldCap;
            T* ptr = new T[nCap];

            for(int i = 0; i < oldCap; i++)
                ptr[i] = oldData[i];

            delete[]oldData;
            oldData = ptr;
            cap = cap * 1.5;
        }

        // Resizes the vector by 1 for push_back function
        void push_backResize(T*& oldData, int& oldCap)
        {
            int nCap = oldCap + 2;
            T* ptr = new T[nCap];

            for(int i = 0; i < oldCap; i++)
                ptr[i] = oldData[i];

            delete[]oldData;
            oldData = ptr;
            cap = cap + 2;
        }

        // Size of the vector
        int vectSize;
        // Capacity of the vector
        int cap;
        // Elements of the vector
        T* data;
};

#endif // VECTOR_H
