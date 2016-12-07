#include <iostream>
#include <cstring>
#include <fstream>
#include <dirent.h>

#include "DSString.h"
#include "Vector.h"
#include "LinkedList.h"
#include "Stack.h"
#include "AvlTree.h"
#include "HashTable.h"
#include "FileFormat.h"
#include "Nests.h"
#include "SizeFile.h"

using namespace std;

int main(int argc, char* const argv[])
{
    /*
     * argv[1] = verbosity
     * argv[2] = input file
     * argv[3] = output file
     */

    char buffer[251];
    ifstream inputFile;
    ofstream outputFile;
    FileFormat formatMetric = FileFormat();
    Nests nestMetric = Nests();
    SizeFile sizeMetric = SizeFile();

    inputFile.open(argv[2], ios::in);

    if (inputFile.is_open())
    {
        // Create the Vector of lines of code
        Vector<String> codeLines = Vector<String>();

        // Fill the Vector with lines of code
        while (!inputFile.eof())
        {
            inputFile >> buffer;
            inputFile.ignore();
            codeLines.add(buffer);
        }

        formatMetric.setLineNum(codeLines);
        formatMetric.setLongestLine(codeLines);
        formatMetric.countComments(codeLines);
        formatMetric.calcFormatScore();

        nestMetric.findDeepestLevel(codeLines);
        nestMetric.findNestNum(codeLines);
        nestMetric.calcNestScore();

        sizeMetric.setFileLength(codeLines);
        sizeMetric.calculateScore();

        inputFile.close();
    }

    outputFile.open(argv[3]);

    if (outputFile.is_open())
    {
        outputFile << "Scores for the " << argv[2] << " file" << endl << endl;
        outputFile << "Formatting score: " << formatMetric.getScore() << endl;
        outputFile << "Nesting score: " << nestMetric.getScore() << endl;
        outputFile << "File size score: " << sizeMetric.getScore() << endl;

        outputFile.close();
    }
}

