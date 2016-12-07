#include "Nests.h"

Nests::Nests():score(0), nestNum(0), deepestNestLevel(0) {}

Nests::~Nests() {}

void Nests::findDeepestLevel(Vector<String> linesOfCode)
{
    for (int i = 0; i < linesOfCode.size(); i++)
    {
        for (int j = 0; j < linesOfCode.get(i).size(); j++)
            if (linesOfCode.get(i)[j] == '{')
            {
                nestLevel.push('{');
                if (deepestNestLevel < nestLevel.getDepth())
                    deepestNestLevel = nestLevel.getDepth();
            }
            else if (linesOfCode.get(i)[j] == '}')
                nestLevel.pop();
    }
}

void Nests::findNestNum(Vector<String> linesOfCode)
{
    for (int i = 0; i < linesOfCode.size(); i++)
    {
        for (int j = 0; j < linesOfCode.get(i).size(); j++)
            if (linesOfCode.get(i)[j] == '{')
                nestNum++;
    }
}

int Nests::getScore()
{
    return score;
}

int Nests::getDeepestLevel()
{
    return deepestNestLevel;
}

void Nests::calcNestScore()
{
    score = (deepestNestLevel / nestNum) * 500;
}
