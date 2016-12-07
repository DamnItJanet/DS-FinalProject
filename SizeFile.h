#ifndef SIZEMAIN
#define SIZEMAIN

#include "Vector.h"
#include "DSString.h"

class SizeFile
{
    public:
        SizeFile();
        ~SizeFile();

        void setFileLength(Vector<String>);
        int getScore();
        int getFileLength();

        void calculateScore();

    private:
        int score;
        int fileLength;

};

#endif // SIZEMAIN

