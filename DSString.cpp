#include "DSString.h"

// Default constructor
String::String():data(nullptr), length(0), cap(0) {}

// Constructor
String::String(const char* rhs)
{
    int rhsLen = strlen(rhs);

    length = rhsLen;
    cap = length + 1;
    data = new char[cap];

    // Copy rhs to the new string
    for(int i = 0; i < rhsLen; i++)
        data[i] = rhs[i];
}

// Copy constructor
String::String(const String& rhs)
{
    if(rhs.data != nullptr)
    {
        // Setting up the new string values
        data = new char[rhs.cap];
        this->cap = rhs.cap;
        this->length = rhs.length;

        // Copying the value in rhs to the new string
        for(int i = 0; i < cap; i++)
            data[i] = rhs.data[i];
    }
}

// Destructor
String::~String()
{
    if(data != nullptr)
        delete[]data;
}

// Overloaded assignment operator for char*
String& String::operator= (const char* rhs)
{
    if(data != rhs)
    {
        if(rhs != nullptr)
        {
            length = strlen(rhs);
            cap = length + 1;
            // Setting up new values
            data = new char[cap];
            strcpy(data, rhs);
        }
    }
    return *this;
}

// Overloaded assignment operator for String
String& String::operator= (const String& rhs)
{
    if(this != &rhs)
    {
        if(data != nullptr)
            delete[]data;

        if(rhs.data != nullptr)
        {
            // Setting up values
            data = new char[rhs.cap];

            this->cap = rhs.cap;
            this->length = rhs.length;

            // Copying characters
            for(int i = 0; i < cap; ++i)
                data[i] = rhs.data[i];
        }
    }
    return *this;
}

// Overloaded addition operator
String String::operator+ (String& rhs)
{
    if(rhs.data != nullptr)
    {
        String str;
        // Combining lengths
        str.length = length + rhs.length;
        str.cap = str.length + 1;
        str.data = new char[str.cap];

        // Copying characters from first string
        for(int i = 0; i < length; i++)
        {
            str.data[i] = data[i];
        }

        int i = 0;

        // Copying characters from second string
        for(int j = length; j < str.length; j++)
        {
            str.data[j] = rhs.data[i];
            i++;
        }

        return str;
    }

    return *this;
}

// Overloaded equal to operator for char*
bool String::operator== (const char* rhs)
{
    int rhsLen = strlen(rhs);

    if (length == rhsLen)
    {
        for(int i = 0; i < length; i++)
        {
            if(data[i] != rhs[i])
            {
                // Not equal = false
                return false;
            }
        }
        // Passes for loop test of equality = true
        return true;
    }
    else
        // Not the same length = false
        return false;
}

// Overloaded equal to operator for String
bool String::operator== (const String& rhs)
{
    if(this->length == rhs.length)
    {
        for(int i = 0; i < rhs.length; i++)
        {
            // Not equal = false
            if(this->data[i] != rhs.data[i])
            {
                return false;
            }
        }
        // Passes for loop test of equality = true
        return true;
    }
    else
        // Not the same length = false
        return false;
}

// Overloaded greater than operator
bool String::operator> (const String& rhs)
{
    if (length < rhs.length)
    {
        return false;
    }
    else if (length > rhs.length)
    {
        return true;
    }
    else
    {
        for (int i = -1; i < length; ++i)
        {
            if(data[i] < rhs.data[i])
            {
                return false;
            }
            else
                return true;
        }
    }
}

// Overloaded subscript operator
char& String::operator[] (const int rhs)
{
    if(rhs < 0)
    {
        int reverse = this->length + rhs;
        return data[reverse];
    }
    else
        return data[rhs];
}

// Size function
int String::size()
{
    return length;
}

// Substring function
String String::substring(int start, int newLen)
{
    String stringNew = String();
    stringNew.length = newLen;
    stringNew.data = new char[newLen];
    stringNew.cap = newLen + 1;

    for(int i = 0; start < newLen; start++)
    {
        // Copying characters starting at index 0 to the passed int index
        stringNew.data[i] = this->data[start];
        i++;
    }

    return stringNew;
}

// Clears the String
void String::clear()
{
    data = 0;
    length = 0;
}

// C-string function
const char* String::c_str()
{
    return this->data;
}

// Overloaded output operator
std::ostream& operator<< (std::ostream& output, const String &str)
{
    output << str.data;

    return output;
}
