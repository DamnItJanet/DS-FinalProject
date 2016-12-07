#ifndef STRING
#define STRING

#include <iostream>
#include <cstring>

class String
{
    public:

        // Default constructor
        String();
        // Constructor
        String(const char*);
        // Copy constuctor
        String(const String&);
        // Destructor
        ~String();

        // Overloaded assignment op for char[]
        String& operator= (const char*);
        // Overloaded assignment op for Strings
        String& operator= (const String&);
        // Overloaded addition op
        String operator+ (String&);
        // Overloaded comparator for char[]
        bool operator== (const char*);
        // Overloaded comparator for Strings
        bool operator== (const String&);
        // Overloaded comparison operation
        bool operator> (const String&);
        // Overloaded subscript operator
        char& operator[] (const int);

        // Size func: returns size of char array
        int size();
        // Substring func: returns a String
        String substring(int, int);
        // C-string function
        const char* c_str();
        // Clear function
        void clear();

        // Overloaded output
        friend std::ostream& operator<< (std::ostream&, const String&);

    private:

        // char[]
        char* data;
        // Length of char[]
        int length;
        // Capacity of char[]
        int cap;
};

#endif
