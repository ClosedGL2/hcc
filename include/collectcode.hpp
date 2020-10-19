#pragma once
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class CodeCollector
{
    public:
        void setInputFile(string p_inputfile);
        string collect();

    private:
        string inputfile;
        FILE *inputhcfile;
};