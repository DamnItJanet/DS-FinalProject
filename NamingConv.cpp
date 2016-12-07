#include "NamingConv.h"

NamingConv::NamingConv():longestName(0), shortestName(0), score(0) {}

NamingConv::~NamingConv() {}

void NamingConv::setLongestName(Vector<String> linesOfCode)
{
    for (int i = 0; i < linesOfCode.size(); i++)
    {
        for (int j = 0; j < linesOfCode.get(i).size(); j++)
        {

        }
    }
}

void NamingConv::setShortestName(Vector<String> linesOfCode)
{
    for (int i = 0; i < linesOfCode.size(); i++)
    {
        for (int j = 0; j < linesOfCode.get(i).size(); j++)
        {

        }
    }
}

int NamingConv::getScore()
{
    return score;
}

int NamingConv::getShortestName()
{
    return shortestName;
}

int NamingConv::getLongestName()
{
    return longestName;
}

void NamingConv::calcNestScore()
{
    score = 0;
}
