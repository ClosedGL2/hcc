#include <iostream>
#include <string>
#include <vector>

#include "collectcode.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    // exit if no arguments
    if (argc < 2)
    {
        cerr << "Error: No arguments" << endl;
        cerr << "Compilation terminated." << endl;

        return 1;
    }

    // argument variables
    string outputfile = "a.out";
    string includepath = ".";
    string inputfile;

    // process arguments
    for (int i = 1; i < argc; i++)
    {
        string arg = argv[i];
        if (arg == "-o")
        {
            i++;
            outputfile = argv[i];
        } else if (arg == "-I")
        {
            i++;
            includepath = argv[i];
        } else
            inputfile = argv[i];
    }

    // collect code to compile
    CodeCollector codecollector;
    string collectedcode;

    codecollector.setInputFile(inputfile);
    collectedcode = codecollector.collect();

    // print code
    cout << collectedcode;

    return 0;
}