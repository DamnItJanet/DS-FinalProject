#ifndef NESTS
#define NESTS

#include "Vector.h"
#include "DSString.h"
#include "LinkedList.h"
#include "Stack.h"

class Nests
{
    public:
        Nests();
        ~Nests();

        void findDeepestLevel(Vector<String>);
        void findNestNum(Vector<String>);

        int getScore();
        int getDeepestLevel();

        void calcNestScore();

    private:
        int score;
        int nestNum;
        int deepestNestLevel;
        Stack<char> nestLevel;

};

#endif // NESTS

