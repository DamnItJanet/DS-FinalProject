#include "SizeFile.h"

SizeFile::SizeFile():score(0), fileLength(0) {}

SizeFile::~SizeFile() {}

void SizeFile::setFileLength(Vector<String> linesOfCode)
{
    fileLength = linesOfCode.size();
}

int SizeFile::getScore()
{
    return score;
}

int SizeFile::getFileLength()
{
    return fileLength;
}

void SizeFile::calculateScore()
{
    score = fileLength / 2;
}
