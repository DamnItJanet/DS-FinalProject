#ifndef METRIC
#define METRIC

#include "Vector.h"
#include "DSString.h"

class FileFormat
{
    public:
        FileFormat();
        ~FileFormat();

        void countComments(Vector<String>);

        void setLongestLine(Vector<String>);
        void setLineNum(Vector<String>);
        int getScore();
        int getLongestLine();
        int getLineNum();
        int getCommentNum();

        void calcFormatScore();

    private:
        int score;
        int longestLine;
        int lineNum;
        int commentNum;
};

#endif // METRIC

