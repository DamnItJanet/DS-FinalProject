#ifndef NAMINGCONV
#define NAMINGCONV

#include "Vector.h"
#include "DSString.h"

class NamingConv
{
    public:
        NamingConv();
        ~NamingConv();

        void setShortestName(Vector<String>);
        void setLongestName(Vector<String>);
        int getScore();
        int getShortestName();
        int getLongestName();

        void calcNestScore();

    private:
        int score;
        int shortestName;
        int longestName;
};

#endif // NAMINGCONV

