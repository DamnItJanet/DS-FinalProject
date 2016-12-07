#include "FileFormat.h"


FileFormat::FileFormat():score(0), longestLine(0), lineNum(0), commentNum(0) {}

FileFormat::~FileFormat() {}

void FileFormat::countComments(Vector<String> linesOfCode)
{
    for (int i = 0; i < linesOfCode.size(); i++)
    {
        for (int j = 0; j < linesOfCode.get(i).size(); j++)
        {
            if (linesOfCode.get(i)[j] == '/'
                    && linesOfCode.get(i)[j + 1] == '/')
                commentNum++;
            else if ((linesOfCode.get(i)[j] == '/'
                      && linesOfCode.get(i)[j + 1] == '*'))
                commentNum++;
        }
    }
}

void FileFormat::setLongestLine(Vector<String> linesOfCode)
{
    for (int i = 0; i < linesOfCode.size(); i++)
    {
        for (int j = 0; j < linesOfCode.get(i).size(); j++)
        {
            if (linesOfCode.get(i)[j] == ';' && longestLine < j)
                longestLine = j;
        }
    }
}

void FileFormat::setLineNum(Vector<String> linesOfCode)
{
    lineNum = linesOfCode.size();
}

int FileFormat::getScore()
{
    return score;
}

int FileFormat::getLongestLine()
{
    return longestLine;
}

int FileFormat::getLineNum()
{
    return lineNum;
}

int FileFormat::getCommentNum()
{
    return commentNum;
}

void FileFormat::calcFormatScore()
{
    if (longestLine > 80)
        score = ((lineNum / commentNum) * 100) + (longestLine * 0.3);
    else
        score = ((lineNum / commentNum) * 100) - (longestLine * 0.3);
}
